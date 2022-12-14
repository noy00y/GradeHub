#ifndef FILE_HANDLER_H // FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ofstream;
using std::stringstream;
using std::ios;

class FileHandler{
public:
    string filename;
    vector<string>lines;
public:
    FileHandler(string u_filename);
    void readlines();
    void print();
    void set_lines(string linetowrite);
    void clearfile(); // Creates a clear file, or clears existing file
};

#endif
