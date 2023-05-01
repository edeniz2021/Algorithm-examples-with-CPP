#include "SchoolManagementSystem.h"
#include <iostream>
#include <string>
#include <sstream>
namespace PA4
{
    SchoolManagementSystem::SchoolManagementSystem()
    {
        courses = nullptr;
        students = nullptr;
    }

    void SchoolManagementSystem::run()
    {
        int button = 1;
        int buttonTwo;
        while (button != 0)
        {
            std::cout << "Main_Menu" << std::endl;
            std::cout << "0 exit" << std::endl;
            std::cout << "1 student" << std::endl;
            std::cout << "2 course" << std::endl;
            std::cout << "3 list_all_students" << std::endl;
            std::cout << "4 list_all_courses" << std::endl;
            std::cin >> button;
            if (button == 1)
            {
                buttonTwo = 1;
                while (buttonTwo != 0)
                {
                    std::cout << "0 up" << std::endl;
                    std::cout << "1 add_student" << std::endl;
                    std::cout << "2 select_student" << std::endl;
                    std::cin >> buttonTwo;
                    if (buttonTwo == 1)
                    {
                        int id;
                        std::string name;
                        std::string input;
                        name = "";
                        while (std::cin >> input)
                        {
                            std::istringstream ss(input);
                            if (ss >> id)
                            {
                                break;
                            }

                            if (!name.empty())
                            {
                                name += " ";
                            }
                            name += input;
                        }
                        Student s(name, id);
                        add_student(s);
                    }
                    else if (buttonTwo == 2)
                    {
                        select_student();
                    }
                }
            }
            else if (button == 2)
            {
                buttonTwo = 1;
                while (buttonTwo != 0)
                {
                    std::cout << "0 up" << std::endl;
                    std::cout << "1 add_course" << std::endl;
                    std::cout << "2 select_course" << std::endl;
                    std::cin >> buttonTwo;
                    if (buttonTwo == 1)
                    {
                        std::string code;
                        std::string name;
                        std::cin >> code;
                        std::getline(std::cin >> std::ws, name);
                        Course c(code, name);
                        add_course(c);
                    }
                    else if (buttonTwo == 2)
                    {
                        select_course();
                    }
                }
            }
            else if (button == 3)
            {
                list_all_students();
            }
            else if (button == 4)
            {
                list_all_courses();
            }
            else if (button == 0)
            {
                exit(0);
            }
        }
    }
    void SchoolManagementSystem::student_menu(std::string name, int id)
    {
        Student s(name, id);
        int button = 1;
        int buttonTwo;
        while (button != 0)
        {
            std::cout << "0 up" << std::endl;
            std::cout << "1 delete_student" << std::endl;
            std::cout << "3 add_selected_student_to_a_course" << std::endl;
            std::cout << "4 drop_selected_student_from_a_course" << std::endl;
            std::cin >> buttonTwo;
            if (buttonTwo == 1)
            {

                delete_student(s);
            }
            else if (buttonTwo == 3)
            {
                add_selected_student_to_a_course(s);
            }
            else if (buttonTwo == 4)
            {
                drop_selected_student_from_a_course(s);
            }
            else if (buttonTwo == 0)
            {
                button = 0;
            }
        }
    }
    void SchoolManagementSystem::course_menu(std::string code, std::string name)
    {
        Course c(code, name);
        int button = 1;
        int buttonTwo;
        while (button != 0)
        {
            std::cout << "0 up" << std::endl;
            std::cout << "1 delete_course" << std::endl;
            std::cout << "2 list_students_registered_to_the_selected_course" << std::endl;
            std::cin >> buttonTwo;
            if (buttonTwo == 0)
            {
                button = 0;
            }
            else if (buttonTwo == 1)
            {
                delete_course(c);
            }
            else if (buttonTwo == 2)
            {
                list_students_registered_to_the_selected_course(c);
            }
        }
    }
    void SchoolManagementSystem::add_course(Course c)
    {
        if (numCourses == 0)
        {
            courses = new Course *[1];
            courses[0] = new Course(c);
            numCourses++;
            return;
        }
        Course **newCourses = new Course *[numCourses + 1];
        for (int i = 0; i < numCourses; i++)
        {
            newCourses[i] = courses[i];
        }
        newCourses[numCourses] = new Course(c);
        delete[] courses;
        courses = newCourses;
        numCourses++;
    }

    void SchoolManagementSystem::add_student(Student s)
    {
        if (numStudents == 0)
        {
            students = new Student *[1];
            students[0] = new Student(s);
            numStudents++;
            return;
        }
        Student **newStudent = new Student *[numStudents + 1];
        for (int i = 0; i < numStudents; i++)
        {
            newStudent[i] = students[i];
        }
        newStudent[numStudents] = new Student(s);
        delete[] students;
        students = newStudent;
        numStudents++;
    }
    Course *SchoolManagementSystem::getCourseByIndex(int index)
    {
        if (index < 0 || index >= numCourses)
        {
            return nullptr;
        }
        return courses[index];
    }

