#include "header.h"

//-----------Constructor--------------
BankAccount::BankAccount(double balance){
    cout<<"~ Account Creation in processes. Please wait!!!! (BankAccount class Constr Calling)"<<endl;
    if(balance<0){
        throw "\033[31mBalance can't be negative. Please try again\033[0m";      
    }
    this->balance= balance;
    cout<<"Account Successfully Created"<<endl;
}

//Get Balance
double BankAccount::getBal(){
        return balance;
    } 
//Amount dedication form balance
void  BankAccount::debit(double amount){
    balance -=amount;
}
BankAccount::~BankAccount(){
    cout<<"~ BankAccount class Distructor Calling"<<endl;
} 

//-------------User CLass----------------- 
User::User(string n, double b){
        cout<<"# USer class Construcor Calling"<<endl;
        name=n;
        account= new BankAccount(b);
    }
User::~User(){
        delete account;
        cout<<"# User Class Destructor Calling"<<endl;
    }

//-----------Regular User----------------
//Constructor
RegularUser::RegularUser(string n, double b):User(n,b){
        cout<<"\033[32m* Regular\033[0m USer class Construcor Calling"<<endl;
    }
//Withdraw class
void RegularUser::withdraw(double amount){
        if(amount > account->getBal()){
            throw "Withdraw denied : !Typed Ammoun is greater then balance";
        }
        account->debit(amount);
        cout<<"\n"<<amount<<"Rs withdraw successfully from account"<<endl;
        cout<<"Remaining Balance: "<<account->getBal()<<endl;
    }
//Destructor
 RegularUser::~RegularUser(){
        cout<<"\n* \033[32mRegularUser\033[0m User class destructor calling"<<endl;
    }
//------------------------------------
//----------Premium User-----------
//constructor
PremiumUser::PremiumUser(string n, double b, double l):User(n,b){
        cout<<"\033[34m/ Premium\033[0m USer class Construcor Calling"<<endl;
        loanLimit= l;
    }
//withdraw function
void PremiumUser:: withdraw(double amount){
        if(amount<= account->getBal()){
            account->debit(amount);
            cout<<"\n"<<amount<<"Rs withdraw successfully from account"<<endl;
            cout<<"Remaining Balance: "<<account->getBal()<<endl;
        }
        else if(amount<= account->getBal() + loanLimit){
            double loan= amount-loanLimit;
            account->debit(account->getBal());
            loanLimit-= loan;
            cout<<"\n>>> Loan approved"<<endl;
            cout<<amount<<"Rs withdraw successfully from account"<<endl;
            cout<<"Remaining Loan Limit: "<<loan<<endl;
        }
        else{
            throw "Withdraw denied : (loan limit exceed)";
        }
    }
//Destructor
PremiumUser::~PremiumUser(){
        cout<<"\n\033[34m/ Premium\033[0m User class destructor calling"<<endl;
    }
