#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

struct User {
	string login;
	string pass;
	int permission;
};

struct Data {
	string name;
	int id;
};

struct Node {
	Data info;
	bool del;
};

template<typename T>
void write_pod(std::ofstream& out, T& t)
{
	out.write(reinterpret_cast<char*>(&t), sizeof(T));
}

template<typename T>
void read_pod(std::ifstream& in, T& t)
{
	in.read(reinterpret_cast<char*>(&t), sizeof(T));
}

template<typename T>
void read_pod_vector(std::ifstream& in, std::vector<T>& vect)
{
	long size;

	// Считываем размер структуры
	read_pod(in, size);
	vect.resize(size);

	for (int i = 0; i < size; ++i)
	{
		// Заполняем вектор
		T t;
		read_pod(in, t);
		vect.push_back(t);
	}
}

template<typename T>
void write_pod_vector(std::ofstream& out, std::vector<T>& vect)
{
	// Записываем размер
	write_pod<long>(out, vect.size());
	// Записываем данные из вектора (собственно, структуры)
	std::for_each(vect.begin(), vect.end(), std::bind1st(write_pod<T>, out));
}

int main()
{
	std::vector<Node> myStructs;
	std::ofstream out("test.dat");
	std::ifstream in("test.dat");

	// Записываем вектор
	write_pod_vector(out, myStructs);
	out.close();
	// Считываем вектор
	read_pod_vector(in, myStructs);
}
