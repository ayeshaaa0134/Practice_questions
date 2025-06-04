#include<iostream>
#include <vector>
using namespace std;
class Patient; // Forward declaration

class Doctor {
private:
    std::vector<Patient*> patients; // Association (raw pointer)
public:
    void addPatient(Patient* p) { patients.push_back(p); }
};

class Patient {
private:
    std::vector<Doctor*> doctors; // Association (raw pointer)
public:
    void addDoctor(Doctor* d) { doctors.push_back(d); }
};
int main(){
    return;

}