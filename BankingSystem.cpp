//Banking System
#include<iostream>
#include<iomanip>
using std::cout;
using std::cin;
using std::string;

void showbalance(double balance);
double deposit();
double withdraw(double balance);

int main(){
    int choice;
    double balance=0;

    do{
    cout<<"******************\n";
    cout<<"enter the choice:\n";
    cout<<"1. show balance\n";
    cout<<"2. deposit money\n";
    cout<<"3. withdraw money\n";
    cout<<"4. exit\n";
    cout<<"******************\n";
    cin>>choice;

    std::cin.clear();
    fflush(stdin);

    switch(choice){
        case 1:showbalance(balance);
                break;
        case 2:balance+=deposit();
                showbalance(balance);
                break;
        case 3:balance-=withdraw(balance);
                showbalance(balance);
                break;
        case 4:cout<<"thanks for visiting!!";
                break;
        default:cout<<"invalid input!!\n";
    }
    }while(choice!=4);
    
    return 0;
}

void showbalance(double balance){
    cout<<"your balance is : Rs "<<std::setprecision(2)<<std::fixed<<balance<<"\n";
}
double deposit(){
    int amount=0;
    cout<<"enter the amount to depoist in your account : ";
    cin>>amount;

    if(amount>=0){
        return amount;
    }
    else{
        cout<<"invalid amount to deposit!!\n";
        return 0;
    }
    
}
double withdraw(double balance){
    int amount;
    cout<<"enter the amount to withdraw from your account : ";
    cin>>amount;

    if(amount>balance){
        cout<<"oops insufficient funds!!!\n";
        return 0;
    }
    else if(amount<0){
        cout<<"invalid amount to be withdrawn\n";
        return 0;
    }
    else{
        return amount;
    }
    
}
