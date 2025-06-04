#include <iostream>
#include <vector>
using namespace std;
class Professor {
    public:
        std::string name;
        Professor(std::string n) : name(n) {}
    };
    
    class Department {
    private:
        std::vector<Professor*> professors; // Aggregation (weak ownership)
    public:
        void addProfessor(Professor* p) { professors.push_back(p); }
        ~Department() { /* Doesn't delete professors! */ }
    };