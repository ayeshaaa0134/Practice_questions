#include <iostream>
using namespace std;
class Complex {     
    private:
    int real, imag;
    public:
    Complex(){
        real=0;
        imag=0;
    }
    Complex(int r, int i){
        real=r;
        imag=i;
    }
    void print(){
        cout<<real<<"+"<<imag <<"i"<<endl;
    }

    Complex operator +(Complex c){

Complex temp;
temp.real=real+c.real;
temp.imag=imag+c.imag;
return temp;
    }
};

 int main (){
    Complex c1(2,3);
    Complex c2(2,6);
    Complex c22(2,6);
    Complex c3;
    c3=c2+c1+c22;   //c3=c2.add(c1)

 c3.print();
 
    return 0;
 }