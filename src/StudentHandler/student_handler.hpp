#ifndef STUDENT_HANDLER_H /* STUDENT_HANDLER_H */
#define STUDENT_HANDLER_H

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include "..\CourseHandler\course_handler.hpp"
#include "..\Utils\utils.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::vector;
using std::fstream;
using std::stringstream;
using std::ios;

/*
* 
* Student Handler Object
* ==================================
* Description: 
*     This object is used to handle 
*     each student & their courses
* ==================================
*/
class StudentHandler {
     /*
     * 
     * Private attributes
     *  - name (string) : the name of the student
     *  - studentID (int) : the ID of the student
     *  - courses (vector<CourseHandler>) : the courses of the student 
     *  - num_courses (int) : the number of courses
     * 
     */  
     private:
          string name;
          int studentID;
          vector<CourseHandler> courses;
          int num_courses;
     /*
     * 
     * Public methods
     *  - StudentHandler (constructor) : the constructor of the object for a given name and ID
     *  - StudentHandler (constructor) : the constructor of the object for a given data string
     *  - add_course (method) : adds a course to the student
     *  - print (method) : prints the student information
     * 
     */   
     public:
          StudentHandler(string studentName, int ID);
          StudentHandler(string data);
          void add_course(string input);
          void print();
          void store(string filename);
};

#endif /* STUDENT_HANDLER_H */