#include "course_handler.hpp"
#include "..\Utils\utils.hpp"

CourseHandler:: CourseHandler(string data) {
     remove(data,','); // remove commas from the given data
     stringstream strIn(data); // set up string stream to itterate over the given data
     if (strIn.fail()) {
          cout << "Error: Invalid input" << "\n";
     } else {
          studentID = 0; 
          code = "None";
          while (!strIn.fail()) { // Loop till badbit/failbit in stringstream
               string line; 
               strIn >> line; // load data string (line) from stringstream into string line
               if (line.size() != 0) { // Check line and set/add it to the appropriate field
                    if (isnum(line) && line.size()==9) {
                         studentID = stoi(line);
                    }
                    if (line.size()==5) {
                         code=line;
                    } if (isnum(line)&&line.size()==2) {
                         scores.push_back(stoi(line));
                         num_scores++;
                    }
               }
          } 

          // Calculate the final grade
          double final_grade = 0.0;
          int i;
          for (i=0; i<scores.size()-1; i++) {
               final_grade += ((scores[i] / 100) * 20);
          }
          final_grade +=((scores[i] / 100) * 40);
          final_score = to_string(final_grade);
     } 
     return;
}

void CourseHandler::print() {
     cout << "\tStudent ID: " << studentID << "\n";
     cout << "\tCourse Code: " << code << "\n";
     for (int i = 0; i < num_scores; i++) {
          cout << "\tScore " << i << ": " << scores[i] << "\n";
     }
     cout<< "\tFinal Grade: " << final_score << "\n";
     return;
}
          
bool CourseHandler::taken_by(int given_ID) {
     return given_ID == studentID;
}