#include "FileHandler\file_handler.hpp"
#include "StudentHandler\student_handler.hpp"
#include "CourseHandler\course_handler.hpp"
#include "Utils\utils.hpp"
using namespace std;

int main() {
    StudentHandler teddy("Teddy Hyde, 642176077");
    teddy.print();


    // create instances of filehandler for each of the files and read the files lines
    FileHandler courses("C:/Users/Harri/Desktop/dev/Software-Engineering-Project/data/CourseFile.txt"); 
    FileHandler names("C:/Users/Harri/Desktop/dev/Software-Engineering-Project/data/NameFile.txt"); 
    courses.readlines();
    names.readlines();
    courses.print();
    names.print();
    // vector containing student objects
    vector<StudentHandler> students; 
    
    // for (int i=0;i<names.size();i++){ // max complexity is still capped at N^2 (ignoring the usage of vectors)
    //     StudentHandler student(names[i]);
    //     // add courses for each student
    //     for (int j=0;j<courses.size();j++){
    //         student.add_course(courses[j]);
    //     }
    //     students.push_back(student);
    // }

    // for (int i=0;i<students.size();i++){
    //     students[i].print();
    // }

    // // ((float)score/100)*20 (or 40 depending on the weight)
    
    return 0;
}
 
