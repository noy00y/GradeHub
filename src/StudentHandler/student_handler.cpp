#include "student_handler.hpp"
#include "..\CourseHandler\course_handler.hpp"
#include "..\Utils\utils.hpp"

/*
* 
* Student Handler Object
* ==================================
* Description: 
*     This object is used to handle 
*     each student & their courses
* ==================================
*/
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
     cout << data << endl;
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

void StudentHandler::add_course(string input) {
     remove(input,',');
     CourseHandler course(input);
     if (course.taken_by(studentID)) {
          courses.push_back(course);
          num_courses++;
     }
     return;
}
          
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
