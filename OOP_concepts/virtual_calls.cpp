#include <iostream>
using namespace std;
class Base {
public:
Base() { cout << "Base::ctor\n"; call(); }
virtual void call() { cout << "Base::call\n"; }
virtual ~Base() { cout << "Base::dtor\n"; call(); }
};
class Derived : public Base {
public:
Derived() { cout << "Derived::ctor\n"; }
void call() override { cout << "Derived::call\n"; }
~Derived() override { cout << "Derived::dtor\n"; }
};
int main() {
Base* b = new Derived;
delete b;
return 0;
}
