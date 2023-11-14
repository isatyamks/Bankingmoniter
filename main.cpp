#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankingMonitorSystem {
private:
    string username;
    string password;
    double balance;


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

