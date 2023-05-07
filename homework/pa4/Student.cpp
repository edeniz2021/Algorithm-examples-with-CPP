#include "Student.hpp"
namespace PA4
{
    Student::Student()
    {
        name = "";
        ID = 0;
        course = nullptr;
        numCourse = 0;
    }
    Student::Student(const std::string n, int id)
    {
        name = n;
        ID = id;
        course = nullptr;
        numCourse = 0;
    }
    Student::~Student()
    {
        if (course != nullptr)
        {
            delete[] course;
            course = nullptr;
        }
    }
    Course *Student::getCourses() const
    {
        return course;
    }
    void Student::add_course(Course *c)
    {
        if (numCourse == 0)
        {
            course = new Course[1];
            course[0] = *c;
            numCourse++;
        }
        else
        {
            Course *newCourse = new Course[numCourse + 1];
            for (int i = 0; i < numCourse; i++)
            {
                newCourse[i] = course[i];
            }
            newCourse[numCourse] = *c;
            delete[] course;
            course = newCourse;
            numCourse++;
        }
    }

    void Student::delete_course(Course *c)
    {
        int index = -1;
        for (int i = 0; i < numCourse; i++)
        {
            if (course[i] == *c)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            Course *newCourse = new Course[numCourse - 1];
            for (int i = 0, j = 0; i < numCourse; i++)
            {
                if (i != index)
                {
                    newCourse[j] = course[i];
                    j++;
                }
            }
            delete[] course;
            course = newCourse;
            numCourse--;
        }
    }
    bool Student::operator==(const Student &other) const
    {
        return name == other.name && ID == other.ID;
    }
    bool Student::isRegisteredToCourse(Course c)
    {
        for (int i = 0; i < numCourse; i++)
        {
            if (course[i].getCode() == c.getCode() && course[i].getName() == c.getName())
            {
                return true;
            }
        }
        return false;
    }
    //This function attempts to remove the specified course from the student's list
    //of enrolled courses. If the course is found, it is removed and the function
    //returns true. If the course is not found, the function returns false.
    bool Student::dropFromCourse(Course c)
    {
        for (int i = 0; i < numCourse; i++)
        {
            if (course[i].getCode() == c.getCode() &&course[i].getName() == c.getName())
            {
                // Shift remaining elements left to fill gap
                for (int j = i; j < numCourse - 1; j++)
                {
                    course[j] = course[j + 1];
                }
                numCourse--;
                return true;
            }
        }
        return false;
    }

}
