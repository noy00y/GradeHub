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


          // Offensive error handling: Ignore all the grade entires that have less or more than 4 scores as this program is tailored for handling 4 scores
          if (scores.size()==4){
                         // Calculate the final grade
          double final_grade = 0.0;
          int i;
          for (i=0; i<scores.size()-1; i++) {
               final_grade += ((scores[i] / 100) * 20);
          }
          final_grade +=((scores[i] / 100) * 40);
          final_score = to_string(final_grade);
          // trim the final score to have only one digit after the decimal point
          if (final_score.size()>3){ // two digits, a decimal and more
               string trimmed_final_score="";
               trimmed_final_score.append(final_score,0,4);
               final_score = trimmed_final_score;
          } 
          } else {
               scores.clear(); // clear all the scores
               // set the final score as an error message
               final_score = "Invalid number of scores given for this course";
          }
     } 
     return;
}

/*
* 
* Print the objects data.
* Returns nothing.
* 
*/
void CourseHandler::print() {
     cout << "\tStudent ID: " << studentID << "\n";
     cout << "\tCourse Code: " << code << "\n";
     for (int i = 0; i < num_scores; i++) {
          cout << "\tScore " << i << ": " << scores[i] << "\n";
     }
     cout<< "\tFinal Grade: " << final_score << "\n";
     return;
}

/*
* 
* Returns true if the given student took the current course & false otherwise.
* 
*/       
bool CourseHandler::taken_by(int given_ID) {
     return given_ID == studentID;
}