#include "student_handler.h"
#include ".\CourseHandler\course_handler.hpp"
#include ".\Utils\utils.h"

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
     * Public attributes & methods
     *  - StudentHandler (constructor) : the constructor of the object for a given name and ID
     *  - StudentHandler (constructor) : the constructor of the object for a given data string
     *  - add_course (method) : adds a course to the student
     *  - print (method) : prints the student information
     * 
     */   
     public:
          StudentHandler(string studentName, int ID) { 
               name = studentName;
               studentID = ID;
               num_courses = 0;
               return;
          }

          StudentHandler(string data) {
               name = "None";
               studentID = 0;
               num_courses = 0;

               remove(data,',');
               stringstream strIn(data);
               string line;

               while (!strIn.fail()) {
                    strIn >> line;
                    if (line.size() != 0) {
                         if (isnum(line)) {
                              studentID=stoi(line);
                         } else {
                              if (name=="None") {
                                   name=line;
                              } else {
                                   if (!strIn.fail()) {
                                        strIn >> line;
                                        name.append(" ");
                                        name.append(line);
                                   }
                              }
                         }
                    }
               }
          }

          /*
          * 
          * Adds a course object to the student's list of courses.
          * Returns nothing.
          * 
          */
          void add_course(string input) {
               remove(input,',');
               CourseHandler course(input);

               if (course.takenBy(studentID)) {
                    courses.push_back(course);
                    num_courses++;
               }

               return;
          }
          
          /*
          * 
          * Prints the data and calls print on the course objects when called.    
          * Returns nothing.
          * 
          */
          void print() {
               cout << "Student Name: " << name << "\n";
               cout << "Student ID: " << studentID << "\n";
               cout << "Number of courses: " << num_courses << "\n";
               cout << "Courses: " << "\n";

               for (int i = 0; i < num_courses; i++) {
                    courses[i].print();
               }    

               return;
          }     
};