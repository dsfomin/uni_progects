// LZW.cpp
/*---------------------------------------------------------
* �������� LZW. ���������������� ���������.
* ������:
*     LZW e|d infile outfile
*---------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned int  uint;

/*---------------------------------------------------------
   ��������� ������ � ������
*/

typedef struct bfile
{
	FILE *file;
	uchar mask;
	int rack;
	int pacifier_counter;
}
BFILE;

#define PACIFIER_COUNT 2047

BFILE *OpenInputBFile(char *name);
BFILE *OpenOutputBFile(char *name);
void  WriteBit(BFILE *bfile, int bit);
void  WriteBits(BFILE *bfile, ulong code, int count);
int   ReadBit(BFILE *bfile);
ulong ReadBits(BFILE *bfile, int bit_count);
void  CloseInputBFile(BFILE *bfile);
void  CloseOutputBFile(BFILE *bfile);

/*---------------------------------------------------------
   ������� �������� ������
*/

void CompressFile(FILE *input, BFILE *output);
void ExpandFile(BFILE *input, FILE *output);
void usage_exit(char *prog_name);
void print_ratios(char *input, char *output);
long file_size(char *name);

/*---------------------------------------------------------
   ������� ������ � ������� ������ ��� ��������� LZW
*/

uint find_dictionary_match(int prefix_code, int character);
uint decode_string(uint offset, uint code);

/*---------------------------------------------------------
   ���������, ������������ ��� ������ LZW
*/
/* ���������� ����� � ���� */
#define BITS                       12
/* ������������ �������� ���� */
#define MAX_CODE                   ( ( 1 << BITS ) - 1 )
/* ������ ������� � ��������� */
#define TABLE_SIZE                 5021
/* ����������� ��� ����� ������ */
#define END_OF_STREAM              256
/* �������� ����, ������� �������� ������ �����������
� ������� ����� */
#define FIRST_CODE                 257
/* ������� ��������� ������ � ������� */
#define UNUSED                     -1

// ��� �����-�����������
const char *compressor_filname = "LZW.exe";

/*-----------------------------------------------------------
   ��������� ��������� ������ ��� ������ ���������.
*/

void fatal_error(const char *str, ...)
{
	printf("Fatal error: %s\n", str);
	exit(1);
}

/*-----------------------------------------------------------
   �������� ����� ��� ��������� ������
*/

BFILE *OpenOutputBFile(char * name)
{
	BFILE *bfile;

	bfile = (BFILE *)calloc(1, sizeof(BFILE));
	bfile->file = fopen(name, "wb");
	bfile->rack = 0;
	bfile->mask = 0x80;
	bfile->pacifier_counter = 0;
	return bfile;
}

/*-----------------------------------------------------------
   �������� ����� ��� ���������� ������
*/

BFILE *OpenInputBFile(char *name)
{
	BFILE *bfile;

	bfile = (BFILE *)calloc(1, sizeof(BFILE));
	bfile->file = fopen(name, "rb");
	bfile->rack = 0;
	bfile->mask = 0x80;
	bfile->pacifier_counter = 0;
	return bfile;
}

/*-----------------------------------------------------------
   �������� ����� ��� ��������� ������
*/

void CloseOutputBFile(BFILE *bfile)
{
	if (bfile->mask != 0x80)
		putc(bfile->rack, bfile->file);
	fclose(bfile->file);
	free((char *)bfile);
}

/*-----------------------------------------------------------
   �������� ����� ��� ���������� ������
*/

void CloseInputBFile(BFILE *bfile)
{
	fclose(bfile->file);
	free((char *)bfile);
}

/*-----------------------------------------------------------
   ����� ������ ����
*/

void WriteBit(BFILE *bfile, int bit)
{
	if (bit)
		bfile->rack |= bfile->mask;
	bfile->mask >>= 1;
	if (bfile->mask == 0)
	{
		putc(bfile->rack, bfile->file);
		if ((bfile->pacifier_counter++ & PACIFIER_COUNT) == 0)
			putc('.', stdout);
		bfile->rack = 0;
		bfile->mask = 0x80;
	}
}

/*-----------------------------------------------------------
   ����� ���������� �����
*/

void WriteBits(BFILE *bfile, ulong code, int count)
{
	ulong mask;

	mask = 1L << (count - 1);
	while (mask != 0)
	{
		if (mask & code)
			bfile->rack |= bfile->mask;
		bfile->mask >>= 1;
		if (bfile->mask == 0)
		{
			putc(bfile->rack, bfile->file);
			if ((bfile->pacifier_counter++ & PACIFIER_COUNT) == 0)
				putc('.', stdout);
			bfile->rack = 0;
			bfile->mask = 0x80;
		}
		mask >>= 1;
	}
}

