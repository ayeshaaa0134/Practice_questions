#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

class BankAccount {
protected:
    std::string accountHolder;
    double balance;
    static int totalAccounts;

    void validateNonNegative(double val, const std::string& argName) {
        if (val < 0) {
            throw std::invalid_argument(argName + " cannot be negative.");
        }
    }

public:
    BankAccount() : accountHolder(""), balance(0.0) {
        totalAccounts++;
    }

    BankAccount(std::string holder, double bal) : accountHolder(holder), balance(0.0) {
        validateNonNegative(bal, "Initial balance");
        balance = bal;
        totalAccounts++;
    }

    BankAccount(const BankAccount& other) : accountHolder(other.accountHolder), balance(other.balance) {
        totalAccounts++;
    }

    virtual ~BankAccount() {
        totalAccounts--;
    }

    std::string getAccountHolder() const {
        return accountHolder;
    }

    double getBalance() const {
        return balance;
    }

    void setAccountHolder(std::string holder) {
        accountHolder = holder;
    }

    void setBalance(double bal) {
        validateNonNegative(bal, "Balance");
        balance = bal;
    }

    virtual double calculateInterest() const = 0;

    static int getTotalAccounts() {
        return totalAccounts;
    }

    bool transferFunds(BankAccount& target, double amount) {
        try {
            validateNonNegative(amount, "Transfer amount");
            if (balance < amount) {
                std::cerr << "Error: Insufficient funds for transfer from " << accountHolder << "." << std::endl;
                return false;
            }
            this->balance -= amount;
            target.setBalance(target.getBalance() + amount);
            return true;
        } catch (const std::invalid_argument& e) {
            std::cerr << "Transfer Error: " << e.what() << std::endl;
            return false;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const BankAccount& acc);
};

int BankAccount::totalAccounts = 0;

std::ostream& operator<<(std::ostream& os, const BankAccount& acc) {
    os << "Account Holder: " << acc.accountHolder
       << ", Balance: " << acc.balance;
    return os;
}

class SavingsAccount : public BankAccount {
private:
    double interestRate;
    int withdrawalCount;

public:
    SavingsAccount() : BankAccount(), interestRate(0.0), withdrawalCount(0) {}

    SavingsAccount(std::string holder, double bal, double rate, int wCount = 0)
        : BankAccount(holder, bal), interestRate(0.0), withdrawalCount(wCount) {
        validateNonNegative(rate, "Interest rate");
        interestRate = rate;
    }

    SavingsAccount(const SavingsAccount& other)
        : BankAccount(other), interestRate(other.interestRate), withdrawalCount(other.withdrawalCount) {}

    double getInterestRate() const {
        return interestRate;
    }

    void setInterestRate(double rate) {
        validateNonNegative(rate, "Interest rate");
        interestRate = rate;
    }

    int getWithdrawalCount() const {
        return withdrawalCount;
    }

    void setWithdrawalCount(int count) {
        validateNonNegative(static_cast<double>(count), "Withdrawal count");
        withdrawalCount = count;
    }

    double calculateInterest() const override {
        return balance * (interestRate / 100.0);
    }

    friend std::ostream& operator<<(std::ostream& os, const SavingsAccount& acc);
};

std::ostream& operator<<(std::ostream& os, const SavingsAccount& acc) {
    os << static_cast<const BankAccount&>(acc)
       << ", Interest Rate: " << acc.interestRate
       << "%, Withdrawal Count: " << acc.withdrawalCount;
    return os;
}

class CheckingAccount : public BankAccount {
private:
    double transactionFee;
    int transactionCount;

public:
    CheckingAccount() : BankAccount(), transactionFee(0.0), transactionCount(0) {}

    CheckingAccount(std::string holder, double bal, double fee, int tCount = 0)
        : BankAccount(holder, bal), transactionFee(0.0), transactionCount(tCount) {
        validateNonNegative(fee, "Transaction fee");
        transactionFee = fee;
    }

    CheckingAccount(const CheckingAccount& other)
        : BankAccount(other), transactionFee(other.transactionFee), transactionCount(other.transactionCount) {}

    double getTransactionFee() const {
        return transactionFee;
    }

    void setTransactionFee(double fee) {
        validateNonNegative(fee, "Transaction fee");
        transactionFee = fee;
    }

    int getTransactionCount() const {
        return transactionCount;
    }

    void setTransactionCount(int count) {
        validateNonNegative(static_cast<double>(count), "Transaction count");
        transactionCount = count;
    }

    double calculateInterest() const override {
        return 0.0;
    }

