#include <iostream>
 #include <cstring> 
using namespace std; 
 
class Student { private: 
    char *name; public: 
    Student(const char* n) { 
         name = new char[strlen(n) + 1]; 
        strcpy(name, n); 
    } 
 
    void display() { cout << "Student Name: " << name << endl; } 
 
    ~Student() { delete[] name; } 
}; 
 	int main() { 
    Student s1("Alice"); 
    Student s2 = s1;  
    s1.display();   
    s2.display();  
    return 0; 
} 
 
