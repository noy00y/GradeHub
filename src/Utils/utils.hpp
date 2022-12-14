#ifndef UTILS_HEADER_H /* UTILS_HEADER_H */
#define UTILS_HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include <iomanip>

using std::string;
using std:: cout;
using std:: endl;
using std::vector;
using std::fstream;
using std::stringstream;
using std::ios;

void remove(string &input, char to_replace);
bool isnum(string line);
vector<string> readlines(string filename);

#endif /* UTILS_HEADER_H */