#include <iostream>
#include <fstream>
#include <vector>
#include "prototypes.h"

void select_all_from_the_file(std::string filename) {
	const int lines = get_count_of_lines(filename);
	for (int i = 1; i <= lines; ++i) {
		std::vector<std::string> vec = split_to_words(getline_from_a_file(filename, i));
		vec.pop_back();
		for (int j = 0; j < vec.size(); ++j) {
			std::cout << vec[j] << " ";
		}
		std::cout << std::endl;
	}
}

void select_first_two_attributes(std::string filename) {
	const int lines = get_count_of_lines(filename);
	for (int i = 1; i <= lines; ++i) {
		std::vector<std::string> vec = split_to_words(getline_from_a_file(filename, i));
		vec.pop_back();
		vec.pop_back();
		for (int j = 0; j < vec.size(); ++j) {
			std::cout << vec[j] << " ";
		}
		std::cout << std::endl;
	}
}

void select_first_and_last_attributes(std::string filename) {
	const int lines = get_count_of_lines(filename);
	for (int i = 1; i <= lines; ++i) {
		std::vector<std::string> vec = split_to_words(getline_from_a_file(filename, i));
		vec.pop_back();
		vec.erase(vec.begin() + 1);
		for (int j = 0; j < vec.size(); ++j) {
			std::cout << vec[j] << " ";
		}
		std::cout << std::endl;
	}
}

void select_second_and_last_attributes(std::string filename) {
	const int lines = get_count_of_lines(filename);
	for (int i = 1; i <= lines; ++i) {
		std::vector<std::string> vec = split_to_words(getline_from_a_file(filename, i));
		vec.pop_back();
		vec.erase(vec.begin());
		for (int j = 0; j < vec.size(); ++j) {
			std::cout << vec[j] << " ";
		}
		std::cout << std::endl;
	}
}

void select_first(std::string filename) {
	const int lines = get_count_of_lines(filename);
	for (int i = 1; i <= lines; ++i) {
		std::vector<std::string> vec = split_to_words(getline_from_a_file(filename, i));
		std::cout << vec[0];
		std::cout << std::endl;
	}
}

void select_second(std::string filename) {
	const int lines = get_count_of_lines(filename);
	for (int i = 1; i <= lines; ++i) {
		std::vector<std::string> vec = split_to_words(getline_from_a_file(filename, i));
		std::cout << vec[1];
		std::cout << std::endl;
	}
}

void select_third(std::string filename) {
	const int lines = get_count_of_lines(filename);
	for (int i = 1; i <= lines; ++i) {
		std::vector<std::string> vec = split_to_words(getline_from_a_file(filename, i));
		std::cout << vec[2];
		std::cout << std::endl;
	}
}
