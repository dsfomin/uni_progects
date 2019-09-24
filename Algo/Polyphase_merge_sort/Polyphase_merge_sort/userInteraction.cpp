#include <iostream>
#include "userInteraction.h"

long ramMem() {
	static long ans = 0;
	if (!(ans)) {
		while (ans <= 0) {
			std::cout << "Enter how many RAM in bytes do you have available -> ";
			std::cin >> ans;
		}
	}
	return ans;
}

void info() {
	std::cout << "This function does an external sorting of the file \"input.txt\"" << std::endl;
	return;
}
