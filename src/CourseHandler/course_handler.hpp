#ifndef COURSE_HANDLER_HPP_ /* COURSE_HANDLER_HPP_ */
#define COURSE_HANDLER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <sstream>

#include "../Utils/utils.hpp" 

using namespace std;

class CourseHandler {
     private:
          int studentID;
          int num_scores; 
          string final_score; 
          vector<float> scores;

     public:
          string code;
          CourseHandler(string data); // Constructor
          // ~CourseHandler(); // Deconstructor
          void print();
          bool taken_by(int given_ID);
};

#endif /* COURSE_HANDLER_HPP_ */
