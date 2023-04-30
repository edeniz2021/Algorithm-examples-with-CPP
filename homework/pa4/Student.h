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
        int numCourse;

    public:
        Student();
        Student(const std::string n, int id);
        ~Student();
        Course** getCourses() const;
        void add_course(Course *c);
        std::string getName()const{ return name;}
        int getID()const{ return ID;}
    };
}

#endif
