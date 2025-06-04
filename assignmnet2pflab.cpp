#include <iostream>
#include <cmath>
using namespace std;

void fib() {
    int n1 = 1, n2 = 1, next;
    cout << "fib Sequence: ";
    cout << n1 << " " << n2 << " ";
    for (int i = 3; i <= 25; ++i) {
        next = n1 + n2;
        cout << next << " ";
        n1 = n2;
        n2 = next;
    }
    cout << endl;
}

double fact(int n) {
    double fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

double power(double base, int exp) {
    double result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

double sinP(double x) {
    double result = 0;
    for (int i = 1; i <= 9; i += 2) {
        result += power(x, i) / fact(i);
    }
    return result;
}

double sinPN(double x) {
    double result = 0;
    for (int i = 1; i <= 9; i += 2) {
        if ((i / 2) % 2 == 0)
            result += power(x, i) / fact(i);
        else
            result -= power(x, i) / fact(i);
    }
    return result;
}

int main() {
    cout<<"Q:4"<<endl;
    fib();
    cout<<"Q:5"<<endl;
    cout << "Sin(x) :" << endl;
    for (double x = 0; x <= 1; x += 0.1) {
        cout << "sin(" << x << ") = " << sinP(x) << endl;
    }
    cout << "Sin(x) with PN terms:" << endl;
    for (double x = 0; x <= 1; x += 0.1) {
        cout << "sin(" << x << ") = " << sinPN(x) << endl;
    }
    return 0;
}
