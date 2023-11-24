#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
using namespace std;

class Details {
private:
    int account_num;
    string user;
    string password;    
    double balance;

public:
    Details(int acc_num,string username,string pwd, double initial_balance)
        : account_num(acc_num),user{username}, password(pwd), balance(initial_balance) {}

   
    string get_password()const{return password;}
    string get_user()const{return user;}
    int get_accnum()const{return account_num;};
    double get_balance()const{return balance;}

    void displayAccountInfo() {
        cout << "Account Information for " << user << ":" << endl;
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

class Accounts{
private:
    vector<Details> account;

public:
    void add_acc(int accnum,string user,string pass,double intial_b){
         account.push_back(Details{accnum,user,pass,intial_b});
    }

    bool accnum_check(int input)const{
        for(int i=0;i<account.size();i++){
            if(account.at(i).get_accnum()==input){
                return true;
            }
        }
        return false;
    }
    bool pass_check(int acc,string pass){
        for(int i=0;i<account.size();i++){
            if(account.at(i).get_accnum()==acc){
                if(pass==account.at(i).get_password())
                  return true;
            }
        }
        return false;
    }
    void deposit(int acc,double depo){
        for(int i=0;i<account.size();i++){
            if(account.at(i).get_accnum()==acc){
                account.at(i).deposit(depo);
                break;
            }
        }
    }
    void withdraw(int acc,double with){
        
        for(int i=0;i<account.size();i++){
            if(account.at(i).get_accnum()==acc){
                account.at(i).withdraw(with);
                break;
            }
        }
    }

    void display(int acc){
         for(int i=0;i<account.size();i++){
            if(account.at(i).get_accnum()==acc){
                account.at(i).displayAccountInfo();
            }
    }
    }
    
    
};

int main() {
    
    Accounts my_accounts; 

    bool condition{true};
    do{ 
    int input;
    cout<<"Enter\n(1) To Login\n(2) To open Account \n";
    cin>>input;
    if(input==1){
        int accnum;
        cout<<"Enter your account number: ";
        cin>>accnum;
        if(my_accounts.accnum_check(accnum)){   
        string pass;     
        cout << "Enter your password: " << endl;
        cin>>pass;
        if(my_accounts.pass_check(accnum,pass)){
           cout<<"Authentication successful. Welcome!\n";        
        
        
        double tempamount;
        int option;
        cout<<"Enter\n(1)----> To display the amount\n(2)----> To deposit money\n(3)-----> To withdraw money\n(4)---->To Quit";
        cout<<endl;

        cin>>option;

        if(option==1){
            my_accounts.display(accnum);
            cout<<"\n";
            cout<<"Thanks :)"<<endl;
        }
        else if (option==2){
            cout<<"Enter the Amount you want to deposit\n";
            cin>>tempamount;
            my_accounts.deposit(accnum,tempamount);
            cout<<"\n";
            my_accounts.display(accnum);

        }
        else if(option==3){
            cout<<"Enter the Amount You want to withdraw\n";
            cin>>tempamount;
            my_accounts.withdraw(accnum,tempamount);
            cout<<"\n";
             my_accounts.display(accnum);

        }
        else if(option==4){
            cout<<"Exiting Program!!";
            condition=false;

        }
        else{
            cout<<" Enter Valid input."<<endl;
        }
     
    }
    
    else
    {
        cout << "Authentication failed. Exiting program." << endl;
    }
    }else{
        cout<<"Account not fount!\n";
        cout<<"Enter Y to create new account or N to exit: \n";
        char input;
        cin>>input;

        if('Y'==toupper(input)){
        int accnum;
        string user;
        string password;
        cout<<"Enter username and account number with a space: ";
       cin>>user>>accnum;

        cout<<"Enter password: ";
        cin>>password;

        double balance;
        cout<<"Set Initial balance: ";
        cin>>balance;

        my_accounts.add_acc(accnum,user,password,balance);
        }
        else{
            cout<<"Exiting Program";
            condition=false;
        }
    }
    }else if(input==2){
        int accnum;
        string user;
        string password;
        cout<<"Enter username and account number with a space: ";
        cin>>user>>accnum;

        cout<<"Enter password: ";
        cin>>password;

        double balance;
        cout<<"Set Initial balance: ";
        cin>>balance;

        my_accounts.add_acc(accnum,user,password,balance);

    }
    }while(condition);
   

    return 0;
}
