#include <iostream>
#include <string>
using namespace std;
class Printer {
public:
void print(string s = "default") { cout << "print(string): " << s << "\n"; }
template<typename T>
void print(T val) { cout << "print<T>: " << val << "\n"; }
template<>
void print<bool>(bool val) { cout << "print<bool>: " << (val ? "true" : "false") << "\n"; }
};
int main() {
Printer p;
p.print(); // A
p.print("custom"); // B
p.print(123); // C
p.print(true); // D
p.print(3.14); // E
p.print('A'); // F
return 0;
}
