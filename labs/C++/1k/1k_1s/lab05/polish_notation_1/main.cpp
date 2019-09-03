#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double number();
double factor();
double expr();
double brackets();
double power();

int main()
{
	double n;

	setlocale(LC_ALL, "Rus");

	cout << "Введите выражение: ";

	n = expr();

	cout << "Результат вычисления: " << setprecision(10) << n << endl;

	cin.get();
	system("pause");
	return 0;
}

double number()
{
	double result = 0;
	double k = 10;
	int sign = 1;
	char c;

	c = cin.get();

	while (c == ' ')
		c = cin.get();

	if (c == '-')
		sign = -1;
	else
	{
		if (c != '+')
			cin.putback(c);
	}

	while (true)
	{
		c = cin.get();

		while (c == ' ')
			c = cin.get();

		if (c >= '0' && c <= '9')
			result = result * 10.0 + (c - '0');
		else
		{
			cin.putback(c);
			break;
		}
	}

	c = cin.get();

	if (c == '.')
	{
		while (true)
		{
			c = cin.get();

			if (c >= '0' && c <= '9')
			{
				result += (c - '0') / k;
				k *= 10.0;
			}
			else
			{
				cin.putback(c);
				break;
			}
		}
	}
	else
		cin.putback(c);

	return sign * result;
}

double factor()
{
	double result;
	double temp;
	char op;

	result = power();

	while (true)
	{
		op = cin.get();

		while (op == ' ')
			op = cin.get();

		switch (op)
		{
		case '*':
			result *= power();
			break;
		case '/':
			temp = power();

			if (temp == 0.0)
			{
				cout << "Деление на ноль!" << endl;
				system("pause");
				exit(-1);
			}

			result /= temp;
			break;
		default:
			cin.putback(op);
			return result;
		}
	}
}

double expr()
{
	double result;
	char op;

	result = factor();

	while (true)
	{
		op = cin.get();

		while (op == ' ')
			op = cin.get();

		switch (op)
		{
		case '+':
			result += factor();
			break;
		case '-':
			result -= factor();
			break;
		default:
			cin.putback(op);
			return result;
		}
	}
}

double brackets()
{
	double result;
	int sign = 1;
	char op;

	op = cin.get();

	while (op == ' ')
		op = cin.get();

	if (op == '-')
	{
		sign = -1;
		op = cin.get();
	}
	else
	{
		if (op == '+')
			op = cin.get();
	}

	while (op == ' ')
		op = cin.get();

	if (op == '(')
	{
		result = sign * expr();

		op = cin.get();

		if (op != ')')
		{
			cout << "Неверная расстановка скобок!" << endl;
			exit(-1);
		}

		return result;
	}
	else
	{
		cin.putback(op);

		return sign * number();
	}
}

double power()
{
	double result;
	char op;
	vector <double> args;

	args.push_back(brackets());

	while (true)
	{
		op = cin.get();

		while (op == ' ')
			op = cin.get();

		if (op == '^')
			args.push_back(brackets());
		else
		{
			cin.putback(op);
			break;
		}
	}

	for (int i = args.size() - 1; i > 0; i--)
		args[i - 1] = pow(args[i - 1], args[i]);

	return args[0];
}