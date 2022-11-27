#ifndef STUDENT_HANDLER_H /* STUDENT_HANDLER_H */
#define STUDENT_HANDLER_H

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include <student_handler.h>
#include <course_handler.h>
#include <utils.h>

using std::cout;
using std::string;
using std::vector;
using std::fstream;
using std::stringstream;
using std::ios;

class StudentHandler {
     private:
          string name;
          int studentID;
          vector<CourseHandler> courses;
          int num_courses;

     public:
          StudentHandler(string studentName, int ID) { return };
          StudentHandler(string data) { return };
          void add_course(string input) { return };
          void print() { return };

}

#endif /* STUDENT_HANDLER_H */