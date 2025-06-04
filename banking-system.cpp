#include <iostream> 
using namespace std; 

class BankAccount { 
private: 
    int accountNo; 
    double balance; 
    string interestRate; 
public: 
    BankAccount(int n) { 
        accountNo = n; 
        balance = 20000; 
        interestRate = "5%"; 
    } 
    
    void getInfo() { 
        cout << "Account Number is: " << accountNo << endl; 
        cout << "It's Balance is: " << balance << endl; 
        cout << "It's Interest Rate is: " << interestRate << endl << endl; 
    } 
    
    void deposit(double n) {
        if (n > 0) {
            balance += n; 
            cout << "Amount Deposited!!" << endl; 
            cout << "Now, Your Balance Is: " << balance << endl << endl;
        }
        else {
            cout << "INVALID AMOUNT!!!" << endl << endl;
        }
    } 
    
    void withdraw(double n) { 
        if (balance >= n && n > 0) {  //  '>=' to allow withdrawing entire balance
            balance -= n; 
            cout << "Amount Withdrawn!!" << endl; 
            cout << "Now, Your Balance Is: " << balance << endl << endl; 
        }
        else {
            cout << "INVALID AMOUNT!!!\nENTER AGAIN!!" << endl << endl;
        }
    } 
}; 

int main() { 
    int number; 
    cout << "Enter your account no.(roll no. here) : "; 
    cin >> number; 
    BankAccount acc1(number); 
    acc1.getInfo(); 
    
    while(true) { 
        cout << "Enter 1 to deposit cash" << endl; 
        cout << "Enter 2 to withdraw cash" << endl; 
        cout << "Enter 3 to exit" << endl;  
        int n; 
        cout << "Enter your choice: "; 
        cin >> n; 
        
        if(n == 1) { 
            double deposit; 
            cout << "Enter your amount to deposit: "; 
            cin >> deposit; 
            acc1.deposit(deposit); 
        } 
        else if(n == 2) { 
            double withdraw; 
            cout << "Enter your amount to withdraw: "; 
            cin >> withdraw; 
            acc1.withdraw(withdraw); 
        } 
        else if(n == 3) {  
            cout << "Thank you for banking with us!" << endl;
            break;
        }
        else {
            cout << "INVALID CHOICE!!!" << endl << endl;
        } 
    } 
    
    return 0; 
}