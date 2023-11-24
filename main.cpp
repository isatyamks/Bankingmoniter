#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class Transaction {
public:
    string type; // "Deposit" or "Withdrawal"
    double amount;
    double balance_after_transaction;

    Transaction(string t, double a, double b) : type(t), amount(a), balance_after_transaction(b) {}
};

class BankingMonitorSystem {
private:
    string username;
    string password;
    int accountNumber;
    double balance;
    vector<Transaction> transactionHistory;

public:
    BankingMonitorSystem(string uname, string pwd, int accNumber, double initial_balance)
        : username(uname), password(pwd), accountNumber(accNumber), balance(initial_balance) {}

    bool authenticate(string entered_password) {
        return entered_password == password;
    }

    void displayAccountInfo() {
        cout << "Account Information for " << username << " (Account Number: " << accountNumber << "):" << endl;
        cout << "Balance: Rs" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back(Transaction("Deposit", amount, balance));
        cout << "Deposit successful. New balance: Rs" << fixed << setprecision(2) << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push_back(Transaction("Withdrawal", amount, balance));
            cout << "Withdrawal successful. New balance: Rs" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        }
    }

    void printTransactionHistory() {
        cout << "Transaction History for " << username << " (Account Number: " << accountNumber << "):" << endl;
        for (const Transaction& transaction : transactionHistory) {
            cout << transaction.type << " of Rs" << fixed << setprecision(2) << transaction.amount;
            cout << ", Balance after transaction: Rs" << fixed << setprecision(2) << transaction.balance_after_transaction << endl;
        }
    }
};

int main() {
    int account_number;
    cout << "Enter the account Number: ";
    cin >> account_number;


    BankingMonitorSystem userAccount("Satyam_kumar", "satyam9835.",9835100179, 50000.0);


    
    string enteredPassword;
    cout << "Enter your password: ";
    cin >> enteredPassword;

    if (userAccount.authenticate(enteredPassword)) {
        cout << "Authentication successful. Welcome!" << endl;

        int option;

        do {
            cout << "Enter\n(1)----> To display the amount\n(2)----> To deposit money\n(3)-----> To withdraw money\n(4)-----> To print transaction history\n(0)-----> To exit" << endl;
            cin >> option;

            switch (option) {
                case 1:
                    userAccount.displayAccountInfo();
                    break;
                case 2:
                    double tempamount;
                    cout << "Enter the Amount you want to deposit: ";
                    cin >> tempamount;
                    userAccount.deposit(tempamount);
                    break;
                case 3:
                    cout << "Enter the Amount You want to withdraw: ";
                    cin >> tempamount;
                    userAccount.withdraw(tempamount);
                    break;
                case 4:
                    userAccount.printTransactionHistory();
                    break;
                case 0:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Error: Invalid option." << endl;
            }

        } while (option != 0);
    } else {
        cout << "Authentication failed. Exiting program." << endl;
    }

    return 0;
}
