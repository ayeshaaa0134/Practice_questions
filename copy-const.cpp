#include <iostream>
#include <string>
using namespace std;

class Ayesha {
private:
    int scores;
    string subject;

public:
    // Constructors
    Ayesha() { // default constructor 
        scores = 0;
        subject = "";
    }
    
    Ayesha(int scr, string sub) {  // parameterized constructor 
        scores = scr;
        subject = sub;
    }
    
    // copy constructor
    Ayesha(const Ayesha& other) {
        scores = other.scores;
        subject = other.subject;
    }
    
    // Getters
    int getScores() const {
        return scores;
    }
    
    string getSubject() const {
        return subject;
    }
    
    // Setters
    void setScores(const int scr) {
        scores = scr;
    }
    
    void setSubject(const string sub) {
        subject = sub;
    }
    
    // Display function
    void display() const {
        cout << "Subject: " << subject << ", Scores: " << scores << endl;
    }
};

int main() {
    // Example usage:
    Ayesha obj1; // uses default constructor
    Ayesha obj2(95, "Math"); // uses parameterized constructor
    Ayesha obj3(obj2); // uses copy constructor here obj2 is the other object the source , we pss source , and the one whihc we want to intialize cmoes beofre the obj3
    
    // Using setters
    obj1.setSubject("Science");
    obj1.setScores(88);
    
    // Using getters
    cout << "Obj2 subject: " << obj2.getSubject() << endl;
    cout << "Obj2 scores: " << obj2.getScores() << endl;
    
    // Display all objects
    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}