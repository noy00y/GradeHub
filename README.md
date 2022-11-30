<div align="center">
  
# _GradeHub_

### A fast system that combines, calculates and formats data with ease
![CPP](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![GitHub](https://img.shields.io/github/license/noy00y/Software-Engineering-Project?style=flat-square)

</div>


## Usage

### CLI

A simplified `Makefile` allows for easy compilation of the program. <br/>
Automatically calling from predefined data files in `./data` allows for the user to easily input sample data, delimitted by a comma.

<br/>

> Enter source directory
```sh
$ cd src
```

> Compile all files
```sh
$ make all
```
> Run the program
```sh
$ make run
```

### File Handler

```cpp
#include "file_handler.hpp"

FileHandler::FileHandler(string u_filename) {
     filename = u_filename; 
     return;
}

void FileHandler::readlines() {
     fstream file; 
     file.open(filename, ios::in);

     if (file.is_open()) {
          string line;
          while (getline(file, line)) {
               lines.push_back(line);
          }
     }

     file.close();

     return;
}

void FileHandler::print() {
     for (int i = 0; i < lines.size(); i++) {
          cout<<lines[i]<<endl;
     }

     return;
}

void FileHandler::set_lines(vector<string>u_lines) {
     lines = u_lines;
     return;
}
```

## Sample Input Data
<img src="./screenshots/sample_course_file.png">
<img src="./screenshots/sample_name_file.png">

## Sample Output Data
<img src="./screenshots/sample_output.png">