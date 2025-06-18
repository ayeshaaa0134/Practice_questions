#include <iostream>
#include <exception>
using namespace std;
class BaseException : public exception {
public:
virtual const char* what() const noexcept override { return "BaseException"; }
~BaseException() { cout << "~BaseException\n"; }
};
class DerivedException : public BaseException {
string msg = "DerivedException";
public:
const char* what() const noexcept override { return msg.c_str(); }
~DerivedException() { cout << "~DerivedException\n"; }
};
class AnotherException {
public:
~AnotherException() { cout << "~AnotherException\n"; }
};

void riskyFunction(int code) noexcept(false) {
if (code == 1) throw DerivedException();
if (code == 2) throw BaseException();
if (code == 3) throw AnotherException();
if (code == 4) throw "C-string exception";
if (code == 5) throw 3.14;
cout << "No exception thrown\n";
}
int main() {
try {
try {
riskyFunction(1);
}
catch (BaseException e) { // **slicing happens here**
cout << "Caught BaseException: " << e.what() << "\n";
throw;
}
}
catch (DerivedException& e) {
cout << "Caught DerivedException: " << e.what() << "\n";
}
catch (BaseException& e) {
cout << "Caught Base again: " << e.what() << "\n";
}
}

