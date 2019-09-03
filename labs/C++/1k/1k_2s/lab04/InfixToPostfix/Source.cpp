#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int Priority(char c) {
	switch (c) {
	case '+':
	case '-': return 2;
	case '*':
	case '/': return 3;
	case '^': return 4;
	case '(': return 1;
	}
}

List<string> split(const string& s, char delimiter)
{
	List<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

string InfixToPostfix(string input) {
	List<char> opStack;
	List<string> TokenList = split(input, ' ');
	List<string> PostfixList;
	string TopToken;
	string output;

	for (int i = 0; i < TokenList.GetSize(); i++) {
		if (isdigit(TokenList[i][0]) || isalpha(TokenList[i][0]))
			PostfixList.push_back(TokenList[i]);
		else if (TokenList[i][0] == '(')
			opStack.push_back(TokenList[i][0]);
		else if (TokenList[i][0] == ')') {
			TopToken = opStack[opStack.GetSize() - 1];
			opStack.pop_back();
			while (TopToken[0] != '(') {
				PostfixList.push_back(TopToken);
				TopToken = opStack[opStack.GetSize() - 1];
				opStack.pop_back();
			}
		}
		else {
			while (opStack.GetSize() > 0 && (Priority(opStack[opStack.GetSize() - 1]) >= Priority(TokenList[i][0]))) {
				string tmp;
				tmp += opStack[opStack.GetSize() - 1];
				PostfixList.push_back(tmp);
				tmp.clear();
				opStack.pop_back();
			}
			opStack.push_back(TokenList[i][0]);
		}
	}
	while (opStack.GetSize() > 0) {
		string tmp;
		tmp += opStack[opStack.GetSize() - 1];
		PostfixList.push_back(tmp);
		tmp.clear();
		opStack.pop_back();
	}
	for (int i = 0; i < PostfixList.GetSize(); i++) {
		output += PostfixList[i];
		output += ' ';
	}
	return output;
}

int main() {

	string input = "3 + ( ( 5 + 9 ) * 2 )"; /* "A * B + C * D" "( A + B ) * C - ( D - E ) * ( F + G )"*/
	string output = InfixToPostfix(input);
	cout << "Input: " << input << endl;
	cout << "Output: " << output << endl;

	system("pause>nul");
	return 0;
}