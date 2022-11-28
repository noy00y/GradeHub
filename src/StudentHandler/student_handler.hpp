#ifndef STUDENT_HANDLER_HPP_ /* STUDENT_HANDLER_HPP_ */
#define STUDENT_HANDLER_HPP_

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include "../CourseHandler/course_handler.hpp"
#include "../Utils/utils.hpp"

using namespace std;

class StudentHandler {
     private:
          string name;
          int studentID;
          vector<CourseHandler> courses;
          int num_courses;

     public:
          StudentHandler(string studentName, int ID);
          StudentHandler(string data);
          // ~StudentHandler();
          void add_course(string input);
          void print();

};

#endif /* STUDENT_HANDLER_HPP_ */