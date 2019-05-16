#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class T
{
public:
	T() {
		cout << "T()" << endl; 
	}
	~T() {
		cout << "~T()" << endl; 
	}
};

class A
{
public:
	A() { cout << "A()" << endl; c = NULL; }
	~A() { cout << "~A()" << endl; delete[] c; }
private:
	T t;
	char * c;
};

class B : public A
{
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
};

int main()
{
	B b;
	return 0;
}