#include <iostream>
#include <cmath>
using namespace std;

//First Question : Vector3D Class
class Vector3D {
public:
    double x, y, z;

    Vector3D(double xVal, double yVal, double zVal) {
        x = xVal;
        y = yVal;
        z = zVal;
    }

    double magnitude() {
        return sqrt(x * x + y * y + z * z);
    }

    Vector3D add(Vector3D other) {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    void display() {
        cout << "Vector: (" << x << ", " << y << ", " << z << ")\n";
    }
};

// Second Question: Book Class
class Book {
public:
    string title, author, ISBN;
    double price;

    Book(string t, string a, string isbn, double p) {
        title = t;
        author = a;
        ISBN = isbn;
        price = p;
    }

    void display() {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << ", Price: $" << price << "\n";
    }
};

// Third Question : ComplexNumber Class
class ComplexNumber {
public:
    double real, imaginary;

    ComplexNumber(double r, double i) {
        real = r;
        imaginary = i;
    }

    ComplexNumber add(ComplexNumber other) {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber subtract(ComplexNumber other) {
        return ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    ComplexNumber multiply(ComplexNumber other) {
        return ComplexNumber(real * other.real - imaginary * other.imaginary, real * other.imaginary + imaginary * other.real);
    }

    void display() {
        cout << real << " + " << imaginary << "i\n";
    }
};

int main() {
    // Vector3D Test
    cout<<"Question :1"<<endl;
    Vector3D v1(3, 4, 5), v2(1, 2, 3);
    Vector3D v3 = v1.add(v2);
    v1.display();
    v2.display();
    v3.display();
    cout << "Magnitude of v1: " << v1.magnitude() << "\n\n";

    // Book Test
    cout<<"Question :2"<<endl;
    Book books[] = {
        Book("Book1", "Author1", "12345", 10.5),
        Book("Book2", "Author2", "67890", 15.0)
    };

    for (Book b : books) b.display();
    cout << "\n";

    // ComplexNumber Test
    cout<<"Question :3"<<endl;
    ComplexNumber c1(3, 4), c2(1, 2);
    ComplexNumber c3 = c1.add(c2);
    ComplexNumber c4 = c1.subtract(c2);
    ComplexNumber c5 = c1.multiply(c2);
    c1.display();
    c2.display();
    c3.display();
    c4.display();
    c5.display();

    return 0;
}
