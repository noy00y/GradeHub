#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
// TODO: Error handling (offence tactic: accept no errors)
// TODO: Change how final grade is calcualted and stored, change how it is printed and stored (2 decimal places)

// Function used to remove commas in place
void remove(string &input, char toReplace){
    int len = input.size();
    for (int i=0; i<len ;i++){
        if (input[i]==toReplace){
            input.erase(i--,1);
            len = input.size();
        }
    }
    return;
}

// Function used to check if the given string only contains numbers
bool isnum(string line){
    stringstream strIn(line);
    char character;
    while (!strIn.fail()){
        strIn >> character;
        if (!isdigit(character)){
            return false;
        }
    } return true;
}

// Function to read the lines of a given file, append them to a vector, and to return the said vector
vector<string> readlines(string filename){
    fstream file; 
    vector<string>lines;
    file.open(filename,ios::in);
    if (file.is_open()){
        string line;
        while (getline(file, line)){
            lines.push_back(line);
        }
    }
    file.close();
    return lines;
}

// Course class (Each student will have many courses, each course of type Course)
class Course{
private: // Private Attributes
    int studentID;
    int N; // number of scores (len of vector scores)
    string finalScore; // NOTE: changing this a float breaks the code (add to testing notes?)
    vector<float> scores;
    
    
public: // Public Attributes
    string code;

public: // Public Methods

    // Constructor: Given the code code and the other data as a string create a course instance and populate the appropriate attributes
    Course(string data){
        stringstream strIn(data);

        if (strIn.fail()){
            // return an error message;
            cout << "Error: Invalid input" << endl;
        } else{
            
            // Default student ID values (incase the inputs are not valid)
            studentID = 0; 
            code = "None";

            while (!strIn.fail()){ // Loop till badbit/failbit in stringstream
                string line; 
                strIn >> line; // load data string (line) from stringstream into string line
                if (line.size()!=0){ // Check line and set/add it to the appropriate field
                    if (isnum(line) && line.size()==9) {studentID = stoi(line);}
                    if (line.size()==5){code=line;}
                    if (isnum(line)&&line.size()==2){scores.push_back(stoi(line));N++;}
                }
            } 
            
            // TODO: Calculate and set the final grade as a string?
            double finalGrade=0.0;
            int i=0;
            for (i;i<scores.size()-1;i++){finalGrade+=(scores[i]/100)*20;}finalGrade+=((scores[i]/100)*40);
            finalScore = to_string(finalGrade);

        } return;
    }

    // Print the objects data
    void print(){
        cout << "\tStudent ID: " << studentID << endl;
        cout << "\tCourse Code: " << code << endl;
        for (int i=0; i<N;i++){cout << "\tScore " << i+1 << ": " << scores[i] << endl;}
        cout<< "\tFinal Grade: " << finalScore << endl;
        return;
    }

    // Checks if the given student took the current course (based on student ID)
    bool takenBy(int givenID){
        return givenID==studentID;
    }

};

// Student class
class Student{
private: // Private Attributes
    string name;
    int studentID;
    vector<Course> courses;
    int N; // number of courses in the courses vector

public: // Public Methods
    
    // Constuctor: Given the student name and ID, set the private variables 
    Student(string studentName, int ID){ 
        name = studentName;
        studentID = ID;
        N = 0;
        return;
    }

    Student(string data){
        // Default values
        name = "None";
        studentID = 0;
        N = 0;

        // Clean given data and set attributes based on it
        remove(data,',');
        stringstream strIn(data);
        string line;
        while (!strIn.fail()){
            strIn >> line;
            if (line.size()!=0){
                if (isnum(line)){studentID=stoi(line);}
                else {
                    if (name=="None"){
                        name=line;
                    } else {
                        if (!strIn.fail()){
                            strIn >> line;
                            name.append(" ");
                            name.append(line);
                        }
                    }
                }
            }
        }
    }

    // Function to add course (data as a string, fstream will be used and the inputs will be parsed to the constructor for course)
    void addCourse(string input){
        remove(input,',');
        Course course(input);
        if (course.takenBy(studentID)){courses.push_back(course);N++;}
        return;
    }

    // Function that prints the data and calls print on the course objects when called    
    void print(){
        cout << "Student Name: " << name <<endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Number of courses: " << N << endl;
        cout << "Courses: " << endl;
        for (int i=0;i<N;i++){courses[i].print();}    
        return;
    }

};

int main(){    
    Student teddy("Teddy Hyde, 642176077");

    vector<string> courses; vector<string> names;
    vector<Student> students;

    courses = readlines("CourseFile.txt");
    names = readlines("NameFile.txt");

    for (int i=0;i<names.size();i++){ // max complexity is still capped at N^2 (ignoring the usage of vectors)
        Student student(names[i]);
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