/*-----------------------------------------------------------
   ���� ������ ����
*/

int ReadBit(BFILE *bfile)
{
	int value;

	if (bfile->mask == 0x80)
	{
		bfile->rack = getc(bfile->file);
		if (bfile->rack == EOF)
			fatal_error("Error in function ReadBit!\n");
		if ((bfile->pacifier_counter++ & PACIFIER_COUNT) == 0)
			putc('.', stdout);
	}

	value = bfile->rack & bfile->mask;
	bfile->mask >>= 1;
	if (bfile->mask == 0)
		bfile->mask = 0x80;
	return (value ? 1 : 0);
}

/*-----------------------------------------------------------
   ���� ���������� �����
*/

ulong ReadBits(BFILE *bfile, int bit_count)
{
	ulong mask;
	ulong return_value;

	mask = 1L << (bit_count - 1);
	return_value = 0;
	while (mask != 0)
	{
		if (bfile->mask == 0x80)
		{
			bfile->rack = getc(bfile->file);
			if (bfile->rack == EOF)
				fatal_error("Error in function ReadBits!\n");
			if ((bfile->pacifier_counter++ & PACIFIER_COUNT) == 0)
				putc('.', stdout);
		}
		if (bfile->rack & bfile->mask)
			return_value |= mask;
		mask >>= 1;
		bfile->mask >>= 1;
		if (bfile->mask == 0)
			bfile->mask = 0x80;
	}

	return return_value;
}

/*-----------------------------------------------------------
   ����� ��������� �� �������������
*/

void usage_exit()
{
	printf("\n Using: %s e|d infile outfile\n", compressor_filname);
	printf("e - for encoding (compression)\n");
	printf("d - for decoding (decompression)\n");
	exit(0);
}

/*-----------------------------------------------------------
   ��������� ������� �����
*/

long file_size(char *name)
{
	long eof_ftell;
	FILE *file;

	file = fopen(name, "r");
	if (file == NULL)
		return(0L);
	fseek(file, 0L, SEEK_END);
	eof_ftell = ftell(file);
	fclose(file);
	return eof_ftell;
}

/*-----------------------------------------------------------
   ����� ��������� � ����������� �������� ������
*/
void print_ratios(char *input, char *output)
{
	long input_size;
	long output_size;
	int ratio;

	input_size = file_size(input);
	if (input_size == 0)
		input_size = 1;
	output_size = file_size(output);
	ratio = 100 - (int)(output_size * 100L / input_size);
	printf("\nInput size:        %ld bytes\n", input_size);
	printf("Output size:       %ld bytes\n", output_size);
	if (output_size == 0)
		output_size = 1;
	printf("Ratio: %d%%\n", ratio);
}

/*-----------------------------------------------------------
   ����� ���������� �������� ����� ���������� ��������� LZW
*/

/* ��������� ������� ��� ��������� LZW */

struct dictionary
{
	int code_value;
	int prefix_code;
	char character;
}
dict[TABLE_SIZE];

/* ���� ��� ������������� */

char decode_stack[TABLE_SIZE];

/*-----------------------------------------------------------
   ��������� ������ �����
*/

void CompressFile(FILE *input, BFILE *output)
{
	int next_code, character, string_code;
	uint index, i;

	/* ������������� */
	next_code = FIRST_CODE;
	for (i = 0; i < TABLE_SIZE; i++)
		dict[i].code_value = UNUSED;
	/* ������� ������ ������ */
	if ((string_code = getc(input)) == EOF)
		string_code = END_OF_STREAM;
	/* ���� �� ����� ��������� */
	while ((character = getc(input)) != EOF)
	{
		/* ������� ����� � ������� ���� <�����, ������> */
		index = find_dictionary_match(string_code, character);
		/* ������������ ������� */
		if (dict[index].code_value != -1)
			string_code = dict[index].code_value;
		/* ����� ���� � ������� ��� */
		else
		{
			/* ���������� � ������� */
			if (next_code <= MAX_CODE)
			{
				dict[index].code_value = next_code++;
				dict[index].prefix_code = string_code;
				dict[index].character = (char)character;
			}
			/* ������ ���� */
			WriteBits(output, (ulong)string_code, BITS);
			string_code = character;
		}
	}
	/* ���������� ����������� */
	WriteBits(output, (ulong)string_code, BITS);
	WriteBits(output, (ulong)END_OF_STREAM, BITS);
}

