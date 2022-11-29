#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include "file_handler.hpp"

using namespace std;

FileHandler::FileHandler(string u_filename){
     filename=u_filename; 
     // Have processes to open and validate the content of the file and return an error and call destructor if the file is invalid
     return;
}

void FileHandler::readlines(){
     fstream file; 
     file.open(filename,ios::in);
     if (file.is_open()){
          string line;
          while (getline(file, line)){
               lines.push_back(line);
          }
     }
     file.close();
     return;
}

void FileHandler::print(){
     for (int i=0;i<lines.size();i++){
          cout<<lines[i]<<endl;
     }
     return;
}

void FileHandler::set_lines(vector<string>u_lines){
     lines = u_lines;
     return;
}