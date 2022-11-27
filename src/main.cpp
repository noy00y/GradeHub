#include "FileHandler\file_handler.hpp"
#include "StudentHandler\student_handler.hpp"
#include "CourseHandler\course_handler.hpp"
#include "Utils\utils.hpp"

int main() {
    StudentHandler teddy("Teddy Hyde, 642176077");

    vector<string> courses; vector<string> names;
    vector<StudentHandler> students;

    courses = readlines("CourseFile.txt");
    names = readlines("NameFile.txt");

    for (int i=0;i<names.size();i++){ // max complexity is still capped at N^2 (ignoring the usage of vectors)
        StudentHandler student(names[i]);
        // add courses for each student
        for (int j=0;j<courses.size();j++){
            student.addCourse(courses[j]);
        }
        students.push_back(student);
    }

    for (int i=0;i<students.size();i++){
        students[i].print();
    }

    // ((float)score/100)*20 (or 40 depending on the weight)
    
    return 0;
}
 
