#include <iostream>
#include <fstream>
#include <cstring>
#include "string.h"
#include <SFML/Graphics.hpp>

const int MAX_STUDENTS = 100;
const int MAX_COURSES = 50;
const int MAX_COURSE_CAPACITY = 30;
const int MAX_SUBJECTS = 5;
const int MAX_STUDENT_COURSES = 5;

class Student {
public:
    std::string name;
    int roll_num;
    int age;
    std::string contact;
    std::string courses[MAX_STUDENT_COURSES];
    bool attendance[MAX_SUBJECTS];
    int marks[MAX_SUBJECTS];

    // Additional methods for Student
};

class Course {
public:
    std::string code;
    std::string name;
    std::string instructor;
    int credits;
    int capacity;
    Student* students[MAX_COURSE_CAPACITY];

    // Additional methods for Course
};

class System {
private:

public:
    System() {
        // ... (Existing code)

        // Initialize SFML window
        window.create(sf::VideoMode(800, 600), "Student Management System");
        window.setFramerateLimit(60);
    }

    // ... (Existing code)

    void display_students_courses() {
        // Display students and courses in SFML window
        window.clear();

        // Display student information
        for (int i = 0; i < studentCount; ++i) {
            sf::Text text;
            text.setString("Student " + std::to_string(i + 1) + ": " + students[i].name);
            text.setPosition(50, 50 + i * 30);
            window.draw(text);
        }

        // Display course information
        for (int i = 0; i < courseCount; ++i) {
            sf::Text text;
            text.setString("Course " + std::to_string(i + 1) + ": " + courses[i].name);
            text.setPosition(400, 50 + i * 30);
            window.draw(text);
        }

        window.display();
    }

    void run_graphical_interface() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            display_students_courses();
        }
    }
};





    Student students[MAX_STUDENTS];
    Course courses[MAX_COURSES];

    int studentCount = 0;
    int courseCount = 0;

    void load_data() {
        // Load data from the file if available
        std::ifstream file("data.txt");
        if (file.is_open()) {
            // Read data and initialize students and courses
            while (file >> students[studentCount].name >> students[studentCount].roll_num >> students[studentCount].age
                >> students[studentCount].contact) {
                // Read student's courses, attendance, and marks
                for (int i = 0; i < MAX_STUDENT_COURSES; ++i) {
                    file >> students[studentCount].courses[i];
                }
                for (int i = 0; i < MAX_SUBJECTS; ++i) {
                    file >> students[studentCount].attendance[i];
                }
                for (int i = 0; i < MAX_SUBJECTS; ++i) {
                    file >> students[studentCount].marks[i];
                }

                ++studentCount;
                if (studentCount == MAX_STUDENTS) {
                    break;  // Avoid exceeding array bounds
                }
            }

            // Read course information
            while (file >> courses[courseCount].code >> courses[courseCount].name
                >> courses[courseCount].instructor >> courses[courseCount].credits
                >> courses[courseCount].capacity) {

                // Read enrolled students
                for (int i = 0; i < courses[courseCount].capacity; ++i) {
                    int roll_num;
                    file >> roll_num;

                    // Find the student by roll number and enroll them in the course
                    for (int j = 0; j < studentCount; ++j) {
                        if (students[j].roll_num == roll_num) {
                            courses[courseCount].students[i] = &students[j];
                            break;
                        }
                    }
                }

                ++courseCount;
                if (courseCount == MAX_COURSES) {
                    break;  // Avoid exceeding array bounds
                }
            }
        }
        file.close();
    }

    void save_data() {
        // Save data to the file
        std::ofstream file("data.txt");
        if (file.is_open()) {
            // Save student information
            for (int i = 0; i < studentCount; ++i) {
                file << students[i].name << " " << students[i].roll_num << " " << students[i].age << " "
                    << students[i].contact << " ";

                // Save student's courses, attendance, and marks
                for (int j = 0; j < MAX_STUDENT_COURSES; ++j) {
                    file << students[i].courses[j] << " ";
                }
                for (int j = 0; j < MAX_SUBJECTS; ++j) {
                    file << students[i].attendance[j] << " ";
                }
                for (int j = 0; j < MAX_SUBJECTS; ++j) {
                    file << students[i].marks[j] << " ";
                }

                file << "\n";
            }

            // Save course information
            for (int i = 0; i < courseCount; ++i) {
                file << courses[i].code << " " << courses[i].name << " "
                    << courses[i].instructor << " " << courses[i].credits << " " << courses[i].capacity << " ";

                // Save enrolled students
                for (int j = 0; j < courses[i].capacity; ++j) {
                    file << courses[i].students[j]->roll_num << " ";
                }

                file << "\n";
            }
        }
        file.close();
    }

public:
    System() {
        load_data();
    }

    ~System() {
        save_data();
    }

    void display_main_menu() {
        std::cout << "Main Menu\n";
        std::cout << "1- Enroll a student\n";
        std::cout << "2- Course Registration\n";
        std::cout << "3- Attendance\n";
        std::cout << "4- Marks\n";
        std::cout << "5- Course Withdraw\n";
        std::cout << "6- Exit\n";
    }

    char get_user_input(const std::string& message) {
        std::cout << message;
        char choice;
        std::cin >> choice;
        return choice;
    }

    void perform_action(char choice) {
        switch (choice) {
        case '1':
            // Handle student enrollment
            enroll_student();
            break;
        case '2':
            // Handle course registration
            register_course();
            break;
        case '3':
            // Handle attendance
            mark_attendance();
            break;
        case '4':
            // Handle marks
            assign_marks();
            break;
        case '5':
            // Handle course withdrawal
            withdraw_course();
            break;
        case '6':
            // Save data and exit
            exit(0);
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    }

    void enroll_student() {
        // Implementation for enrolling a student
    }

    void register_course() {
        // Implementation for course registration
    }

    void mark_attendance() {
        // Implementation for marking attendance
    }

    void assign_marks() {
        // Implementation for assigning marks
    }

    void withdraw_course() {
        // Implementation for course withdrawal
    }

    // Additional methods for handling submenus and user interactions
};

int main() {
    System system;

    while (true) {
        system.display_main_menu();
        char user_choice = system.get_user_input("Press 1 to 6 to select an option: ");
        system.perform_action(user_choice);
    }

    return 0;
}
