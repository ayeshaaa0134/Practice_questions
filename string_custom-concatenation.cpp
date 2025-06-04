#include <iostream>
#include <cstring>

class MyString {
private:
    char* str;

public:
    // Default constructor
    MyString() {
        str = new char[1];
        str[0] = '\0';
    }

    // Parameterized constructor
    MyString(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Copy constructor
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Destructor
    ~MyString() {
        delete[] str;
    }

    // Overloaded + operator
    MyString operator+(const MyString& other) const {
        char* newStr = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        MyString result(newStr);
        delete[] newStr;
        return result;
    }

    // Overloaded += operator
    MyString& operator+=(const MyString& other) {
        char* newStr = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(newStr, str);
        strcat(newStr, other.str);
        delete[] str;
        str = newStr;
        return *this;
    }

    // Overloaded == operator
    bool operator==(const MyString& other) const {
        return strcmp(str, other.str) == 0;
    }

    // Overloaded != operator
    bool operator!=(const MyString& other) const {
        return !(*this == other);
    }

    // Display function
    void display() const {
        std::cout << str << std::endl;
    }
};

// Test the MyString class
int main() {
    MyString s1("Hello");
    MyString s2(" World");

    MyString s3 = s1 + s2;
    s3.display();  // Output: Hello World

    s1 += s2;
    s1.display();  // Output: Hello World

    if (s1 == s3)
        std::cout << "s1 and s3 are equal\n";
    else
        std::cout << "s1 and s3 are not equal\n";

    if (s1 != s2)
        std::cout << "s1 and s2 are different\n";
    else
        std::cout << "s1 and s2 are the same\n";

    return 0;
}
