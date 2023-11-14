
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankingMonitorSystem {
private:
    string username;
    string password;
    double balance;

public:
    BankingMonitorSystem(string uname, string pwd, double initial_balance)
        : username(uname), password(pwd), balance(initial_balance) {}

    bool authenticate(string entered_password) {
        return entered_password == password;
    }

    void displayAccountInfo() {
        cout << "Account Information for " << username << ":" << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        }
    }
};

int main() {
    BankingMonitorSystem userAccount("Satyam_kumar", "satyam9835.", 50000.0);

    string enteredPassword;
    cout << "Enter your password: ";
    cin >> enteredPassword;

    if (userAccount.authenticate(enteredPassword)) {
        cout << "Authentication successful. Welcome!" << endl;

        userAccount.displayAccountInfo();

        userAccount.deposit(500.0);
        userAccount.withdraw(200.0);
    } else {
        cout << "Authentication failed. Exiting program." << endl;
    }

    return 0;
}

