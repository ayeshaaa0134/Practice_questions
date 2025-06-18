#include <iostream>
using namespace std;
class Logger {
public:
void log(int x) { cout << "log(int): " << x << "\n"; }

void log(double x) { cout << "log(double): " << x << "\n"; }
template<typename... Args>
void log(Args... args) { cout << "log(Args...): count = " << sizeof...(args) << "\n"; }
};
int main() {
Logger l;
l.log(5); // A
l.log(3.14); // B
l.log("Hello"); // C
l.log(1, 2, 3); // D
l.log(true, 'c'); // E
l.log(3.0f); // F
return 0;
}
