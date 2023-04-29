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
    Student** Course::getStudents() const
    {
        return students;
    }
}
