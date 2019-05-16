//#include "stdafx.h"
#include <iostream>
#include<Windows.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
using namespace std;

typedef struct Node
{
	int index;
	int value;
	struct Node* next;
} Node;

Node* inithead(int index, int value) //инициализация головы
{
	Node *el = (Node*)malloc(sizeof(Node));
	el->value = value;
	el->index = index;
	el->next = NULL;
	return el;
}

int addel(Node* head, int index, int value) //добавление елемента 
{
	if (!head)
	{
		cout << "NULL pointer head" << endl;
		return -1;
	}
	while (head->next)
		head = head->next;

	head->next = (Node*)malloc(sizeof(Node));
	head = head->next;
	head->value = value;
	head->index = index;
	head->next = NULL;

	return 0;
}

Node* findel(Node*head, int _index) //поиск елемента
{
	if (!head)
	{
		cout << "NULL-pointer head!" << endl;
		return NULL;
	}
	if (_index < 0) cout << "The index must be > 0. Or = 0." << endl;
	int index = 0;
	while (head->next && _index != index)
	{
		index++;
		head = head->next;
	}

	if (_index != index) return NULL;
	return head;
}

void Write(Node*mas, int n, int n2);
void WriteTable(Node*mas, int n, int n2);
int y(Node*mas, int n, int n2, int x[10]);
void Add(int x[10], int n);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Node* mas = inithead(-1, 0);
	int n, n2;

	int b, a[256];
	Node*node;
	//Node *node = (Node*)malloc(sizeof(Node));
	//node->value = a[256];
	//node->index = b;
	//node->next = NULL;
	//a = node->value;
	//b = node->index;
	//z = addel(mas, a[256],  b);
	cout << "Enter quantity of elements: ";
	cin >> n2;
	cout << "Enter quantity of x: ";
	cin >> n;
	if ((n <= 0) || (n2 <= 0))
	{
		cout << "ERROR! QUANTITY MUST BE > 0" << endl;
		return 0;
	}
	if (n > n2)
	{
		cout << "ERROR! QUANTITY OF X CAN'T BE > QUANTITY OF ELEMENTS" << endl;
		return 0;
	}
	for (int i = 0; i < n2; i++)
	{
		cout << "enter index of (): ";
		cin >> a[i];
		if (a[0] != 0 || a[0] < 0)
		{
			cout << "ERROR! FIRST MUST BE 0" << endl;
			return 0;
		}
		if (a[i] < 0)
		{
			cout << "ERROR! INDEX OF () CAN'T BE < 0" << endl;
			return 0;
		}

		cout << "enter index of element: ";
		cin >> b;
		if (b == 0)
		{
			cout << "ERROR! INDEX OF X CAN'T BE 0" << endl;
			return 0;
		}
		if (abs(b) > n)
		{
			cout << "ERROR! INDEX OF X CAN'T BE BIGGER THAN X QUANTITY" << endl;
			return 0;
		}

		addel(mas, a[i], b);
	}
	Write(mas, n, n2);
	cout << endl;
	WriteTable(mas, n, n2);
	_getch();
	return 0;
}

void Write(Node*mas, int n, int n2)
{
	cout << "y= ";
	int k = 1;
	int i = 0;
	int j = 0;
	Node*node;
	do
	{
		node = findel(mas, k);
		if (node != NULL)
		{
			if (node->index == i)
			{
				if ((j > 0) && (j < n))cout << "\\/";
			}
			else
			{
				j = 0;
				i++;
				cout << ")";
				if (i <= n2)cout << "/\\";

			}
			if (j == 0) cout << "(";
			if (node->value < 0)cout << "-";
			cout << "x" << abs(node->value);
			j++;

			k++;
		}
	} while (node != NULL);
	cout << ")";
}
void WriteTable(Node*mas, int n, int n2)
{
	cout << "y  ";
	for (int j = 0; j < n; j++)
		cout << "x" << j + 1 << " ";
	cout << endl;

	int x[10];
	for (int j = 0; j < n; j++)
		x[j] = 0;

	for (int i = 0; i < pow(2, n); i++)
	{
		cout << y(mas, n, n2, x) << "  ";
		for (int j = 0; j < n; j++)
			cout << x[j] << "  ";

		cout << endl;
		Add(x, n);
	}
}
int y(Node*mas, int n, int n2, int x[10])
{
	int f2 = 0;
	int k = 1;
	int i = 0;
	int f = 0;
	Node*node;
	int x2[10];

	for (int j = 0; j < n; j++)
		x2[j] = 0;

	do
	{
		int a = x[0];
		int b = x[1];
		node = findel(mas, k);
		if (node != NULL)
		{
			if (((node->value > 0) && (x[abs(node->value) - 1] == 1)) || ((node->value < 0) && (x[abs(node->value) - 1] == 0)))
				x2[node->index]++;
			k++;
		}
	} while (node != NULL);

	for (int j = 0; j < n; j++)
		if (x2[j] == 0) return 0;

	return 1;
}
void Add(int x[10], int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (x[i] == 0)
		{
			x[i] = 1;
			break;
		}
		else x[i] = 0;
	}
}