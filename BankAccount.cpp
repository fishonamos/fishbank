#include "BankAccount.h"
#include <iostream>

BankAccount::BankAccount(std::string accountNumber, std::string accountHolderName, double initialBalance)
    : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(initialBalance) {}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

std::string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposited: " << amount << std::endl;
    } else {
        std::cout << "Invalid amount. Deposit failed." << std::endl;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew: " << amount << std::endl;
        return true;
    } else {
        std::cout << "Invalid amount or insufficient funds. Withdrawal failed." << std::endl;
        return false;
    }
}
