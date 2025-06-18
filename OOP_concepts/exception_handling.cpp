#include <iostream>
#include <exception>
using namespace std;
class BaseException : public exception {
public:
const char* what() const noexcept override { return "BaseException"; }
~BaseException() { cout << "~BaseException\n"; }
};
class DerivedException : public BaseException {
public:
const char* what() const noexcept override { return "DerivedException"; }
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
for (int i = 1; i <= 6; ++i) {
cout << "\n--- Test case " << i << " ---\n";
try {
riskyFunction(i);
}
catch (DerivedException& e) {
cout << "Caught DerivedException: " << e.what() << "\n";
}
catch (BaseException& e) {
cout << "Caught BaseException: " << e.what() << "\n";
}
catch (AnotherException&) {
cout << "Caught AnotherException\n";
}
catch (const char* msg) {
cout << "Caught const char*: " << msg << "\n";
}
catch (...) {
cout << "Caught unknown
