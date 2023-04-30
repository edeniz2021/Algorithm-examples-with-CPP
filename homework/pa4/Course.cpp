#include "Course.h"
#include <string>
namespace PA4
{
    Course::Course()
    {
        name = "";
        code = "";
        students = nullptr;
    }
    Course::Course(const std::string n, const std::string c)
    {
        name = n;
        code = c;
        students = nullptr;
    }
    Course::~Course()
    {
        if (students != nullptr)
        {
            delete[] students;
            students = nullptr;
        }
    }
    Student **Course::getStudents() const
    {
        return students;
    }
    void Course::add_student(Student *s)
    {
        Student **new_students = new Student *[numStudents + 1];
        for (int i = 0; i < numStudents; i++)
        {
            new_students[i] = students[i];
        }
        new_students[numStudents] = s;
        delete[] students;
        students = new_students;
        numStudents++;
    }

}
