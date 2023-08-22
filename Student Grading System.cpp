#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<string> studentNames;
    vector<double> studentGrades;
    string name;
    double grade;

    cout << "Student Grade Management Program" << endl;
    cout << "--------------------------------" << endl;

    while (true) {
        cout << "Enter student name (or 'exit' to finish): ";
        cin >> name;
        
        if (name == "exit") {
            break;
        }
        
        cout << "Enter " << name << "'s grade: ";
        cin >> grade;

        studentNames.push_back(name);
        studentGrades.push_back(grade);
    }

    if (studentNames.empty()) {
        cout << "No student data entered." << endl;
        return 0;
    }

    double sum = 0;
    double highestGrade = studentGrades[0];
    double lowestGrade = studentGrades[0];

    for (size_t i = 0; i < studentGrades.size(); ++i) {
        double grade = studentGrades[i];
        sum += grade;
        if (grade > highestGrade) {
            highestGrade = grade;
        }
        if (grade < lowestGrade) {
            lowestGrade = grade;
        }
    }

    double average = sum / studentGrades.size();

    cout << "Student Grade Summary" << endl;
    cout << "---------------------" << endl;
    cout << "Average Grade: " << average << endl;
    cout << "Highest Grade: " << highestGrade << endl;
    cout << "Lowest Grade: " << lowestGrade << endl;

    return 0;
}

