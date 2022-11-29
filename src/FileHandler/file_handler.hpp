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
using std::stringstream;
using std::ios;

class FileHandler{
public:
    string filename;
public:
    FileHandler(string u_filename);
    vector<string> readlines();
    void print(vector<string>lines);
};

#endif // FILE_HANDLER_H