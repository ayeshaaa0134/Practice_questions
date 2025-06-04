#include <iostream>
#include <cstring>
using namespace std;

// 1. Default Constructor & Getters/Setters
class Car {
public:
    string model;
    int year;
    Car() : model("Unknown"), year(2000) {}
    void setModel(string m) { model = m; }
    void setYear(int y) { year = y; }
    string getModel() { return model; }
    int getYear() { return year; }
};

// 2. Parameterized Constructor & Object Manipulation
class Laptop {
public:
    string brand;
    int RAM;
    double price;
    Laptop(string b, int r, double p) : brand(b), RAM(r), price(p) {}
    string getBrand() { return brand; }
    int getRAM() { return RAM; }
    double getPrice() { return price; }
};

// 3. Copy Constructor Implementation
class Point {
public:
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
    Point(const Point &p) : x(p.x), y(p.y) {}
};

// 4. Constructor Overloading
class Mobile {
public:
    string brand;
    int storage;
    int battery;
    Mobile() : brand("Generic"), storage(64), battery(3000) {}
    Mobile(string b, int s, int bat) : brand(b), storage(s), battery(bat) {}
    Mobile(const Mobile &m) : brand(m.brand), storage(m.storage), battery(m.battery) {}
};

// 5. Dynamic Memory Allocation in Constructor & Copy Constructor
class Book {
public:
    char *title;
    Book(const char *t) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }
    Book(const Book &b) {
        title = new char[strlen(b.title) + 1];
        strcpy(title, b.title);
    }
    ~Book() { delete[] title; }
};

// 6. Returning Objects from a Function
class Rectangle {
public:
    double length, width;
    Rectangle(double l, double w) : length(l), width(w) {}
    Rectangle(const Rectangle &r) : length(r.length), width(r.width) {}
};
Rectangle createRectangle(double l, double w) { return Rectangle(l, w); }

// 7. Constructor with Default Arguments
class TV {
public:
    string brand;
    int size;
    double price;
    TV(string b = "Sony", int s = 42, double p = 499.99) : brand(b), size(s), price(p) {}
};

// 8. Using Getter for Constant Objects
class Circle {
public:
    double radius;
    Circle(double r) : radius(r) {}
    double getRadius() const { return radius; }
};

// 9. Modifying an Object Using Setter After Construction
class Person {
public:
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() { return name; }
    int getAge() { return age; }
};

// 10. Initializing Constant Member Using Constructor
class CarWithMaxSpeed {
public:
    string model;
    const int maxSpeed;
    CarWithMaxSpeed(string m, int max) : model(m), maxSpeed(max) {}
};

int main() {
    // 1. Car
    cout<<"Question 1"<<endl;
    Car myCar;
    myCar.setModel("Toyota");
    myCar.setYear(2022);
    cout << "Car: " << myCar.getModel() << " " << myCar.getYear() << endl;

    // 2. Laptop
    cout<<"Question 2"<<endl;
    Laptop laptop1("Dell", 16, 1200.5);
    Laptop laptop2("HP", 8, 900.3);
    cout << "Laptop1: " << laptop1.getBrand() << " " << laptop1.getRAM() << "GB " << laptop1.getPrice() << "$" << endl;
    cout << "Laptop2: " << laptop2.getBrand() << " " << laptop2.getRAM() << "GB " << laptop2.getPrice() << "$" << endl;
    
    // 3. Point
    cout<<"Question 3"<<endl;
    Point p1(5, 10);
    Point p2(p1);
    cout << "Point: " << p2.x << ", " << p2.y << endl;
    
    // 4. Mobile
    cout<<"Question 4"<<endl;
    Mobile m1, m2("Samsung", 128, 5000), m3(m2);
    cout << "Mobile: " << m3.brand << " " << m3.storage << "GB " << m3.battery << "mAh" << endl;
    
    // 5. Book
    cout<<"Question 5"<<endl;
    Book b1("C++ Programming"), b2(b1);
    cout << "Book title: " << b2.title << endl;
    
    // 6. Rectangle
    cout<<"Question 6"<<endl;
    Rectangle r = createRectangle(10, 5);
    cout << "Rectangle: " << r.length << " x " << r.width << endl;
    
    // 7. TV
    cout<<"Question 7"<<endl;
    TV tv1, tv2("Samsung", 55, 799.99);
    cout << "TV1: " << tv1.brand << " " << tv1.size << "" << endl;
    cout << "TV2: " << tv2.brand << " " << tv2.size << "" << endl;
    
    // 8. Circle
    cout<<"Question 8"<<endl;
    const Circle c(7.5);
    cout << "Circle radius: " << c.getRadius() << endl;
    
    // 9. Person
    cout<<"Question 9"<<endl;
    Person person("Alice", 25);
    person.setName("Bob");
    person.setAge(30);
    cout << "Person: " << person.getName() << " " << person.getAge() << endl;
    
    // 10. CarWithMaxSpeed
    cout<<"Question 10"<<endl;
    CarWithMaxSpeed carMax("Ferrari", 350);
    cout << "Car: " << carMax.model << " Max Speed: " << carMax.maxSpeed << "km/h" << endl;
    
    return 0;
}
