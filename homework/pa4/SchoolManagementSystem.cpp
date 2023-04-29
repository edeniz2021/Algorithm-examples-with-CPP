#include "SchoolManagementSystem.h"
#include <iostream>

namespace PA4 {
    SchoolManagementSystem::SchoolManagementSystem() {
        courses = nullptr;
        students = nullptr;
        numCourses = 0;
        numStudents = 0;
    }

    SchoolManagementSystem::~SchoolManagementSystem() {
        if (students != nullptr) {
            for (int i = 0; i < numStudents; i++) {
                delete students[i];
            }
            delete[] students;
            students = nullptr;
        }
        if (courses != nullptr) {
            for (int i = 0; i < numCourses; i++) {
                delete courses[i];
            }
            delete[] courses;
            courses = nullptr;
        }
    }

    void SchoolManagementSystem::run() {
        std::cout << "Main_Menu" << std::endl;
        std::cout << "0 exit" << std::endl;
        std::cout << "1 student" << std::endl;
        std::cout << "2 course" << std::endl;
        std::cout << "3 list_all_students" << std::endl;
        std::cout << "4 list_all_courses" << std::endl;
    }
}
