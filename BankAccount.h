#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(std::string accountNumber, std::string accountHolderName, double initialBalance);
    
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);
};

#endif
