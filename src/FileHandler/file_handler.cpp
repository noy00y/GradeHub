#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include "file_handler.hpp"
// Unable to make the file_handler for this work properly
using namespace std;

FileHandler::FileHandler(string u_filename){
     filename=u_filename; 
     // Have processes to open and validate the content of the file and return an error and call destructor if the file is invalid
     return;
}
// FileHandler::~FileHandler() {} 

vector<string> FileHandler::readlines(){
     fstream file; 
     vector<string>lines;
     file.open(filename,ios::in);
     if (file.is_open()){
          string line;
          while (getline(file, line)){
               lines.push_back(line);
          }
     }
     file.close();
     return lines;
}

void FileHandler::print(vector<string> lines){
     for (int i=0;i<lines.size();i++){
          cout<<lines[i]<<endl;
     }
     return;
}


int main(){
     FileHandler file = FileHandler("CourseFile.txt");
     vector<string> lines = file.readlines();
     file.print(lines);
     return 0;
}