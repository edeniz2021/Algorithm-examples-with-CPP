#ifndef COURSE_H
#define COURSE_H

#include <string> 
#include "Student.hpp" 
namespace PA4
{
    class Student;
    class Course
    {
    private:
        std::string name;
        Student* students;
        std::string code;
        int numStudents;

    public:
        Course();
        Course(const std::string n,const std::string c);
        ~Course();
        Student* getStudents() const;
        void setName(std::string n){ name = n;}
        void setCode(std::string c){ code = c;}
        void add_student(Student *s);
        std::string getName()const{ return name;}
        std::string getCode()const{ return code;}
        bool operator==(const Course &other) const;
        void delete_student(Student *s);
        int getNumStudents()const{ return numStudents;}
    };
}

#endif
