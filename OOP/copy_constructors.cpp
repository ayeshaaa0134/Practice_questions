#include <iostream>
#include <cstring>

using namespace std;
//Question 1
class Student {
private:
    char* name;
    int* grades;
    int numGrades;

public:
    // Constructor
    Student(const char* n, int* g, int size) {
        numGrades = size;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        grades = new int[numGrades];
        for (int i = 0; i < numGrades; i++) {
            grades[i] = g[i];
        }
    }

    // Copy Constructor (Deep Copy)
    Student(const Student& other) {
        numGrades = other.numGrades;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        grades = new int[numGrades];
        for (int i = 0; i < numGrades; i++) {
            grades[i] = other.grades[i];
        }
    }

    // Destructor
    ~Student() {
        delete[] name;
        delete[] grades;
    }

    // Modify name
    void modifyName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }

    // Display student info
    void display() const {
        cout << "Student: " << name << ", Grades: ";
        for (int i = 0; i < numGrades; i++) {
            cout << grades[i] << " ";
        }
        cout << endl;
    }
};
//Question 2
class TextDocument {
private:
    char* text;

public:
    // Constructor
    TextDocument(const char* content) {
        text = new char[strlen(content) + 1];
        strcpy(text, content);
    }

    // Copy Constructor (Deep Copy)
    TextDocument(const TextDocument& other) {
        text = new char[strlen(other.text) + 1];
        strcpy(text, other.text);
    }

    // Destructor
    ~TextDocument() {
        delete[] text;
    }

    // Modify text
    void modifyText(const char* newText) {
        delete[] text;
        text = new char[strlen(newText) + 1];
        strcpy(text, newText);
    }

    // Display document
    void display() const {
        cout << "Document: " << text << endl;
    }
};

int main() {
    cout<<"Question 1 "<<endl;
    // Testing Student class
    int grades[] = {85, 90, 78};
    Student student1("Alice", grades, 3);
    Student student2 = student1;  // Copy constructor

    cout << "Before modifying student1:\n";
    student1.display();
    student2.display();

    student1.modifyName("Bob");

    cout << "\nAfter modifying student1:\n";
    student1.display();
    student2.display();  

    cout<<"Question 2 "<<endl;
    // Testing TextDocument class
    TextDocument doc1("Hello, world!");
    TextDocument doc2 = doc1;  // Copy constructor

    cout << "\nBefore modifying doc1:\n";
    doc1.display();
    doc2.display();

    doc1.modifyText("Modified text.");

    cout << "\nAfter modifying doc1:\n";
    doc1.display();
    doc2.display(); 

    return 0;
}
