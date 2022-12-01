#include "student_handler.hpp"

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
     for (int i = 0; i < courses.size(); i++) {
          cout << studentID << ", " << name <<", "<< courses[i].code << ", " << courses[i].final_score << endl;
     }
     return;
}     

void StudentHandler::store(string filepath) {
     // Should be done through the FileHandler (setting lines)
     ofstream file;
     file.open(filepath, std::ios_base::app);

     for (int i = 0; i < courses.size(); i++){
          if (courses[i].final_score=="Invalid number of scores given for this course"){
               cout << studentID << " " << courses[i].final_score << ": " << courses[i].code << endl;
          } else {
               file << studentID << ", " << name <<", "<< courses[i].code << ", " << courses[i].final_score << endl;
          }
     }

     file.close();

     return;
}
