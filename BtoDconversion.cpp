//binary to decimal conversion
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"enter the binary number :";
    cin>>num;

    int digit,place=1,ans=0;
    while(num!=0){
        digit=num%10;
        if(digit==1){
            ans=ans+place;
        }
        place=place*2;
        num=num/10;    
    }

    cout<<"decimal representation : "<<ans;

    return 0;
}