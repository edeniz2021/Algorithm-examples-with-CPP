#ifndef COURSE_H
#define COURSE_H

#include <string> // add this line

namespace PA4
{
    class Student;

    class Course
    {
    private:
        std::string name;
        Student** students;
        std::string code;

    public:
        Course();
        Course(const std::string n,const std::string c);
        ~Course();
        Student** getStudents() const;
    };
}

#endif