/*-----------------------------------------------------------
   ��������� ������������� ������� �����
*/

void ExpandFile(BFILE *input, FILE *output)
{
	uint next_code, new_code, old_code;
	int character;
	uint count;

	next_code = FIRST_CODE;
	old_code = (uint)ReadBits(input, BITS);
	if (old_code == END_OF_STREAM)
		return;
	character = old_code;

	putc(old_code, output);

	while ((new_code = (uint)ReadBits(input, BITS))
		!= END_OF_STREAM)
	{
		/* ��������� ��������� �������������� �������� */
		if (new_code >= next_code)
		{
			decode_stack[0] = (char)character;
			count = decode_string(1, old_code);
		}
		else
			count = decode_string(0, new_code);

		character = decode_stack[count - 1];
		/* ������ ��������������� ������ */
		while (count > 0)
			putc(decode_stack[--count], output);
		/* ���������� ������� */
		if (next_code <= MAX_CODE)
		{
			dict[next_code].prefix_code = old_code;
			dict[next_code].character = (char)character;
			next_code++;
		}
		old_code = new_code;
	}
}

/*-----------------------------------------------------------
   ��������� ������ � ������� ��������� ���� <��� �����,
   ������>. ��� ��������� ������ ������������ ���, ����������
   �� ����������.
*/

uint find_dictionary_match(int prefix_code, int character)
{
	int index;
	int offset;

	/* ���������� ��������� �������� ���-������� */
	index = (character << (BITS - 8)) ^ prefix_code;
	/* ���������� ��������� �������� */
	if (index == 0)
		offset = 1;
	else
		offset = TABLE_SIZE - index;
	for (; ; )
	{
		/* ��� ������ ������� �� ������������ */
		if (dict[index].code_value == UNUSED)
			return index;
		/* ������� ������������ */
		if (dict[index].prefix_code == prefix_code &&
			dict[index].character == (char)character)
			return index;
		/* ��������. ���������� � ��������� ������� ��
		   ���������� */
		index -= offset;
		if (index < 0)
			index += TABLE_SIZE;
	}
}

/*-----------------------------------------------------------
   ��������� ������������� ������. ��������� ������� � �����,
   ���������� �� ����������.
*/

uint decode_string(uint count, uint code)
{
	while (code > 255) /* ���� �� ���������� ��� ������� */
	{
		decode_stack[count++] = dict[code].character;
		code = dict[code].prefix_code;
	}
	decode_stack[count++] = (char)code;
	return count;
}


//------------------------------------------------------------
// ������� ���������
int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);

	// � ������ ������������� ���������� ����������
	// ��������� ������ ������������� ���������
	if (argc < 4)
		usage_exit();

	// ����������:
	if (argv[1][0] == 'e' || argv[1][0] == 'E')
	{
		BFILE *output;
		FILE *input;

		// �������� �������� ����� ��� ������
		input = fopen(argv[2], "rb");
		if (input == NULL)
			fatal_error("������ ��� �������� %s ��� �����\n", argv[2]);

		// �������� ��������� ����� ��� ������
		output = OpenOutputBFile(argv[3]);
		if (output == NULL)
			fatal_error("������ ��� �������� %s ��� ������\n", argv[3]);
		printf("\n���������� %s � %s\n", argv[2], argv[3]);

		// ����� ��������� ����������
		CompressFile(input, output);

		// �������� ������
		CloseOutputBFile(output);
		fclose(input);

		printf("\nCompression complete.");

		// ����� ������������ ������
		print_ratios(argv[2], argv[3]);
	}
	// ������������:
	else if (argv[1][0] == 'd' || argv[1][0] == 'D')
	{
		BFILE *input;
		FILE *output;

		// �������� �������� ����� ��� ������
		input = OpenInputBFile(argv[2]);
		if (input == NULL)
			fatal_error("Error on open %s for read\n", argv[2]);

		// �������� ��������� ����� ��� ������
		output = fopen(argv[3], "wb");
		if (output == NULL)
			fatal_error("Error on open %s for write\n", argv[3]);

		printf("\nDecompression %s into %s\n", argv[2], argv[3]);

		// ����� ��������� ������������
		ExpandFile(input, output);

		// �������� ������
		CloseInputBFile(input);
		fclose(output);

		printf("\nDecompression complete.");
	};

	system("pause");
	return 0;

}