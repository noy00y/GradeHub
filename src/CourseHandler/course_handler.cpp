#include <course_handler.h>
#include <utils.h>

/*
* 
* Course Handler Object
* ==================================
* Description: 
*     This object is used to handle 
*     the courses of each student
* ==================================
*/
class CourseHandler {
     
     /*
     * 
     * Private attributes
     *  - studentID (int) : the ID of the student
     *  - num_scores (int) : the number of scores
     *  - final_score (string) : the final score of the course 
     *  - scores (vector<float>) : the scores of the course
     * 
     */     
     private: 
          int studentID;
          int num_scores; 
          string final_score; 
          vector<float> scores;

     /*
     * 
     * Public attributes & methods
     *  - code (string) : the code of the course
     *  - CourseHandler (constructor) : the constructor of the object
     *  - print (method) : prints the course information
     *  - taken_by (method) : returns true if the student took the course
     * 
     */    
     public: 
          string code;

          CourseHandler(string data) {
               stringstream strIn(data);

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
                              }

                              if (isnum(line)&&line.size()==2) {
                                   scores.push_back(stoi(line));
                                   num_scores++;
                              }
                         }
                    } 

                    double final_grade = 0.0;
                    int i = 0;

                    for (i; i < scores.size()-1; i++) {
                         final_grade += ((scores[i] / 100) * 20);
                    }
                    
                    final_grade+=((scores[i] / 100) * 40);
                    final_score = to_string(final_grade);
               } 
               
               return;
          }

          /*
          * 
          * Print the objects data.
          * Returns nothing.
          * 
          */
          void print() {
               cout << "\tStudent ID: " << studentID << "\n";
               cout << "\tCourse Code: " << code << "\n";

               for (int i = 0; i < num_scores; i++) {
                    cout << "\tScore " << i++ << ": " << scores[i] << "\n";
               }

               cout<< "\tFinal Grade: " << final_score << "\n";

               return;
          }
          
          /*
          * 
          * Returns true if the given student took the current course & false otherwise.
          * 
          */
          bool taken_by(int given_ID) {
               return given_ID == studentID;
          }
};