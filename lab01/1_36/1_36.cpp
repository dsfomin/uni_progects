
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int s1, v1, v2, s2, t;

	setlocale(LC_CTYPE, "rus");
	cout << "¬ведите значение s1 в метрах: " << endl;;
	cin >> s1;
	cout << "¬ведите значение v1 в м/с : " << endl;;
	cin >> v1;
	cout << "¬ведите значение v2 в м/с : " << endl;;
	cin >> v2;
	cout << "¬ведите значение t в секундах : " << endl;;
	cin >> t;

	s2 = s1 + (t * (v1 + v2));

	cout << "s2 = " << s2 << " метров(-а)" << endl;
	system("PAUSE");
}