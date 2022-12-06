#include <vector>
#include <string>

std::vector<std::string> split_to_words(std::string);
void insert_to_the_file(std::vector<std::string>, std::string, unsigned int = 0);
void select_all_from_the_file(std::string);
void select_first_two_attributes(std::string);
void select_first_and_last_attributes(std::string);
void select_second_and_last_attributes(std::string);
void select_first(std::string);
void select_second(std::string);
void select_third(std::string);
void update_all(std::string, std::string, std::string, std::string);
void determine(std::vector<std::string>);
std::string getline_from_a_file(std::string, int);
int get_count_of_lines(std::string);
bool file_is_empty(std::string);
unsigned int get_status(std::string, unsigned int);