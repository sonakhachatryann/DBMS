#include <iostream>
#include <fstream>
#include <vector>
#include "prototypes.h"

void update_all(std::string name, std::string surname, std::string age, std::string filename) {
	std::vector<std::string> vec(3);
	vec[0] = name;
	vec[1] = surname;
	vec[2] = age;
	insert_to_the_file(vec, filename, 1);
}