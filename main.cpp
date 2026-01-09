#include "header.h"

int main(){
    //------Regular User Testing
    try{
        User* user1= new RegularUser("Ahmad", 5000);
        try{
          user1->withdraw(4000); 
        }
        catch (const char*n){
            cout<<n<<endl;
        }
         delete user1;
    }
    catch (const char*n){
        cout<<n<<endl;
    }
    cout<<"\n-----------------------------------------------------------------------------------"<<endl;

    //-----Premium User Testing
    try{
        User *user2= new PremiumUser("Kamal",40000,30000);
        try{
          user2->withdraw(50000); 
        }
        catch (const char*n){
            cout<<n<<endl;
        }
        delete user2;
    }
    catch (const char*n){
        cout<<n<<endl;
    }
    
    return 0;
}
