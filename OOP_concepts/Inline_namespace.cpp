#include <iostream>
namespace V1 {
inline namespace Core {
void greet() { std::cout << "Hello from V1::Core\n"; }
}
void show() { std::cout << "Show from V1\n"; }
}
namespace V2 {
void greet() { std::cout << "Hello from V2\n"; }
void show() { std::cout << "Show from V2\n"; }
}
using namespace V1;
// Removed: using V2::show; // this line caused ambiguity
int main() {
std::cout << "Part A:" << std::endl;
greet(); // Calls V1::Core::greet (inline)

std::cout << "\nPart B:" << std::endl;
V1::show(); // Explicit
V2::show(); // Explicit
std::cout << "\nPart C:" << std::endl;
V2::greet();
}
