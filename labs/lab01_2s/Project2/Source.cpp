#include <string>
#include <iostream>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

int main()
{
	std::string path = "C:\\UNI\\progects\\labs\\lab01_2s\\Kataloge\\DataBase";
	for (const auto & entry : fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;
	system("pause");
	return 0;
}