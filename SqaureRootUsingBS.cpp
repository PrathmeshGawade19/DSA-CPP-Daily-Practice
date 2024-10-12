//Program to find sqaure root of number using binary search
#include<iostream>
using namespace std;
int main(){
    int n=37;

    int s=0,e=n,ans;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(mid*mid>n){
            e=mid-1;
        }
        else if(mid*mid<n){
            ans=mid;
            s=mid+1;
        }
        else if(mid*mid==n){
            cout<<"sqaure is :"<<mid<<endl;
            break;
        }
        mid=s+(e-s)/2;
    }

    // Decimal precision
    double increment = 0.1;
    double precise_ans = ans;

    for (int precision = 0; precision < 3; precision++) {  // Iterating for 3 decimal places
        while (precise_ans * precise_ans <= n) {
            precise_ans += increment;
        }
        precise_ans -= increment;  // Overshoot, so subtract last increment
        increment /= 10;
    }

    cout << "Approximate square root: " << precise_ans << endl;
    
    return 0;
}