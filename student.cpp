#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a student
class Student {
private:
    int id; // Student ID
    string name; // Student name
    vector<int> courses; // List of courses the student is enrolled in
public:
    // Constructor to initialize a student with an ID and name
    Student(int id, string name) : id(id), name(name) {}

    // Getters for student ID, name, and courses
    int getId() const { return id; }
    string getName() const { return name; }
    vector<int> getCourses() const { return courses; }

    // Method to add a course to the student's course list
    void addCourse(int courseId) { courses.push_back(courseId); }

    // Method to display the student's details
    void displayStudentDetails() const;
};

// Implementation of the displayStudentDetails method
void Student::displayStudentDetails() const {
    cout << "ID: " << id << "\nName: " << name << "\nCourses: ";
    for (int course : courses) {
        cout << course << " ";
    }
    cout << endl;
}

// Class representing a course
class Course {
private:
    int id; // Course ID
    string name; // Course name
public:
    // Constructor to initialize a course with an ID and name
    Course(int id, string name) : id(id), name(name) {}

    // Getters for course ID and name
    int getId() const { return id; }
    string getName() const { return name; }

    // Method to display the course's details
    void displayCourseDetails() const;
};

// Implementation of the displayCourseDetails method
void Course::displayCourseDetails() const {
    cout << "Course ID: " << id << "\nCourse Name: " << name << endl;
}

// Class representing an admin who can manage students and courses
class Admin {
public:
    // Methods to manage students and courses
    void addStudent(vector<Student>& students, int id, string name);
    void deleteStudent(vector<Student>& students, int id);
    void assignCourse(vector<Student>& students, int studentId, int courseId);
    void displayAllStudents(const vector<Student>& students) const;
};

// Implementation of the addStudent method
void Admin::addStudent(vector<Student>& students, int id, string name) {
    students.push_back(Student(id, name));
}

// Implementation of the deleteStudent method
void Admin::deleteStudent(vector<Student>& students, int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getId() == id) {
            students.erase(it);
            break;
        }
    }
}

// Implementation of the assignCourse method
void Admin::assignCourse(vector<Student>& students, int studentId, int courseId) {
    for (auto& student : students) {
        if (student.getId() == studentId) {
            student.addCourse(courseId);
            break;
        }
    }
}

// Implementation of the displayAllStudents method
void Admin::displayAllStudents(const vector<Student>& students) const {
    for (const auto& student : students) {
        student.displayStudentDetails();
    }
}

// Function to display the main menu
void displayMenu() {
    cout << "\nStudent Management System\n";
    cout << "1. Add Student\n";
    cout << "2. Delete Student\n";
    cout << "3. Assign Course to Student\n";
    cout << "4. Display All Students\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Main function
int main() {
    vector<Student> students; // List of students
    vector<Course> courses; // List of courses

    Admin admin; // Admin object to manage students and courses

    // Adding some initial courses
    courses.push_back(Course(101, "Mathematics"));
    courses.push_back(Course(102, "Physics"));

    int choice; // Variable to store the user's menu choice
    while (true) {
        displayMenu(); // Display the menu
        cin >> choice; // Get the user's choice

        if (choice == 1) {
            // Add a student
            int id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore(); // To ignore the newline character left by previous input
            getline(cin, name);
            admin.addStudent(students, id, name);
        } else if (choice == 2) {
            // Delete a student
            int id;
            cout << "Enter Student ID to Delete: ";
            cin >> id;
            admin.deleteStudent(students, id);
        } else if (choice == 3) {
            // Assign a course to a student
            int studentId, courseId;
            cout << "Enter Student ID: ";
            cin >> studentId;
            cout << "Enter Course ID: ";
            cin >> courseId;
            admin.assignCourse(students, studentId, courseId);
        } else if (choice == 4) {
            // Display all students
            admin.displayAllStudents(students);
        } else if (choice == 5) {
            // Exit the program
            break;
        } else {
            // Invalid choice
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
