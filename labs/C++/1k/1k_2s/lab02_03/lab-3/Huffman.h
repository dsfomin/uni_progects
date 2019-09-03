#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

short           father[512];
unsigned short  code[256], heap_length;
unsigned long   compress_charcount, file_size, heap[257];
unsigned char   code_length[256];
long            frequency_count[512]; // встречаемость символов
short           decomp_tree[512]; // дерево декодирования

FILE            *ifile, *ofile; // входной и выходной файлы

//=========================================================
/* ФУНКЦИИ ДЛЯ КОМПРЕССИИ */

//---------------------------------------------------------
// реорганизация структкры heap
void reheap(unsigned short heap_entry)
{
	register unsigned short  index;
	register unsigned short  flag = 1;

	unsigned long   heap_value;

	heap_value = heap[heap_entry];

	while ((heap_entry <= (heap_length >> 1)) && (flag))
	{
		index = heap_entry << 1;

		if (index < heap_length)
			if (frequency_count[heap[index]] >=
				frequency_count[heap[index + 1]])
				index++;

		if (frequency_count[heap_value]
			< frequency_count[heap[index]])
			flag--;
		else
		{
			heap[heap_entry] = heap[index];
			heap_entry = index;
		}
	}

	heap[heap_entry] = heap_value;
}
//---------------------------------------------------------
// Сжатие данных
void compress_image()
{
	register unsigned int    thebyte = 0;
	register short           loop1;
	register unsigned short  current_code;
	register unsigned long   loop;

	unsigned short  current_length, dvalue;
	unsigned long   curbyte = 0;
	short           curbit = 7;


	for (loop = 0L; loop < file_size; loop++)
	{
		dvalue = (unsigned short)getc(ifile);
		current_code = code[dvalue];
		current_length = (unsigned short)code_length[dvalue];

		for (loop1 = current_length - 1; loop1 >= 0; --loop1)
		{
			if ((current_code >> loop1) & 1)
				thebyte |= (char)(1 << curbit);

			if (--curbit < 0)
			{
				putc(thebyte, ofile);
				thebyte = 0;
				curbyte++;
				curbit = 7;
			}
		}
	}
	putc(thebyte, ofile);
	compress_charcount = ++curbyte;
}
//---------------------------------------------------------
// Генерация таблицы кодирования
unsigned short  generate_code_table()
{
	register unsigned short  loop;
	register unsigned short  current_length;
	register unsigned short  current_bit;

	unsigned short  bitcode;
	short           parent;

	for (loop = 0; loop < 256; loop++)
		if (frequency_count[loop])
		{
			current_length = bitcode = 0;
			current_bit = 1;
			parent = father[loop];

			while (parent)
			{
				if (parent < 0)
				{
					bitcode += current_bit;
					parent = -parent;
				}
				parent = father[parent];
				current_bit <<= 1;
				current_length++;
			}

			code[loop] = bitcode;

			if (current_length > 16)
				return (0);
			else
				code_length[loop] = (unsigned char)current_length;
		}
		else
			code[loop] = code_length[loop] = 0;

	return (1);
}
//---------------------------------------------------------
// Построение дерева кодирования
void build_code_tree()
{
	register unsigned short  findex;
	register unsigned long   heap_value;


	while (heap_length != 1)
	{
		heap_value = heap[1];
		heap[1] = heap[heap_length--];

		reheap(1);
		findex = heap_length + 255;

		frequency_count[findex] = frequency_count[heap[1]] +
			frequency_count[heap_value];
		father[heap_value] = findex;
		father[heap[1]] = -findex;
		heap[1] = findex;

		reheap(1);
	}

	father[256] = 0;
}
//---------------------------------------------------------
// построение heap'а по частотам встречаемости при инициализации
void build_initial_heap()
{
	register unsigned short  loop;
	heap_length = 0;

	for (loop = 0; loop < 256; loop++)
		if (frequency_count[loop])
			heap[++heap_length] = (unsigned long)loop;

	for (loop = heap_length; loop > 0; loop--)
		reheap(loop);
}
//---------------------------------------------------------
// подсчет количества встречаемости каждого символа
void get_frequency_count()
{
	register unsigned long  loop;

	for (loop = 0; loop < file_size; loop++)
		frequency_count[getc(ifile)]++;
}
//=========================================================
/* ФУНКЦИИ ДЛЯ КОМПРЕССИИ */

