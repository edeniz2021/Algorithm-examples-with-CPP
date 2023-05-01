#include "Course.h"
#include "Student.h"
namespace PA4 {
    class SchoolManagementSystem {
        private:
            Course** courses;
            Student** students;
            int numCourses=0;
            int numStudents=0;
        public:
            SchoolManagementSystem();
            ~SchoolManagementSystem();
            int getNumCourses()const{ return numCourses;}
            void run();
            void student_menu(std::string name, int id);
            void course_menu(std::string code, std::string name);
            void list_all_students();
            void list_all_courses();
            void add_course(Course c);
            void add_student(Student s);
            void select_student();
            void select_course();
            void delete_student(Student s);
            void delete_course(Course c);
            void list_students_registered_to_the_selected_course(Course c);
            void add_selected_student_to_a_course(Student s);
            void drop_selected_student_from_a_course(Student s);
            void addStudentToCourse(Student &student, Course &course);
            void dropStudentToCourse(Student &student, Course &course);
            Course *getCourseByIndex(int index);
            Student *getStudentByIndex(int index);
            //bool operator==(const SchoolManagementSystem &other) const;
    };
}
