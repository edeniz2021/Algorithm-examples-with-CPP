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
    Course **Student::getCourses() const
    {
        return course;
    }
    void Student::add_course(Course *c)
    {
        Course **new_courses = new Course *[numCourse + 1];
        for (int i = 0; i < numCourse; i++)
        {
            new_courses[i] = course[i];
        }
        new_courses[numCourse] = c;
        numCourse++;
        delete[] course;
        course = new_courses;
    }
    void Student::delete_course(Course *c)
    {
        int index = -1;
        for (int i = 0; i < numCourse; i++)
        {
            if (course[i] == c)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            delete course[index];
            for (int i = index; i < numCourse - 1; i++)
            {
                course[i] = course[i + 1];
            }
            numCourse--;
        }
    }
    bool Student::operator==(const Student &other) const
    {
        return name == other.name && ID== other.ID;
    }
}
