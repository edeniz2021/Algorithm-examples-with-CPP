#include "SchoolManagerSystem.hpp"
#include <iostream>
#include <string>
#include <sstream>
namespace PA4
{
    void SchoolManagerSystem::run()
    {
        int button = 1;
        int buttonTwo;
        std::cout << "Main_Menu" << std::endl;
        while (button != 0)
        {
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
    void SchoolManagerSystem::student_menu(std::string name, int id)
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
    void SchoolManagerSystem::course_menu(std::string code, std::string name)
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
    void SchoolManagerSystem::add_course(Course c)
    {
        if (numCourses == 0)
        {
            courses = new Course[1];
            courses[0] = c;
            numCourses++;
            return;
        }
        Course *newCourses = new Course[numCourses + 1];
        for (int i = 0; i < numCourses; i++)
        {
            newCourses[i] = courses[i];
        }
        newCourses[numCourses] = c;
        delete[] courses;
        courses = newCourses;
        numCourses++;
    }

    void SchoolManagerSystem::add_student(Student s)//to add user first increased memory then added to array
    {
        if (numStudents == 0)
        {
            students = new Student[1];
            students[0] = s;
            numStudents++;
            return;
        }
        Student *newStudents = new Student[numStudents + 1];
        for (int i = 0; i < numStudents; i++)
        {
            newStudents[i] = students[i];
        }
        newStudents[numStudents] = s;
        delete[] students;
        students = newStudents;
        numStudents++;
    }
    void SchoolManagerSystem::list_all_students()// print listt al
    {
        for (int i = 0; i < numStudents; i++)
        {
            std::cout << i + 1 << " " << students[i].getName() << " " << students[i].getID() << std::endl;
        }
        std::cout << std::endl;
    }

    void SchoolManagerSystem::list_all_courses()
    {
        for (int i = 0; i < numCourses; i++)
        {
            std::cout << i + 1 << " " << courses[i].getName() << " " << courses[i].getCode() << std::endl;
        }
        std::cout << std::endl;
    }
    void SchoolManagerSystem::select_student()
    {
        int id;
        std::string name;
        std::string input;
        name = "";
        while (std::cin >> input)//It removes the spaces and takes the input and defines it.
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
    void SchoolManagerSystem::select_course()
    {
        std::string code;
        std::string name;
        std::cin >> code;
        std::getline(std::cin >> std::ws, name);
        course_menu(code, name);
    }

    void SchoolManagerSystem::delete_student(Student s)//It finds which index it is in the array and removes it from the array.
    {
        int index = -1;
        for (int i = 0; i < numStudents; i++)
        {
            if (students[i].getName() == s.getName() && students[i].getID() && s.getID())
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            for (int i = index; i < numStudents - 1; i++)
            {
                students[i] = students[i + 1];
            }
            numStudents--;
        }
    }

    void SchoolManagerSystem::delete_course(Course c)
    {
        int index = -1;
        for (int i = 0; i < numCourses; i++)
        {
            if (courses[i].getCode() == c.getCode() && courses[i].getName() == c.getName())
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            for (int i = index; i < numCourses - 1; i++)
            {
                courses[i] = courses[i + 1];
            }
            numCourses--;
        }
    }
    void SchoolManagerSystem::list_students_registered_to_the_selected_course(Course c)
    {
        int count = 1;
        for (int i = 0; i < numStudents; i++)
        {
            if (students[i].isRegisteredToCourse(c))
            {
                std::cout << count << " " << students[i].getName() << " " << students[i].getID() << std::endl;
                count++;
            }
        }
        std::cout << std::endl;
    }
    void SchoolManagerSystem::add_selected_student_to_a_course(Student s)
    {
        std::cout << "0 up" << std::endl;
        for (int i = 0; i < numCourses; i++)
        {
            std::cout << i + 1 << " " << courses[i].getName() << " " << courses[i].getCode() << std::endl;
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
        Course c(courses[selection - 1].getName(), courses[selection - 1].getCode());//create new obje

        bool studentFound = false;
        bool courseFound = false;
        int studentIndex = -1;
        int courseIndex = -1;

        for (int i = 0; i < numStudents; i++)
        {
            if (students[i].getName() == s.getName() && students[i].getID() == s.getID())
            {
                studentFound = true;
                studentIndex = i;
                break;
            }
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (courses[i].getCode() == c.getCode() && courses[i].getName() == c.getName())
            {
                courseFound = true;
                courseIndex = i;
                break;
            }
        }

        if (studentFound && courseFound)
        {
            students[studentIndex].add_course(&c);//add student to course
            courses[courseIndex].add_student(&s);
        }
        else
        {
            std::cout << "Either the student or the course was not found. Please try again." << std::endl;
        }
        std::cout << std::endl;
    }
    void SchoolManagerSystem::drop_selected_student_from_a_course(Student s)
    {
        std::cout << "0 up" << std::endl;
        for (int i = 0; i < numCourses; i++)
        {
            std::cout << i + 1 << " " << courses[i].getName() << " " << courses[i].getCode() << std::endl;
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

        Course c(courses[selection -1].getCode(), courses[selection -1].getName() );

        bool studentFound = false;
        bool courseFound = false;
        int studentIndex = -1;
        int courseIndex = -1;

        for (int i = 0; i < numStudents; i++)
        {
            if (students[i].getName() == s.getName() && students[i].getID() == s.getID())
            {
                studentFound = true;
                studentIndex = i;
                break;
            }
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (courses[i].getCode() == c.getCode() && courses[i].getName() == c.getName())
            {
                courseFound = true;
                courseIndex = i;
                break;
            }
        }

        if (studentFound && courseFound)
        {
            bool dropped = students[studentIndex].dropFromCourse(c);
            if (dropped)
            {
                courses[courseIndex].delete_student(&s);
            }
        }
        else
        {
            std::cout << "Either the student or the course was not found. Please try again." << std::endl;
        }
        std::cout << std::endl;
    }

    SchoolManagerSystem::~SchoolManagerSystem()
    {
        delete[] courses;
        courses = nullptr;
        delete[] students;
        students = nullptr;
    }
}
