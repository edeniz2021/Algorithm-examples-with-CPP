#ifndef COURSE_H
#define COURSE_H

#include <string> 
#include "Student.h" 
namespace PA4
{
    class Student;
    class Course
    {
    private:
        std::string name;
        Student** students;
        std::string code;
        int numStudents;

    public:
        Course();
        Course(const std::string n,const std::string c);
        ~Course();
        Student** getStudents() const;
        void add_student(Student *s);
        std::string getName()const{ return name;}
        std::string getCode()const{ return code;}
        bool operator==(const Course &other) const;
        void delete_student(Student *s);
    };
}

#endif
