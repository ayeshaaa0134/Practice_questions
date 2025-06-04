#include <iostream>
#include <fstream>
using namespace std;


struct Student {
    int id;
    char name[30];
    float cgpa;
};

int main() {
  const    int MAX_STUDENTS = 51; 
    Student students[MAX_STUDENTS];
    int count = 0;


    ifstream inputFile("students.txt");
   
   
    while (inputFile >> students[count].id >> students[count].name >> students[count].cgpa) {
        count++;
    }
    inputFile.close();


    cout << "Student Data:" << endl;
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].name << ", CGPA: " << students[i].cgpa << endl;
    }

   
    ofstream outputFile("output_students.txt");
    
    for (int i = 0; i < count; i++) {
        outputFile << students[i].id << " " << students[i].name << " " << students[i].cgpa << endl;
    }
    outputFile.close();

    return 0;
}
