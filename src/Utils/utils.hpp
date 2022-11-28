#ifndef UTILS_HEADER_HPP_ /* UTILS_HEADER_HPP_ */
#define UTILS_HEADER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::vector;
using std::fstream;
using std::stringstream;
using std::ios;

void remove(string &input, char to_replace);
bool isnum(string line);
vector<string> readlines(string filename);

#endif /* UTILS_HEADER_HPP_ */
