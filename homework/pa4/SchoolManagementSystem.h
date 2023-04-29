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
    };
}
