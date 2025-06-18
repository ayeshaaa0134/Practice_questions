#include <iostream>
#include <string>
namespace Genre {
struct Book {
std::string title;
Book(std::string t) : title(t) {}
};
void describe(const Book& b) {
std::cout << "Genre Book: " << b.title << std::endl;
}
}
namespace Section {
struct Book {
std::string section;
Book(std::string s) : section(s) {}
};
void describe(const Book& b) {

std::cout << "Section Book: " << b.section << std::endl;
}
}
void describe(...) {
std::cout << "Unknown Book\n";
}
using Genre::Book;
using Section::describe;
int main() {
Book b1("1984");
Section::Book b2("History");
std::cout << "Part A:" << std::endl;
describe(b1); // Which describe?
std::cout << "\nPart B:" << std::endl;
describe(b2); // Which describe?
std::cout << "\nPart C:" << std::endl;
::describe(5); // Fall to ellipsis?
}
