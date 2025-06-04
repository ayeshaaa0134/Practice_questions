#include <iostream>
#include <string>
using namespace std;
const int MAX_DEPARTMENTS = 10;
const int MAX_COURSES = 10;
const int MAX_STUDENTS = 50;

// ////////////////////////- Student ////////////////////////-
class Student {
public:
    std::string name;

    Student(const std::string& name) : name(name) {}
};

// ////////////////////////- Instructor ////////////////////////-
class Instructor {
public:
    std::string name;

    Instructor(const std::string& name) : name(name) {}
};

// ////////////////////////- Course ////////////////////////-
class Course {
public:
    std::string title;
    Instructor* instructor;                 // Association
    Student* students[MAX_STUDENTS];        // Association
    int studentCount;

    Course(const std::string& title) : title(title), instructor(nullptr), studentCount(0) {}

    void assignInstructor(Instructor* inst) {
        instructor = inst;
    }

    void addStudent(Student* student) {
        if (studentCount < MAX_STUDENTS) {
            students[studentCount++] = student;
        } else {
            std::cout << "Course is full!\n";
        }
    }

    void removeStudent(Student* student) {
        for (int i = 0; i < studentCount; ++i) {
            if (students[i] == student) {
                for (int j = i; j < studentCount - 1; ++j) {
                    students[j] = students[j + 1];
                }
                --studentCount;
                break;
            }
        }
    }

    void printInfo() const {
        std::cout << "Course: " << title << "\n";
        if (instructor)
            std::cout << "Instructor: " << instructor->name << "\n";
        std::cout << "Enrolled Students:\n";
        for (int i = 0; i < studentCount; ++i)
            std::cout << "- " << students[i]->name << "\n";
    }
};

// ////////////////////////- Department ////////////////////////-
class Department {
public:
    std::string name;
    Course* courses[MAX_COURSES];   // Aggregation
    int courseCount;

    Department(const std::string& name) : name(name), courseCount(0) {}

    void addCourse(Course* course) {
        if (courseCount < MAX_COURSES) {
            courses[courseCount++] = course;
        } else {
            std::cout << "Max course limit reached!\n";
        }
    }

    void removeCourse(Course* course) {
        for (int i = 0; i < courseCount; ++i) {
            if (courses[i] == course) {
                for (int j = i; j < courseCount - 1; ++j) {
                    courses[j] = courses[j + 1];
                }
                --courseCount;
                break;
            }
        }
    }

    void printCourses() const {
        std::cout << "Courses in Department " << name << ":\n";
        for (int i = 0; i < courseCount; ++i)
            std::cout << "- " << courses[i]->title << "\n";
    }
};

// ////////////////////////- University ////////////////////-////
class University {
public:
    std::string name;
    Department* departments[MAX_DEPARTMENTS];   // Composition
    int departmentCount;

    University(const std::string& name) : name(name), departmentCount(0) {}

    ~University() {
        // Cleanup composed departments
        for (int i = 0; i < departmentCount; ++i)
            delete departments[i];
    }

    Department* addDepartment(const std::string& deptName) {
        if (departmentCount < MAX_DEPARTMENTS) {
            departments[departmentCount] = new Department(deptName);
            return departments[departmentCount++];
        } else {
            std::cout << "Max department limit reached!\n";
            return nullptr;
        }
    }

    void removeDepartment(const std::string& deptName) {
        for (int i = 0; i < departmentCount; ++i) {
            if (departments[i]->name == deptName) {
                delete departments[i];  // Free memory
                for (int j = i; j < departmentCount - 1; ++j)
                    departments[j] = departments[j + 1];
                --departmentCount;
                break;
            }
        }
    }

    void printDepartments() const {
        std::cout << "Departments in University " << name << ":\n";
        for (int i = 0; i < departmentCount; ++i)
            std::cout << "- " << departments[i]->name << "\n";
    }
};
int main() {
    University uni("Air University");

    // Add departments
    Department* csDept = uni.addDepartment("FCAI");
    Department* mathDept = uni.addDepartment("BBA");

    // Create courses
    Course course1("OOPs");
    Course course2("Physics");

    // Add courses to departments
    csDept->addCourse(&course1);
    mathDept->addCourse(&course2);

    // Create students and instructors
    Student s1("Ayesha"), s2("Muattar");
    Instructor i1("Miss Asra Masood"), i2("Tahir Akram");

    // Assign instructors and students
    course1.assignInstructor(&i1);
    course1.addStudent(&s1);
    course1.addStudent(&s2);

    course2.assignInstructor(&i2);
    course2.addStudent(&s2);

    // Print details
    uni.printDepartments();
    csDept->printCourses();
    course1.printInfo();

    return 0;
}
