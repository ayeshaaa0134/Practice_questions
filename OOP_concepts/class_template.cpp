#include <iostream>
#include <vector>
#include <algorithm>
template<typename T>
class BaseContainer {
protected:
std::vector<T> data;
public:
virtual void insert(T x) {
data.push_back(x);
}
virtual T process() const {
if (data.empty()) return T{};
return *std::max_element(data.begin(), data.end());
}
virtual ~BaseContainer() = default;
};
template<>
class BaseContainer<std::string> {

std::vector<std::string> words;
public:
void insert(std::string s) {
words.push_back(s);
}
std::string process() const {
std::string out;
for (auto& w : words)
out += w;
return out;
}
};
int main() {
BaseContainer<int>* b1 = new BaseContainer<int>();
b1->insert(10); b1->insert(2);
std::cout << b1->process() << " ";
BaseContainer<std::string>* b2 = new BaseContainer<std::string>();
b2->insert("Hi"); b2->insert("There");
std::cout << b2->process();
delete b1;
delete b2;
}
