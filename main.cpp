#include <iostream>
#include "BankAccount.h"

void showMenu() {
    std::cout << "\nBank Account Management System\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Check Balance\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    BankAccount *account = nullptr;
    int choice;
    std::string accountNumber, accountHolderName;
    double initialBalance, amount;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter Account Number: ";
                std::cin >> accountNumber;
                std::cout << "Enter Account Holder Name: ";
                std::cin.ignore(); // To ignore the leftover newline character
                std::getline(std::cin, accountHolderName);
                std::cout << "Enter Initial Balance: ";
                std::cin >> initialBalance;
                account = new BankAccount(accountNumber, accountHolderName, initialBalance);
                std::cout << "Account created successfully!\n";
                break;

            case 2:
                if (account) {
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> amount;
                    account->deposit(amount);
                } else {
                    std::cout << "No account found. Create an account first.\n";
                }
                break;

            case 3:
                if (account) {
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> amount;
                    account->withdraw(amount);
                } else {
                    std::cout << "No account found. Create an account first.\n";
                }
                break;

            case 4:
                if (account) {
                    std::cout << "Account Number: " << account->getAccountNumber() << std::endl;
                    std::cout << "Account Holder Name: " << account->getAccountHolderName() << std::endl;
                    std::cout << "Balance: " << account->getBalance() << std::endl;
                } else {
                    std::cout << "No account found. Create an account first.\n";
                }
                break;

            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                delete account;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
