/*
ќписать процедуру SortInc3(A, B, C), мен€ющую содержимое перемен-
ных A, B, C таким образом, чтобы их значени€ оказались упор€доченными
по возрастанию (A, B, C Ч вещественные параметры, €вл€ющиес€ одно-
временно входными и выходными). — помощью этой процедуры упор€до-
чить по возрастанию два данных набора из трех чисел: (A1, B1, C1) и (A2,
B2, C2).
*/

#include <iostream>

using namespace std;

void SortInc3(int a, int b, int c)
{
	if (a <= b && a <= c && b <= c) cout << a << ", " << b << ", " << c << '\n';
	if (b <= a && b <= c && a <= c) cout << b << ", " << a << ", " << c << '\n';
	if (b <= a && b <= c && c <= a) cout << b << ", " << c << ", " << a << '\n';
	if (c <= a && c <= b && a <= b) cout << c << ", " << a << ", " << b << '\n';
	if (c <= a && c <= b && b <= a) cout << c << ", " << b << ", " << a << '\n';
	if (a <= b && a <= c && c <= b) cout << a << ", " << c << ", " << b << '\n';
}

int main(void)
{
	int a1, b1, c1;
	int a2, b2, c2;

	cout << "a1 = " << endl;
	cin >> a1;
	cout << "b1 = " << endl;
	cin >> b1;
	cout << "c1 = " << endl;
	cin >> c1;
	cout << "a2 = " << endl;
	cin >> a2;
	cout << "b2 = " << endl;
	cin >> b2;
	cout << "c2 = " << endl;
	cin >> c2;

	SortInc3(a1, b1, c1);
	SortInc3(a2, b2, c2);

	system("pause");
	return 0;
}