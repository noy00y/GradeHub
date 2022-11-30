#ifndef COURSE_HANDLER_H /* COURSE_HANDLER_H */
#define COURSE_HANDLER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <sstream>

#include "..\Utils\utils.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::stringstream;
using std::to_string;

/*
* 
* Course Handler Object
* ==================================
* Description: 
*     This object is used to handle 
*     the courses of each student
* ==================================
*/
class CourseHandler {
     /*
     * 
     * Private attributes
     *  - studentID (int) : the ID of the student
     *  - num_scores (int) : the number of scores
     *  - final_score (string) : the final score of the course 
     *  - scores (vector<float>) : the scores of the course
     * 
     */     
     private:
          int studentID;
          int num_scores; 
          vector<float> scores;
     /*
     * 
     * Public attributes & methods
     *  - code (string) : the code of the course
     *  - CourseHandler (constructor) : the constructor of the object
     *  - print (method) : prints the course information
     *  - taken_by (method) : returns true if the student took the course
     * 
     */    
     public:
          string code;
          string final_score; // made public as it may required for calculations such as the average etc. 
          CourseHandler(string data);
          void print();
          bool taken_by(int given_ID);
};

#endif /* COURSE_HANDLER_H */