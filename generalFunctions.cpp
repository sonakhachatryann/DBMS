#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "prototypes.h"

std::vector<std::string> split_to_words(std::string input) {
	std::vector<std::string> result;
	unsigned int i{};
	unsigned int j{};
	result.push_back("");
	while (i < input.size()) {
		while (input[i] != ' ' && input[i] != ',' && input[i] != '\0') {
			result[j].push_back(input[i]);
			++i;
			if (input[i] == ' ' || input[i] == ',') {
				++j;
				result.push_back("");
				break;
			}
		}
		if (input[i] == '\0') {
			return result;
		}
		++i;
	}
	return result;
}

int get_count_of_lines(std::string filename) {
	std::string line;
	int count{};
	std::ifstream mFile(filename);
	if (mFile.is_open()) {
		while (mFile.peek() != EOF) {
			getline(mFile, line);
			count++;
		}
		mFile.close();
		return count;
	}
	std::cout << "Can't open the file!" << std::endl;
	return -1;
}

std::string getline_from_a_file(std::string filename, int line_number) {
	std::string line;
	const int number_of_lines = get_count_of_lines(filename);
	std::ifstream file(filename);
	if (file.is_open()) {
		for (int lineno = 1; lineno <= number_of_lines; lineno++) {
			getline(file, line);
			if (lineno == line_number) {
				file.close();
				return line;
			}
		}
	}
	else std::cout << "Can not open the file";
	return "";
}

bool file_is_empty(std::string filename) {
	std::ifstream fin(filename);
	return fin.peek() == std::ifstream::traits_type::eof();
}

void determine(std::vector<std::string> res) {
	if (res[0] == "insert" && res[1] == "into") {
		std::vector<std::string> attributes(3);
		int current{};
		int i = 3;
		if (res[i] == "name" && res[i + 1] == "=") {
			i += 2;
			if (res[i].front() == '(' && res[i].back() == ')') {
				res[i].pop_back();
				res[i].erase(0, 1);
				attributes[current] = res[i];
			}
			++i;
			++current;
			if (res[i] == "surname" && res[i + 1] == "=") {
				i += 2;
				if (res[i].front() == '(' && res[i].back() == ')') {
					res[i].pop_back();
					res[i].erase(0, 1);
					attributes[current] = res[i];
				}
				++i;
				++current;
				if (res[i] == "age" && res[i + 1] == "=") {
					i += 2;
					if (res[i].front() == '(' && res[i].back() == ')') {
						res[i].pop_back();
						res[i].erase(0, 1);
						attributes[current] = res[i];
					}
				}
			}
			insert_to_the_file(attributes, res[2]);
		}
		else {
			std::cout << "Please enter the data correctly!" << std::endl;
			return;
		}
	}
	else if (res[0] == "select") {
		if (res[1] == "*" && res[2] == "from" && res.size() == 4) {
			select_all_from_the_file(res[3]);
		} 
		else if (res[1] == "name" && res[2] == "surname" && res[3] == "from") {
			select_first_two_attributes(res[4]);
		}
		else if (res[1] == "name" && res[2] == "age" && res[3] == "from") {
			select_first_and_last_attributes(res[4]);
		}
		else if (res[1] == "surname" && res[2] == "age" && res[3] == "from") {
			select_second_and_last_attributes(res[4]);
		}
		else if (res[1] == "name" && res[2] == "from") {
			select_first(res[3]);
		}
		else if (res[1] == "surname" && res[2] == "from") {
			select_second(res[3]);
		}
		else if (res[1] == "age" && res[2] == "from") {
			select_third(res[3]);
		}
		else {
			std::cout << "Please enter the attributes or filename correctly!" << std::endl;
			return;
		}
	}
	else if (res[0] == "update" && res[2] == "set") {
		if (res[3] == "name" && res[6] == "surname" && res[9] == "age" && res[12] == "where") {
			if (res[5].front() == '(' && res[5].back() == ')') {
				res[5].pop_back();
				res[5].erase(0, 1);
			}
			if (res[8].front() == '(' && res[8].back() == ')') {
				res[8].pop_back();
				res[8].erase(0, 1);
			}
			if (res[11].front() == '(' && res[11].back() == ')') {
				res[11].pop_back();
				res[11].erase(0, 1);
			}
			if (res[13] == "name") {
				const int line_numbers = get_count_of_lines(res[1]);
				if (res[15].front() == '(' && res[15].back() == ')') {
					res[15].pop_back();
					res[15].erase(0, 1);
				}
				for (int i = 1; i < line_numbers; ++i) {
					std::string str = getline_from_a_file(res[1], i);
					std::vector<std::string> vec = split_to_words(str);
					if (vec[0] == res[15]) {
						update_all(res[5], res[8], res[11], res[1]);

					}
				}
			}
			if (res[13] == "surname") {
				const int line_numbers = get_count_of_lines(res[1]);
				if (res[15].front() == '(' && res[15].back() == ')') {
					res[15].pop_back();
					res[15].erase(0, 1);
				}
				for (int i = 1; i < line_numbers; ++i) {
					std::string str = getline_from_a_file(res[1], i);
					std::vector<std::string> vec = split_to_words(str);
					if (vec[1] == res[15]) {
						update_all(res[5], res[8], res[11], res[1]);
					}
				}
			}
		}
		else {
			std::cout << "Please enter the attributes or filename correctly!" << std::endl;
			return;
		}
	}
	else if (res[0] == "delete") {
		//TODO
	}
	else {
		std::cout << "Please enter the command correctly!" << std::endl;
		return;
	}
}

unsigned int get_status(std::string filename, unsigned int line_number) {
	return (getline_from_a_file(filename, line_number))[4];
}