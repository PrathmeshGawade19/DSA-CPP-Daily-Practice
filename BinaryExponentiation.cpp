//Porgram to calculate Pow(x^n)
//Introduction to concept of Binary Exponentiation
#include<iostream>
#include<math.h>
using namespace std;
int main(){
    //logic1 - 0(n) leds to TLE
    // double x=2;
    // double n=-2;
    // double ncopy=n;

    // if(n<0){
    //     ncopy=-n;
    //     x=1/x;
    // }

    // double xcopy=x;

    // for(int i=0; i<ncopy-1; i++){
    //     x=x*xcopy;
    // }

    // cout<<x<<endl;

    //logic2 - Binary Exponentiation
    int x=5,n=2;

    //base cases
    if(n==0){
        cout<<"1";
    }
    else if(x==0){
        cout<<"0";
    }
    else if(x==1){
        cout<<"1";
    }
    else if(x==-1 && n%2==0){
        cout<<"1";
    }
    else if(x==-1 && n%2!=0){
        cout<<"-1";
    }
    
    long long binform=n;
    
    if(n<0){
        x=1/x;
        binform=-binform;
    }

    double ans=1;

    while(binform>0){
        if(binform%2==1){
            ans=ans*x;
        }
        x=x*x;
        binform=binform/2;
    }

    cout<<ans<<endl;

    return 0;
}