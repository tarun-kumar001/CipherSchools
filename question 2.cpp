#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks[3];
};

int main() {
    Student* student = new Student;

    cout << "Enter student's name: ";
    getline(cin, student->name);

    cout << "Enter roll number: ";
    cin >> student->rollNumber;
    

    cout << "Enter marks for 3 subjects: ";
    for (int i = 0; i < 3; ++i) {
        cin >> student->marks[i];
    }

    float average = 0;
    for (int i = 0; i < 3; ++i) {
        average += student->marks[i];
    }
    average /= 3;

    cout << "\nStudent Details:" << endl;
    cout << "Name: " << student->name << endl;
    cout << "Roll Number: " << student->rollNumber << endl;
    cout << "Marks: ";
    for (int i = 0; i < 3; ++i) {
        cout << student->marks[i] << " ";
    }
    cout << "\nAverage Marks: " << average << endl;

    delete student;

    return 0;
}
