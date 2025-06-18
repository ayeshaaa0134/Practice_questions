#include <iostream>
#include <vector>
#include <type_traits>
#include <cctype>
#include <numeric>
template<typename T, typename Enable = void>
class Analyzer {
std::vector<T> data;
public:
void add(T val) {
data.push_back(val);
}
T compute() const {
return std::accumulate(data.begin(), data.end(), T{});
}
};
// Specialization for char type
template<>
class Analyzer<char> {
std::string chars;
public:
void add(char c) {
chars += std::toupper(c);
}
std::string compute() const {
return { chars.rbegin(), chars.rend() };
}
};
// Partial specialization for floating-point types
template<typename T>
class Analyzer<T, typename std::enable_if<std::is_floating_point<T>::value>::type> {

std::vector<T> data;
public:
void add(T val) {
data.push_back(val);
}
T compute() const {
if (data.empty()) return 0;
return *std::min_element(data.begin(), data.end()) * 2;
}
};
int main() {
Analyzer<int> a1;
a1.add(4); a1.add(6);
std::cout << a1.compute() << " ";
Analyzer<char> a2;
a2.add('x'); a2.add('y');
std::cout << a2.compute() << " ";
Analyzer<double> a3;
a3.add(3.5); a3.add(1.2);
std::cout << a3.compute();
}
