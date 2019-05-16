#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

#include "AFuntions.h"

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

int toInt(string s) // stoi
{
	int num = 0;

	if (s[0] != '-')
		for (size_t i = 0; i < s.length(); i++)
			num = num * 10 + (int(s[i]) - 48);
	else {
		for (size_t i = 1; i < s.length(); i++)
		{
			num = num * 10 + (int(s[i]) - 48);
			num = num * -1;
		}
	}
	return num;
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

#endif
