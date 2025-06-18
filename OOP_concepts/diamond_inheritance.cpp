#include <iostream>
using namespace std;
class Base {
public:
Base() { cout << "Base::ctor\n"; }
virtual void identify() { cout << "Base::identify\n"; }
virtual ~Base() { cout << "Base::dtor\n"; }
};
class Left : virtual public Base {
public:
Left() { cout << "Left::ctor\n"; }
void identify() override { cout << "Left::identify\n"; }
~Left() override { cout << "Left::dtor\n"; }
};
class Right : virtual public Base {
public:
Right() { cout << "Right::ctor\n"; }
void identify() override { cout << "Right::identify\n"; }
~Right() override { cout << "Right::dtor\n"; }
};
class Bottom : public Left, public Right {
public:
Bottom() { cout << "Bottom::ctor\n"; }

void identify() override { cout << "Bottom::identify\n"; }
~Bottom() override { cout << "Bottom::dtor\n"; }
};
void callIdentify(Base b) {
b.identify(); // slicing!
}
int main() {
Bottom b;
callIdentify(b); // call through copy (sliced)
Base* ptr = new Bottom;
ptr->identify(); // virtual call
delete ptr;
return 0;
}
