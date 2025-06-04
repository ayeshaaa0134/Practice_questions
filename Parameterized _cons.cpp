#include <iostream> 
using namespace std; 
 
class Test { 
    public: 
    int x; 
    Test(int val) : x(val) {}     
     void print() const { 
        cout << "x: " << x << endl; 
    } }; 
 int main() {     
const Test t(10);   
 t.print();    
 return 0; 
}
 


