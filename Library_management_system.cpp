#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100;
const int MAX_MEMBERS = 50;
const int MAX_BORROWED = 5;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isAvailable;

public:
    Book() {}

    Book(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        isAvailable = true;
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    bool getAvailability() const { return isAvailable; }

    void setAvailability(bool status) {
        isAvailable = status;
    }

    void display() const {
        cout << "Title: " << title << ", Author: " << author
             << ", ISBN: " << isbn
             << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

class Loan {
private:
    Book* borrowedBook;
    string dueDate;

public:
    Loan() {
        borrowedBook = nullptr;
    }

    Loan(Book* book, string due) {
        borrowedBook = book;
        dueDate = due;
    }

    Book* getBook() const { return borrowedBook; }
    string getDueDate() const { return dueDate; }

    void display() const {
        if (borrowedBook != nullptr) {
            borrowedBook->display();
            cout << "Due Date: " << dueDate << endl;
        }
    }
};

class LibraryMember {
private:
    string memberID;
    string name;
    Loan borrowedBooks[MAX_BORROWED];
    int borrowedCount;

public:
    LibraryMember() {}

    LibraryMember(string id, string n) {
        memberID = id;
        name = n;
        borrowedCount = 0;
    }

    string getName() const { return name; }
    string getMemberID() const { return memberID; }

    void borrowBook(Book &book, string dueDate) {
        if (!book.getAvailability()) {
            cout << "Sorry, \"" << book.getTitle() << "\" is not available.\n";
            return;
        }

        if (borrowedCount >= MAX_BORROWED) {
            cout << "Cannot borrow more than " << MAX_BORROWED << " books.\n";
            return;
        }

        book.setAvailability(false);
        borrowedBooks[borrowedCount] = Loan(&book, dueDate);
        borrowedCount++;

        cout << name << " borrowed \"" << book.getTitle() << "\" successfully.\n";
    }

    void returnBook(string isbn) {
        for (int i = 0; i < borrowedCount; ++i) {
            if (borrowedBooks[i].getBook()->getISBN() == isbn) {
                borrowedBooks[i].getBook()->setAvailability(true);
                cout << name << " returned \"" << borrowedBooks[i].getBook()->getTitle() << "\".\n";

                // Shift remaining books
                for (int j = i; j < borrowedCount - 1; ++j) {
                    borrowedBooks[j] = borrowedBooks[j + 1];
                }
                borrowedCount--;
                return;
            }
        }
        cout << "Book with ISBN " << isbn << " not found in borrowed list.\n";
    }

    void displayBorrowedBooks() const {
        cout << name << "'s Borrowed Books:\n";
        if (borrowedCount == 0) {
            cout << "None\n";
        } else {
            for (int i = 0; i < borrowedCount; ++i) {
                borrowedBooks[i].display();
            }
        }
    }
};

// Helper function
void searchBooks(Book books[], int size, string keyword) {
    cout << "Search Results for \"" << keyword << "\":\n";
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (books[i].getTitle().find(keyword) != string::npos ||
            books[i].getAuthor().find(keyword) != string::npos) {
            books[i].display();
            found = true;
        }
    }
    if (!found) {
        cout << "No books found.\n";
    }
}


int main() {
    Book books[MAX_BOOKS] = {
        Book("XYZ Book", "ABC Writer ", "123"),
        Book("1984", "ABC Book", "456"),
        Book("LMN Book", "NST Writer", "789")
    };

    int bookCount = 3;

    LibraryMember member("M001", "Ayesha");

    searchBooks(books, bookCount, "Hassan");

    member.borrowBook(books[1], "2025-04-20"); 
    member.borrowBook(books[1], "2025-04-22"); 

    member.displayBorrowedBooks();

    member.returnBook("456");
    member.displayBorrowedBooks();

    return 0;
}
