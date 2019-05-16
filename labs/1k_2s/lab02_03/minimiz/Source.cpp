#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
#define R 4
#define SR 16

string S[SR * 2];
string Rez[SR * 2];
int Flag[SR * 2] = { 0 };
int Y[SR];
int IndexS;
int IndexRez;
FILE *FData = NULL, *FRez = NULL;
/*Функция формирования дизъюнкта*/
string MakeDiz(int Number)
{
	string res;
	for (int i = 0; i < R; i++) {
		res.insert(res.begin(), ((Number >> i) & 0x01) + 48);
	}
	return res;
}
/*Функция склеивания*/
void Splice(const string &S1, const string &S2, int IndexS1, int IndexS2)
{
	int k = 0, n; /*кол-во разных*/
	for (int i = 0; i < R; i++)
		if (S1[i] != S2[i]) {
			k++; n = i;
		}
	switch (k) {
	case 0:
		Rez[IndexRez] = S1;
		Flag[IndexS1] = Flag[IndexS2] = 1;
		IndexRez++;
		break;
	case 1:
		if ((S1[n] != '*') && (S2[n] != '*')) {
			Rez[IndexRez] = S1;
			Rez[IndexRez][n] = '*';
			Flag[IndexS1] = Flag[IndexS2] = 1;
			IndexRez++;
		}
		break;
	}
}
/*Функция проверки на удаление пустого дизъюнкта*/
bool Del(string &S)
{
	bool del = false;
	int k = 0;
	for (int i = 0; i < R; i++) if (S[i] == '*') k++;
	if (k == R) del = true;
	return del;
}

void Clear()
{
	IndexS = 0;
	for (int i = 0; i < SR * 2; i++) {
		Flag[i] = 0;
		S[i] = "";
	}
	for (int i = 0; i < IndexRez - 1; i++) if (Flag[i] == 0)
		for (int j = i + 1; j < IndexRez; j++)
			if (Rez[i] == Rez[j]) Flag[j] = 1;
	for (int i = 0; i < IndexRez; i++)
		if (Flag[i] == 0) {
			S[IndexS] = Rez[i];
			IndexS++;
		}
}
/*Вывод на экран массива Rez*/
void PrintRez(int Step)
{
	cout << "{------------------------------------------------}\n";
	fprintf_s(FRez, "{------------------------------------------------}\n");
	if (Step == 0) {
		cout << "Исходная ДНФ.";
		fprintf_s(FRez, "Исходная ДНФ.");
	}
	else {
		cout << "Шаг номер :" << Step << ".";
		fprintf_s(FRez, "Шаг номер :%d.", Step);
	}
	cout << " Количество дизьюнктов :" << IndexS << endl;
	fprintf_s(FRez, " Количество дизьюнктов :%d\n", IndexS);
	for (int i = 0; i < IndexS; i++) {
		cout << S[i] << endl;
		fprintf_s(FRez, "%s\n", S[i].c_str());
	}
	_getch();
}

int main(void)
{
	setlocale(0, "");
	fopen_s(&FRez, "result.txt", "w");
	fopen_s(&FData, "func.txt", "r");
	/*Считать массив Y из файла*/
	for (int i = 0; i < SR; i++) fscanf_s(FData, "%c ", &Y[i]);
	fclose(FData);
	/*Получить массив S*/
	for (int i = 0; i < SR; i++) S[i] = MakeDiz(i);
	/*Преоразовать S: оставив только те элементы, для которых Y=1. Результата в Rez*/
	IndexRez = 0;
	for (int i = 0; i < SR; i++)
		if (Y[i] == '1') {
			Rez[IndexRez] = S[i];
			IndexRez++;
		}
	for (int i = 0; i < SR * 2; i++) S[i] = Rez[i];
	IndexS = IndexRez;
	PrintRez(0);
	/*склеивание*/
	for (int i = 0; i < R; i++) {
		/*подготовка массива Flag под склеивание*/
		IndexRez = 0;
		for (int j = 0; j < SR * 2; j++) {
			Flag[j] = 0;
			Rez[j] = "";
		}
		/*склеивание*/
		for (int j = 0; j < IndexS - 1; j++)
			for (int k = j + 1; k < IndexS; k++)
				Splice(S[j], S[k], j, k);
		/*копирование несклеившихся компонент*/
		for (int j = 0; j < IndexS; j++)
			if (Flag[j] == 0) {
				Rez[IndexRez] = S[j];
				IndexRez++;
			}
		Clear();/*удаление одинаковых дизъюнктов*/
		PrintRez(i + 1);/*вывод результата на экран*/
	}
	IndexRez = 0;
	/*Удалить все дизъюнкты вида **...* */
	for (int i = 0; i < IndexS; i++)
		if (!Del(S[i])) {
			Rez[IndexRez] = S[i];
			IndexRez++;
		}
	PrintRez(R + 1);
	for (int i = 0; i < IndexS; i++) {
		cout << '(';
		for (int j = 0; j < R; j++) if (S[i][j] != '*') cout << (S[i][j] == '0' ? "-" : "") << 'X' << j + 1;
		cout << ')';
		if (i != (IndexS - 1)) cout << " V ";
	}
	cout << endl;
	_fcloseall();
	return 0;
}