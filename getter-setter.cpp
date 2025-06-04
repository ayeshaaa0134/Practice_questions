#include <iostream>
using namespace std;

class Ayesha {
private:
string  doubts;
int stresslevels; 
public:
 Ayesha(){   //deafult constuctor
    doubts="";
    stresslevels=0; 
    

 }
 
string  getdoubts () const { return doubts;}
 int getstresslevels () const { return stresslevels;}
 void setdoubts(const string &d){ doubts= d;}
 void setstresslevels( const int &s){ stresslevels =s;}

};

 int main(){
Ayesha today ;
today.setdoubts("Existential crisis");
today.setstresslevels(79);
 cout <<"Doubts: "<<today.getdoubts()<<endl;
 cout <<"StressLevels: "<<today.getstresslevels()<<endl;
    return 0;
 }