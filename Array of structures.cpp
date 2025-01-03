#include <iostream>
using namespace std;

// Define a structure to store student information
struct Student {
    string name;
    int age;
    float grade;
};

int main() {
    int n;

    // Ask the user for the number of students
    cout << "Enter the number of students: ";
    cin >> n;

    // Declare an array of structures
    Student students[n];

    // Input student details
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for student " << i + 1 << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Age: ";
        cin >> students[i].age;
        cout << "Grade: ";
        cin >> students[i].grade;
        cout << endl;
    }

    // Output the details of the students
    cout << "Student Information:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Student " << i + 1 << ": " << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "Grade: " << students[i].grade << endl;
        cout << endl;
    }

    return 0;
}
