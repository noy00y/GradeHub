#include <iostream>
#include <student_handler.h>

class StudentHandler {
     public:
          int student_id;
          char student_name[50];

          void setStudentId(int id) {
               student_id = id;
          }

          void setStudentName(char name[]) {
               strcpy(student_name, name);
          }

          int getStudentId() {
               return student_id;
          }

          char* getStudentName() {
               return student_name;
          }

          void printStudentDetails() {
               std::cout << "Student ID: " << student_id << std::endl;
               std::cout << "Student Name: " << student_name << std::endl;
          }
};

