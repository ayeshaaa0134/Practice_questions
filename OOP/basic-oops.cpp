#include <iostream>
#include <string>
using namespace std;

// Question 1: 
class Person {
private:
    string name;
    int age;

public:
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    // Question 2: 
    void printInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Question 3: 
class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

    // Question 4: 
    bool isBalanceNegative() {
        return balance < 0;
    }

public:
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance && !isBalanceNegative()) {
            balance -= amount;
        } else {
            cout << "Insufficient balance or negative balance." << endl;
        }
    }

    void displayBalance() {
        cout << "Current Balance: " << balance << endl;
    }
};

// Question 5: 
class Car {
private:
    string model;
    string manufacturer;
    int speed;

public:
    void accelerate(int increment) {
        speed += increment;
    }

    void brake(int decrement) {
        speed -= decrement;
    }
};

int main() {
    
    Person p;
    p.setName("Ayesha siddiqa");
    p.setAge(20);
    p.printInfo();

    BankAccount acc;
    acc.deposit(1000);
    acc.withdraw(500);
    acc.displayBalance();

    Car car;
    car.accelerate(50);
    car.brake(20);

    return 0;
}