    double getEffectiveBalance() const {
        double effectiveBal = balance - (transactionFee * transactionCount);
        return effectiveBal > 0 ? effectiveBal : 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const CheckingAccount& acc);
};

std::ostream& operator<<(std::ostream& os, const CheckingAccount& acc) {
    os << static_cast<const BankAccount&>(acc)
       << ", Transaction Fee: " << acc.transactionFee
       << ", Transaction Count: " << acc.transactionCount
       << " (Effective Balance: " << acc.getEffectiveBalance() << ")";
    return os;
}

template <typename T>
T* compareBalances(T* account1, T* account2) {
    if (!account1 && !account2) return nullptr;
    if (!account1) return account2;
    if (!account2) return account1;

    if (account1->getBalance() > account2->getBalance()) {
        return account1;
    } else if (account2->getBalance() > account1->getBalance()) {
        return account2;
    } else {
        return account1;
    }
}

void printAccountSummary(const BankAccount& account) {
    std::cout << "\n--- Account Summary ---" << std::endl;
    std::cout << "Account Holder: " << account.getAccountHolder() << std::endl;
    std::cout << "Current Balance: " << account.getBalance() << std::endl;

    const CheckingAccount* checkingAcc = dynamic_cast<const CheckingAccount*>(&account);
    if (checkingAcc) {
        std::cout << "Effective Balance (after fees): " << checkingAcc->getEffectiveBalance() << std::endl;
    }

    std::cout << "Calculated Interest: " << account.calculateInterest() << std::endl;
    std::cout << "-----------------------" << std::endl;
}

int main() {
    std::cout << "Total accounts initially: " << BankAccount::getTotalAccounts() << std::endl;

    SavingsAccount sav1("Alice Smith", 1000.0, 2.5);
    std::cout << "\nCreated SavingsAccount: " << sav1 << std::endl;
    printAccountSummary(sav1);

    CheckingAccount chk1("Bob Johnson", 500.0, 1.5, 2);
    std::cout << "\nCreated CheckingAccount: " << chk1 << std::endl;
    printAccountSummary(chk1);

    std::cout << "Total accounts after creation: " << BankAccount::getTotalAccounts() << std::endl;

    std::cout << "\n--- Interest Calculation ---" << std::endl;
    std::cout << "SavingsAccount Interest: " << sav1.calculateInterest() << std::endl;
    std::cout << "CheckingAccount Interest: " << chk1.calculateInterest() << std::endl;

    std::cout << "\n--- Exception Handling (setBalance) ---" << std::endl;
    try {
        sav1.setBalance(-100.0);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "SavingsAccount balance after failed attempt: " << sav1.getBalance() << std::endl;

    std::cout << "\n--- Fund Transfer ---" << std::endl;
    std::cout << "Before transfer: " << std::endl;
    std::cout << "Sav1: " << sav1 << std::endl;
    std::cout << "Chk1: " << chk1 << std::endl;

    std::cout << "\nAttempting to transfer $150 from Sav1 to Chk1..." << std::endl;
    if (sav1.transferFunds(chk1, 150.0)) {
        std::cout << "Transfer successful!" << std::endl;
    } else {
        std::cout << "Transfer failed." << std::endl;
    }

    std::cout << "After transfer: " << std::endl;
    std::cout << "Sav1: " << sav1 << std::endl;
    std::cout << "Chk1: " << chk1 << std::endl;

    std::cout << "\nAttempting to transfer $1000 from Sav1 to Chk1 (insufficient funds)..." << std::endl;
    if (sav1.transferFunds(chk1, 1000.0)) {
        std::cout << "Transfer successful (unexpected)!" << std::endl;
    } else {
        std::cout << "Transfer failed as expected (insufficient funds)." << std::endl;
    }
    std::cout << "Sav1: " << sav1 << std::endl;

    std::cout << "\nAttempting to transfer -$50 from Chk1 to Sav1..." << std::endl;
    if (chk1.transferFunds(sav1, -50.0)) {
        std::cout << "Transfer successful (unexpected)!" << std::endl;
    } else {
        std::cout << "Transfer failed as expected (invalid amount)." << std::endl;
    }
    std::cout << "Chk1: " << chk1 << std::endl;

    std::cout << "\n--- Comparing Balances ---" << std::endl;
    BankAccount* richerAccount = compareBalances(static_cast<BankAccount*>(&sav1), static_cast<BankAccount*>(&chk1));
    if (richerAccount) {
        std::cout << "Account with more balance: " << richerAccount->getAccountHolder() << " (" << richerAccount->getBalance() << ")" << std::endl;
    }

    std::cout << "\n--- Displaying Summaries (Dynamic Dispatch) ---" << std::endl;
    printAccountSummary(sav1);
    printAccountSummary(chk1);

    std::cout << "\nTotal accounts before end of main: " << BankAccount::getTotalAccounts() << std::endl;

    return 0;
}