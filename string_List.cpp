#include <iostream>
#include <string>
#include <stdexcept> // For std::out_of_range
using namespace std;

class StringList {
private:
    string* strArray; // Dynamic array of strings
    int capacity;     // Current maximum capacity
    int size;         // Current number of strings stored

public:
    // Constructor
    StringList(int initialCapacity) {
        if (initialCapacity <= 0) {
            throw invalid_argument("Initial capacity must be positive.");
        }
        capacity = initialCapacity;
        size = 0;
        strArray = new string[capacity];
    }

    // Destructor
    ~StringList() {
        delete[] strArray;
    }

    // Add a string to the list
    void addString(const string& str) {
        if (size == capacity) {
            // Resize the array (double the capacity)
            int newCapacity = capacity * 2;
            string* newArray = new string[newCapacity];

            // Copy old elements to new array
            for (int i = 0; i < size; ++i) {
                newArray[i] = strArray[i];
            }

            // Free old array and update pointer
            delete[] strArray;
            strArray = newArray;
            capacity = newCapacity;
        }

        // Add the new string
        strArray[size++] = str;
    }

    // Get string at a specific index
    string getString(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range.");
        }
        return strArray[index];
    }

    // Get current size of the list
    int getSize() const {
        return size;
    }
};
int main() {
    StringList myList(2);

    myList.addString("Hello");
    myList.addString("World");
    myList.addString("!");

    for (int i = 0; i < myList.getSize(); ++i) {
        cout << myList.getString(i) << " ";
    }

    return 0;
}
