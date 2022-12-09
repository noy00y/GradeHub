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
     // validate the filename and throw an exception if the filename does not end with a .txt (last four)
     if (filename.substr(filename.size()-4)!=".txt"){
          std::cerr << "Error: Invalid file format" << endl;
          exit(0);
     }
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

void FileHandler::set_lines(string linetowrite){
     ofstream file;
     file.open(filename,std::ios_base::app);
     file << linetowrite;
     file.close();
     return;
}

void FileHandler::clearfile(){
    std::ifstream File;
    File.open(filename, std::ifstream::trunc | std::ifstream::out); // open the file for outputting and close it to clear the file
    File.close();
    return;
} 
