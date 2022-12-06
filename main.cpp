#include <iostream>
#include "prototypes.h"

int main() {
	std::string command;
	getline(std::cin, command);
	std::vector<std::string> splited = split_to_words(command);
	determine(splited);
	
	return 0;
}