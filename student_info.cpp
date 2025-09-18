#include <iostream>
#include <string>
using namespace std;
struct Student {
    string name;
    int age;
    string id;
    string department;
    string major;
};

void inputStudentInfo(Student &student) {
    cout << "Enter student name: ";
    cin >> student.name;
    cout << "Enter student age: ";
    cin >> student.age;
    cout << "Enter student ID: ";
    cin >> student.id;
    cout << "Enter student department: ";
    cin >> student.department;
    cout << "Enter student major: ";
    cin >> student.major;
}

void displayStudentInfo(const Student &student) {
    cout << "Student Information: " << endl;
    cout << "Name: " << student.name << endl;
    cout << "Age: " << student.age << endl;
    cout << "ID: " << student.id << endl;
    cout << "Department: " << student.department << endl;
    cout << "Major: " << student.major << endl;
    cout << "------------------ " <<endl;

}

void searchStudentByID(const Student students[], int size, const string &id) {
    for (int i = 0; i < size; ++i) {
        if (students[i].id == id) {
            displayStudentInfo(students[i]);
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}

void updateStudentInfo(Student &student) {
    cout << "Updating information for student ID: " << student.id << endl;
    inputStudentInfo(student);
}

void deleteStudentByID(Student students[], int &size, const string &id) {
    for (int i = 0; i < size; ++i) {
        if (students[i].id == id) {
            for (int j = i; j < size - 1; ++j) {
                students[j] = students[j + 1];
            }
            --size;
            cout << "Student with ID " << id << " has been deleted." << endl;
            return;
        }
    }
    cout << "Student with ID " << id << " not found." << endl;
}




int main()
{
    const int MAX_STUDENTS = 100;
    Student students[MAX_STUDENTS];
    int studentCount = 0;

    int choice;
    do {
        cout << "Menu: " << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by ID" << endl;
        cout << "4. Update Student Information" << endl;
        cout << "5. Delete Student by ID" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (studentCount < MAX_STUDENTS) {
                    inputStudentInfo(students[studentCount]);
                    ++studentCount;
                } else {
                    cout << "Student list is full!" << endl;
                }
                break;
            case 2:
                for (int i = 0; i < studentCount; ++i) {
                    displayStudentInfo(students[i]);
                }
                break;
            case 3: {
                string id;
                cout << "Enter student ID to search: ";
                cin >> id;
                searchStudentByID(students, studentCount, id);
                break;
            }
            case 4: {
                string id;
                cout << "Enter student ID to update: ";
                cin >> id;
                for (int i = 0; i < studentCount; ++i) {
                    if (students[i].id == id) {
                        updateStudentInfo(students[i]);
                        break;
                    }
                }
                break;
            }
            case 5: {
                string id;
                cout << "Enter student ID to delete: ";
                cin >> id;
                deleteStudentByID(students, studentCount, id);
                break;
            }
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}