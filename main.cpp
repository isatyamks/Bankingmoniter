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
        cout << "Balance: Rs" << fixed << setprecision(2) << balance << endl;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: Rs" << fixed << setprecision(2) << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: Rs" << fixed << setprecision(2) << balance << endl;
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

    if (userAccount.authenticate(enteredPassword)) 
    {
        cout << "Authentication successful. Welcome!" << endl;

        userAccount.displayAccountInfo();

        int tempamount;
        int option;
        cout<<"Enter\n(1)----> To display the amount\n(2)----> To deposit money\n(3)-----> To withdraw money";
        cout<<endl;

        cin>>option;

        if(option==1){
            userAccount.displayAccountInfo();
            cout<<"\n";
            cout<<"Thanks :)"<<endl;
        }
        else if (option==2){
            cout<<"Enter the Amount you want to deposit\n";
            cin>>tempamount;
            userAccount.deposit(tempamount);
            cout<<"\n";
            userAccount.displayAccountInfo();

        }
        else if(option==3){
            cout<<"Enter the Amount You want to withdraw\n";
            cin>>tempamount;
            userAccount.withdraw(tempamount);
            cout<<"\n";
            userAccount.displayAccountInfo();

        }
        else{
            cout<<" Error 404"<<endl;
        }
    } 
    
    else
    {
        cout << "Authentication failed. Exiting program." << endl;
    }

    return 0;
}
