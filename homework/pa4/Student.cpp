#include "Student.h"
namespace PA4
{
    Student::Student()
    {
        name = "";
        ID = 0;
        course = nullptr;
    }
    Student::Student(const std::string n, int id)
    {
        name = n;
        ID = id;
        course = nullptr;
    }
    Student::~Student()
    {
        if (course != nullptr)
        {
            delete[] course;
            course = nullptr;
        }
    }
    Course** Student::getCourses() const
    {
        return course;
    }
}
