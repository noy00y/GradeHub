#include "student_handler.hpp"
#include "..\CourseHandler\course_handler.hpp"
#include "..\Utils\utils.hpp"
#include "..\FileHandler\file_handler.hpp"


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
     for (int i=0;i<courses.size();i++){
          cout << studentID << ", " << name <<", "<< courses[i].code << ", " << courses[i].final_score << endl;
     }
     return;
}     

void StudentHandler::store(string filepath){
     FileHandler outputfile("../data/Output.txt");
     for (int i=0;i<courses.size();i++){
          string data = std::to_string(studentID) + ", " + name + ", " + courses[i].code + ", " + courses[i].final_score + "\n";
          outputfile.set_lines(data);
     }
     return;
}
