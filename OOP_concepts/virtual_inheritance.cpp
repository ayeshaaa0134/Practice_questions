#include <iostream>
using namespace std;
class Root {
public:
Root() { cout << "Root::ctor\n"; }
virtual ~Root() { cout << "Root::dtor\n"; }
};
class A : virtual public Root {
public:
A() { cout << "A::ctor\n"; }
virtual ~A() { cout << "A::dtor\n"; }
};
class B : virtual public Root {
public:
B() { cout << "B::ctor\n"; }
virtual ~B() { cout << "B::dtor\n"; }
};
class D : public A {
public:
D() { cout << "D::ctor\n"; }
~D() override { cout << "D::dtor\n"; }
};
class E : public B {
public:
E() { cout << "E::ctor\n"; }
~E() override { cout << "E::dtor\n"; }
};

class F : public D, public E {
public:
F() { cout << "F::ctor\n"; }
~F() override { cout << "F::dtor\n"; }
};
int main() {
Root* ptr = new F;
delete ptr;
return 0;
}
