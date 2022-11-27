#include "utils.h"

/*
 * 
 * Removes a specificed character from a string.
 * Returns nothing.
 * 
 */
void remove(string &input, char to_replace) {
    int length = input.size();

    for (int i = 0; i < length; i++) {
          if (input[i] == to_replace) {
               input.erase(i--, 1);
               length = input.size();
          }
    }

    return;
}

/*
 * 
 * Checks if a given string only contains numbers. 
 * Returns true if the string only contains numbers, false otherwise.
 * 
 */
bool isnum(string line) {
    stringstream strIn(line);
    char character;

    while (!strIn.fail()) {
          strIn >> character;
          if (!isdigit(character)) {
               return false;
          }
    } 
    
    return true;
}

/*
 * 
 * Reads the lines of a given file and appends them to a vector.
 * Returns the vector of lines.
 * 
 */
vector<string> readlines(string filename) {
     fstream file; 
     vector<string> lines;
     file.open(filename, ios::in);

     if (file.is_open()) {
          string line;
          while (getline(file, line)) {
               lines.push_back(line);
          }
     }

     file.close();
     return lines;
}