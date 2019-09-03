#include <string>
#include <iostream>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

int main()
{
	std::string path = "/path/to/directory";
	for (const auto & entry : fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;
}

//#include <iostream>
//#include <fstream>
//
//using namespace std;
//
//int main() {
//
//	fstream file;
//	file.open("1.txt");
//
//	int ch = 0;
//
//	if (file) {
//		file >> ch;
//		ch++;
//	}
//
//	file.close();
//
//	file.open("1.txt");
//
//	if (file)
//		file << ch;
//
//	file.close();
//
//	cout << "ch = " << ch << endl;
//
//	system("pause");
//	return 0;
//}

//ifstream input("input.txt");
//ofstream output("output.txt");
//string text;
//if (input)
//while (getline(input, text))
//output << text << endl;