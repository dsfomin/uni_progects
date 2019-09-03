#include <iostream>
#include <cstring>
#include <string>

using namespace std;


#define MAX_LEN 256


void push(char *_stack, int &_ptr, char data);
char pop(char *_stack, int &_ptr);
void push_int(int *_stack, int &_ptr, int data);
int pop_int(int *_stack, int &_ptr);

//
//	Преобразование записи математ. выражения из инфиксной в постфиксную (в обратную польскую запись)
//
//	Сразу оговоримся, допустимые операторы: +,-,*,/,(,),^; все операции будем считать лево-ассоциативными
//	Все операнды - односимвольные
//
void PostfixNotation(const char *_infix, char *_postfix)
{
	char stack[MAX_LEN];	// стек для хранения операторов при преобразовании
	int st_ptr = 0;				// указатель вершины стека

	int out_index = 0;		// индекс в выходной строке
	int in_index = 0;		// индекс во входной строке

	// начинаем разбор входящей строки (она не должна быть пустой)
	do
	{
		char c = _infix[in_index];	// берем текущий символ входной строки

		switch (c)
		{
			case '+':
			case '-':
				// выталкиваем из стека в выходную строку все операторы с большим или равным приоритетом
				while (st_ptr != 0)
				{
					char op = stack[st_ptr-1];	// оператор в вершине стека
					if (op != '(')	// все операторы, кроме откр. скобки имеют больший или равный приоритет
					{
						_postfix[out_index++] = op;	// добавляем оператор в выходную строку
						pop(stack, st_ptr);			// удаляем оператор из стека
					}
					else
						break;
				}
				// помещаем оператор в стек
				push(stack, st_ptr, c);
				break;

			case '*':
			case '/':
				// выталкиваем из стека в выходную строку все операторы с большим или равным приоритетом
				while (st_ptr != 0)
				{
					char op = stack[st_ptr-1];
					if ((op == '^') || (op == '*') || (op == '/'))
					{
						_postfix[out_index++] = op;	// добавляем оператор в выходную строку
						pop(stack, st_ptr);			// удаляем оператор из стека
					}
					else
						break;
				}
				// помещаем оператор в стек
				push(stack, st_ptr, c);
				break;

			case '(':
				// просто помещаем в стек
				push(stack, st_ptr, c);
				break;

			case ')':
				// выталкиваем из стека в выходную строку все элементы до открывающей скобки (откр. скобку просто отбрасываем)
				while (st_ptr != 0)
				{
					char op = pop(stack, st_ptr);	// забираем из стека оператор
					if (op == '(')					// если достигли открывающей скобки
						break;						// выталкивание закончили
					else
					{
						_postfix[out_index++] = op;	// добавили оператор в выходную строку
					}
				}
				break;

			case '^':
				// помещаем оператор в стек (выталкивать ничего не нужно, нет операторов с большим приоритетом)
				push(stack, st_ptr, c);
				break;

			case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9:		// символ цифры
				_postfix[out_index] = c;	// добавляем цифру в выходную строку
				out_index++;
				break;
			default:
				cout << "Error - Unknown operation " << c << endl;
				system("pause");
				exit(EXIT_FAILURE);
		}

		in_index++;	// переходим к следующему символу входной строки
	}
	while (_infix[in_index] != 0);	// разбор закончен

	// выталкиваем все операторы в выходную строку
	while(st_ptr != 0)
		_postfix[out_index++] = pop(stack, st_ptr);

	// завершающий символ нуля
	_postfix[out_index] = 0;
}

int pow_int(int a, int b)
{
	int res = a;
	while (b >= 2)
	{
		res = res * a;
		b--;
	}
	return res;
}

int calculation(const char* postfix)
{
	int stack[MAX_LEN];	// стек для хранения операндов
	int st_ptr = 0;		// указатель вершины стека

	int temp;
	int in_index = 0;

	int op_a, op_b;

	do
	{
		char c = postfix[in_index];
		if ((c >= '0') && (c <= '9'))
		{
			temp = c - '0';
		}
		else
		{
			op_b = pop_int(stack, st_ptr);
			op_a = pop_int(stack, st_ptr);

			switch (c)
			{
			case '+':
				temp = op_a + op_b;
				break;
			case '-':
				temp = op_a - op_b;
				break;
			case '*':
				temp = op_a * op_b;
				break;
			case '/':
				temp = op_a / op_b;
				break;
			case '^':
				temp = pow_int(op_a, op_b);
				break;
			default:
				cout << "Unknown operation " << c << endl;
				exit(EXIT_FAILURE);
			}
		}
		push_int(stack, st_ptr, temp);
		in_index++;
	} while (postfix[in_index] != 0);

	return pop_int(stack, st_ptr);
}

void push_int(int *_stack, int &_ptr, int data)
{
	_stack[_ptr++] = data;
}

int pop_int(int *_stack, int &_ptr)
{
	return _stack[--_ptr];
}

void push(char *_stack, int &_ptr, char data)
{
	_stack[_ptr++] = data;
}

char pop(char *_stack, int &_ptr)
{
	return _stack[--_ptr];
}

int error(const char *s)
{
	int i = 0, c1 = 0, c2 = 0, pos = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == '(')
			c1++;
		if (s[i] == ')')
		{
			c2++;
			pos = i;
		}
	}
	if (c1 == c2)
		return 0;
	else if (c1 > c2)
		return -1;
	else if (c2 > c1)
		return pos;
}

int main()
{
	char str_infix[100];
	char str_postfix[MAX_LEN];

	cin.getline(str_infix, 100);
	if (error(str_infix) != 0)
	{
		cout << "Error" << endl;
		system("pause");
		return 0;
	}
	cout << str_infix << endl;

	PostfixNotation(str_infix, str_postfix);
	cout << str_postfix << endl;

	cout << calculation(str_postfix) << endl;

	system("pause");
	return 0;
}