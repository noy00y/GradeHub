#ifndef COURSE_HANDLER_H /* COURSE_HANDLER_H */
#define COURSE_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <sstream>

#include ".\Utils\utils.hpp"

using std::cout;
using std::string;
using std::vector;
using std::stringstream;
using std::to_string;

class CourseHandler {
     private:
          int studentID;
          int num_scores; 
          string finalScore; 
          vector<float> scores;

     public:
          string code;

          CourseHandler(string data);

          void print() { return };
          bool taken_by(int given_ID) { return given_ID == studentID };
};

#endif /* COURSE_HANDLER_H */
