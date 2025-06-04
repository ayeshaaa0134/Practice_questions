#include <iostream> 
using namespace std; 
 
class Counter { private:     int value; public: 
    Counter(int v) : value(v) {} 
 
    void operator++() { value += 10; }   // Prefix overload (no argument passed)
    void operator++(int) { value *= 2; } // Postfix overload (takes one argument)
 
    void display() { cout << "Value: " << value << endl; } }; 
 int main() {
Counter c(5);
++c;     //Prefix increment +=10 =15
c++;  //Postfix  increment *=2=30
c.display();     return 0;
}
 
