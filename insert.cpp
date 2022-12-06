#include <iostream>
#include <fstream>
#include <vector>
#include "prototypes.h"

void insert_to_the_file(std::vector<std::string> data, std::string filename, unsigned int status) {
	int uid{};
	std::ofstream fout;
	fout.open(filename, std::ofstream::app);
	if (!fout.is_open()) {
		std::cout << "Can't open the file!" << std::endl;
	}
	else {
		if (file_is_empty(filename)) {
			uid = 0;
		}
		else {
			int lines_number = get_count_of_lines(filename);
			std::string tmp = getline_from_a_file(filename, lines_number);
			std::vector<std::string> a = split_to_words(tmp);
			uid = stoi(a.rbegin()[1]) + 1;
		}
		for (int i = 0; i < data.size(); ++i) {
			fout << data[i] << " ";
		}
		fout << uid << " " << status << "\n";
		fout.close();
	}
}