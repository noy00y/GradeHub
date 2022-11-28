#ifndef FILE_HANDLER_HPP_ // FILE_HANDLER_HPP_
#define FILE_HANDLER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
using namespace std;

class FileHandler{
public:
    string filename;
public:
    FileHandler();
    // ~FileHandler(); // not sure if a deconstructor is needed here
    vector<vector<string> > readlines();
    void print(vector<string> lines);
};

#endif // FILE_HANDLER_HPP_