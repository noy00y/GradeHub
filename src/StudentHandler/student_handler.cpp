#include "student_handler.hpp"
#include "..\CourseHandler\course_handler.hpp"
#include "..\Utils\utils.hpp"


StudentHandler:: StudentHandler(string studentName, int ID) { 
     name = studentName;
     studentID = ID;
     num_courses = 0;
     return;
}

StudentHandler:: StudentHandler(string data) {
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
void StudentHandler::add_course(string input) {
     remove(input,',');
     CourseHandler course(input);
     if (course.taken_by(studentID)) {
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
void StudentHandler::print() {
     cout << "Student Name: " << name << "\n";
     cout << "Student ID: " << studentID << "\n";
     cout << "Number of courses: " << num_courses << "\n";
     cout << "Courses: " << "\n";

     for (int i = 0; i < num_courses; i++) {
          courses[i].print();
     }    
     return;
}     