//---------------------------------------------------------
// Построение дерева декомпрессии
void  build_decomp_tree()
{
	register unsigned short  loop1;
	register unsigned short  current_index;

	unsigned short  loop;
	unsigned short  current_node = 1;

	decomp_tree[1] = 1;

	for (loop = 0; loop < 256; loop++)
	{
		if (code_length[loop])
		{
			current_index = 1;
			for (loop1 = code_length[loop] - 1; loop1 > 0; loop1--)
			{
				current_index = (decomp_tree[current_index] << 1) +
					((code[loop] >> loop1) & 1);
				if (!(decomp_tree[current_index]))
					decomp_tree[current_index] = ++current_node;
			}
			decomp_tree[(decomp_tree[current_index] << 1) +
				(code[loop] & 1)] = -loop;
		}
	}
}
//---------------------------------------------------------
// декомпрессия данных
void  decompress_image()
{
	register unsigned short  cindex = 1;
	register char            curchar;
	register short           bitshift;

	unsigned long  charcount = 0L;


	while (charcount < file_size)
	{
		curchar = (char)getc(ifile);

		for (bitshift = 7; bitshift >= 0; --bitshift)
		{
			cindex = (cindex << 1) + ((curchar >> bitshift) & 1);

			if (decomp_tree[cindex] <= 0)
			{
				putc((int)(-decomp_tree[cindex]), ofile);

				if ((++charcount) == file_size)
					bitshift = 0;
				else
					cindex = 1;
			}
			else
				cindex = decomp_tree[cindex];
		}
	}
}
//=========================================================
// компрессия файла
void Encode()
{
	fseek(ifile, 0L, 2);
	file_size = (unsigned long)ftell(ifile);
	fseek(ifile, 0L, 0);
	get_frequency_count();
	build_initial_heap();
	build_code_tree();
	if (!generate_code_table())
		printf("ERROR!  Code value out of range. Cannot compress.\n");
	else
	{
		fwrite(&file_size, sizeof(file_size), 1, ofile);
		fwrite(code, 2, 256, ofile);
		fwrite(code_length, 1, 256, ofile);
		fseek(ifile, 0L, 0);
		compress_image();
	}
}
//=========================================================
// декомпрессия файла
void Decode()
{
	fread(&file_size, sizeof(file_size), 1, ifile);
	fread(code, 2, 256, ifile);
	fread(code_length, 1, 256, ifile);
	build_decomp_tree();
	decompress_image();
	fclose(ofile);

}

void split_str(char *str, char **mas) {
	char* tmp = 0;
	for (int i = 0, j = 0; str[i] != '\0'; j++, i++) {
		tmp = 0;
		for (; str[i] != '32'; i++)
			tmp += str[i];
		mas[j] = tmp;
	}
}

//=========================================================
void Setup() {
	char *operation;
	printf("-----------------Huffman----------------- \n\"e(encode) | d(decode) infile outfile\"\n";
	char **mas;
	split_str(operation, mas);

	char *filei, *fileo;
	char ed = static_cast<char>(mas[0][0]);

	strcpy(filei, mas[2].c_str());
	strcpy(fileo, mas[3].c_str());

	if ((fopen_s(&ifile, filei, "rb")) == NULL)
	{
		printf("Error input file.\n");
	}

	// открытие выходного файла
	if ((fopen_s(&ofile, fileo, "wb")) == NULL)
	{
		printf("Error output file.\n");
		fclose(ifile);
	}

	if (tolower(ed) == 'e')
		Encode(); // коппрессия
	else if (tolower(ed) == 'd')
		Decode(); // декомпрессия
	else
		cout << "Incorrect input" << endl;

	fclose(ofile);
	fclose(ifile);
}

#endif