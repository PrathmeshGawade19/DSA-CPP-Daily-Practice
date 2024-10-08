//decimal to binary conversion
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"enter the decimal number :";
    cin>>num;

    int ans=0,bit,place=1;
    while(num!=0){
        // method 1 
        // bit=num%2;
        // ans=(bit*place)+ans;
        // num=num/2;
        // place=place*10;

        //method 2
        bit=num&1;
        ans=(bit*place)+ans;
        num=num>>1;
        place=place*10;
    }
    cout<<"binary form is :"<<ans;

    return 0;
}