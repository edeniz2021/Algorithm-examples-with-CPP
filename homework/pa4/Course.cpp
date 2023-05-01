#include "Course.h"
#include <string>
namespace PA4
{
    Course::Course()
    {
        name = "";
        code = "";
        students = nullptr;
        numStudents = 0;
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
    void Course::delete_student(Student *s)
    {
        int index = -1;
        for (int i = 0; i < numStudents; i++)
        {
            if (students[i] == s)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            delete students[index];
            for (int i = index; i < numStudents - 1; i++)
            {
                students[i] = students[i + 1];
            }
            numStudents--;
        }
    }
    bool Course::operator==(const Course &other) const
    {
        return name == other.name && code == other.code;
    }

}
