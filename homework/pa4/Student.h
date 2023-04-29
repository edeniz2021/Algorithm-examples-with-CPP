#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Course.h" 

namespace PA4
{
    class Student;
    class Student
    {
    private:
        std::string name;
        int ID;
        Course** course;

    public:
        Student();
        Student(const std::string n, int id);
        ~Student();
        Course** getCourses() const;
    };
}

#endif
