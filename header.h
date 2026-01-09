#include <iostream>
using namespace std;

//BankAccount Class 
class BankAccount{
private:
    double balance;
public:
    //Constructor
    BankAccount(double);
    //Get Balance
    double getBal();
    //Amount dedication form balance
    void debit(double amount);
    //Get Load Credit if you are premium user 
    ~BankAccount();
};

//---------User class ---------
class User{
protected:
    string name;
    BankAccount *account;
public:
    User(string n, double b);
    //Pure Virtual withdraw function
    virtual void withdraw(double amount) = 0;
    virtual ~User();
};

//--------------Regular user-----------
class RegularUser: public User{
public:
    RegularUser(string n, double b);
    //Withdraw money
    void withdraw(double amount);
    ~RegularUser();
};
//--------Premium User claass----------
class PremiumUser: public User{
private:
    double loanLimit;
public:
    PremiumUser(string n, double b, double l);
    //withdraw function
    void withdraw(double amount);
    //Destructor
    ~PremiumUser();
};