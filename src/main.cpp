#include "FileHandler\file_handler.hpp"
#include "StudentHandler\student_handler.hpp"
#include "CourseHandler\course_handler.hpp"
#include "Utils\utils.hpp"
using namespace std; // change to individual std::

int main() {
    StudentHandler teddy("Teddy Hyde, 642176077");
    teddy.print();

    // create instances of filehandler for each of the files and read the files lines
    FileHandler courses("../data/CourseFile.txt"); 
    FileHandler names("../data/NameFile.txt"); 
    courses.readlines();
    names.readlines();
    // vector containing student objects
    vector<StudentHandler> students; 
    
    for (int i=0;i<names.lines.size();i++){ // max complexity is still capped at N^2 (ignoring the usage of vectors)
        StudentHandler student(names.lines[i]);
        // add courses for each student
        
        for (int j=0;j<courses.lines.size();j++){
            student.add_course(courses.lines[j]);
        }
        students.push_back(student);
    }

    string output_file_path = "../data/Output.txt"; // does not clean the file if it is already in the path
    for (int i=0;i<students.size();i++){
        students[i].store(output_file_path);
    }
    
    return 0;
}
 
