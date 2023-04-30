#include "Course.h"
#include "Student.h"
namespace PA4 {
    class SchoolManagementSystem {
        private:
            Course** courses;
            Student** students;
            int numCourses;
            int numStudents;
        public:
            SchoolManagementSystem();
            ~SchoolManagementSystem();
            void run();
            void student_menu();
            void course_menu();
            void list_all_students();
            void list_all_courses();
            void add_course(Course c);
            void add_student(Student s);
            void select_student();
            void select_course();
    };
}
