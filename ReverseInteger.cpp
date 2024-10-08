#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the integer : ";
    cin>>n;

    int ans=0,digit;
    while(n!=0){
        digit=n%10;
        if(ans>INT32_MAX/10 || ans<INT32_MIN/10){
            cout<<"invalid for 32 bit integer";
            return 0;
        }
        ans=(ans*10)+digit;
        n=n/10;
    }

    cout<<"reverse is : "<<ans;
    

    return 0;
}


