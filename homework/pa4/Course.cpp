#include "Course.hpp"
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
        numStudents = 0;
    }
    Course::~Course()
    {
        if (students != nullptr)
        {
            delete[] students;
            students = nullptr;
        }
    }
    Student *Course::getStudents() const
    {
        return students;
    }
    void Course::add_student(Student *s)
    {
        if (numStudents == 0)
        {
            students = new Student[1];
            students[0] = *s;
            numStudents++;
        }
        else
        {
            Student *newStudents = new Student[numStudents + 1];
            for (int i = 0; i < numStudents; i++)
            {
                newStudents[i] = students[i];
            }
            newStudents[numStudents] = *s;
            delete[] students;
            students = newStudents;
            numStudents++;
        }
    }
    void Course::delete_student(Student *s)
    {
        int index = -1;
        for (int i = 0; i < numStudents; i++)
        {
            if (students[i] == *s)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            Student *newStudents = new Student[numStudents - 1];
            for (int i = 0, j = 0; i < numStudents; i++)
            {
                if (i != index)
                {
                    newStudents[j] = students[i];
                    j++;
                }
            }
            delete[] students;
            students = newStudents;
            numStudents--;
        }
    }
    bool Course::operator==(const Course &other) const
    {
        return name == other.name && code == other.code;
    }
}
