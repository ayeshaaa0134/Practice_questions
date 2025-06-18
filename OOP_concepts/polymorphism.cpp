#include <iostream>
using namespace std;
class A {
public:
A() { cout << "A::ctor\n"; }
virtual void f() { cout << "A::f\n"; }
void g() { cout << "A::g\n"; }
virtual ~A() { cout << "A::dtor\n"; }
};
class B : public A {
public:
B() { cout << "B::ctor\n"; }
void f() override { cout << "B::f\n"; }
void g() { cout << "B::g\n"; }
~B() override { cout << "B::dtor\n"; }
};
class C : public B {
public:
C() { cout << "C::ctor\n"; }
void f() override { cout << "C::f\n"; }
void g() { cout << "C::g\n"; }
~C() override { cout << "C::dtor\n"; }
};
int main() {
A* ptr = new C;
ptr->f(); // virtual
ptr->g(); // non-virtual

delete ptr;
return 0;
}