    Student *SchoolManagementSystem::getStudentByIndex(int index)
    {
        if (index < 0 || index >= numStudents)
        {
            return nullptr;
        }
        return students[index];
    }
    void SchoolManagementSystem::list_all_students()
    {
        std::cout << "List of all students:" << std::endl;
        for (int i = 0; i < numStudents; i++)
        {
            std::cout << i + 1 << " " << students[i]->getName() << " " << students[i]->getID() << std::endl;
        }
    }

    void SchoolManagementSystem::list_all_courses()
    {
        std::cout << "List of all courses:" << std::endl;
        for (int i = 0; i < numCourses; i++)
        {
            std::cout << i + 1 << " " << courses[i]->getName() << " " << courses[i]->getCode() << std::endl;
        }
    }
    void SchoolManagementSystem::select_student()
    {
        int id;
        std::string name;
        std::string input;
        name = "";
        while (std::cin >> input)
        {
            std::istringstream ss(input);
            if (ss >> id)
            {
                break;
            }

            if (!name.empty())
            {
                name += " ";
            }
            name += input;
        }
        student_menu(name, id);
    }
    void SchoolManagementSystem::select_course()
    {
        std::string code;
        std::string name;
        std::cin >> code;
        std::getline(std::cin >> std::ws, name);
        course_menu(code, name);
    }
    void SchoolManagementSystem::delete_student(Student s)
    {
        int index = -1;
        for (int i = 0; i < numStudents; i++)
        {
            if (*students[i] == s)
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
    void SchoolManagementSystem::delete_course(Course c)
    {
        int index = -1;
        for (int i = 0; i < numCourses; i++)
        {
            if (*courses[i] == c)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            delete courses[index];
            for (int i = index; i < numCourses - 1; i++)
            {
                courses[i] = courses[i + 1];
            }
            numCourses--;
        }
    }
    void SchoolManagementSystem::list_students_registered_to_the_selected_course(Course c)
    {
        bool found = false;
        for (int i = 0; i < numStudents; i++)
        {
            Course **courses = students[i]->getCourses();
            for (int j = 0; j < students[i]->getNumCourses(); j++)
            {
                if (*courses[j] == c)
                {
                    std::cout << students[i]->getName() << " " << students[i]->getID() << std::endl;
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            std::cout << "No students are registered to this course." << std::endl;
        }
    }
    void SchoolManagementSystem::add_selected_student_to_a_course(Student s)
    {
        if (numCourses == 0)
        {
            std::cout << "There are no courses to add the student to." << std::endl;
            return;
        }
        std::cout << "0 up" << std::endl;
        for (int i = 0; i < numCourses; i++)
        {
            std::cout << i + 1 << " " << courses[i]->getCode() << " " << courses[i]->getName() << std::endl;
        }
        int selection;
        std::cin >> selection;
        if (selection < 0 || selection > numCourses)
        {
            std::cout << "Invalid value." << std::endl;
            return;
        }
        if (selection == 0)
        {
            student_menu(s.getName(), s.getID());
        }
        else
        {
            Course *c = courses[selection - 1];
            addStudentToCourse(s, *c);
            std::cout << "Student added to course " << c->getName() << "." << std::endl;
        }
    }
    void SchoolManagementSystem::addStudentToCourse(Student &student, Course &course)
    {
        student.add_course(&course);
        course.add_student(&student);
    }
    void SchoolManagementSystem::drop_selected_student_from_a_course(Student s)
    {
        if (numCourses == 0)
        {
            std::cout << "There are no courses to drop the student to." << std::endl;
            return;
        }
        std::cout << "0 up" << std::endl;
        for (int i = 0; i < numCourses; i++)
        {
            std::cout << i + 1 << courses[i]->getCode() << " " << courses[i]->getName() << std::endl;
        }

        int selection;
        std::cin >> selection;
        if (selection < 0 || selection > numCourses)
        {
            std::cout << "Invalid value." << std::endl;
            return;
        }
        if (selection == 0)
        {
            student_menu(s.getName(), s.getID());
        }
        else
        {
            Course *c = courses[selection - 1];
            dropStudentToCourse(s, *c);
            std::cout << "Student added to course " << c->getName() << "." << std::endl;
        }
    }
    void SchoolManagementSystem::dropStudentToCourse(Student &student, Course &course)
    {
        student.delete_course(&course);
        course.delete_student(&student);
    }
    SchoolManagementSystem::~SchoolManagementSystem()
    {
        for (int i = 0; i < numStudents; ++i)
        {
            delete students[i];
        }
        delete[] students;

        for (int i = 0; i < numCourses; ++i)
        {
            delete courses[i];
        }
        delete[] courses;
    }
}
