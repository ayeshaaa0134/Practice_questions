 #include <iostream>
 using namespace std;
 class Test {
    public:
        int j;
        static int i;
    
        Test() { i += 5; j = i; }
    
        Test(int p) { i += p; j = p + i; }
    
        Test(const Test &t) { i += t.j + t.i; j = t.j; }
    
        ~Test() { i -= 2; }
    };
    
    int Test::i = 100;
    
    int main() {
        Test obj1(20);
        Test obj2;
        Test obj3(obj1);
        cout << obj1.j << " " << obj1.i << endl;
        cout << obj2.j << " " << obj2.i << endl;
        cout << obj3.j << " " << obj3.i << endl;
        return 0;
    }
    