//hamming weight (count of 1 bits in binary form)
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
    cout<<"binary form is :"<<ans<<endl;

    int count=0;
    while(ans!=0){
        if(ans%10==1){
            count++;
        }
        ans=ans/10;
    }
    cout<<"hamming weight (count of 1 bits in binary form:)"<<count;

    return 0;
}