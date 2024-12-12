//problem to find gcd(greatest common divisor) or hcf(highest common factor) 

#include<iostream>
#include<vector>
using namespace std;

//naive approach 
// int gcd(vector<int> vec1, vector<int> vec2){
//     int ans=1;
//     for(int i=0; i<vec1.size(); i++){
//         for(int j=0; j<vec2.size(); j++){
//             if(vec1[i]==vec2[j]){
//                 ans = ans * vec1[i];
//                 vec2[j]=-1;
//                 break;
//             }
//         }
//     }

//     return ans;
// }

// vector<int> div(int n){
//     vector<int> ans;
//     int i=2;
//     while(n!=1){
//         if(n%i==0){
//             ans.push_back(i);
//             n=n/i;
//         }
//         else{
//             i++;
//         }
//     }

//     return ans;
// }

// int main(){
//     int a=24, b=72;

//     vector<int> adiv = div(a);
//     for(int i=0; i<adiv.size(); i++){
//         cout<<adiv[i]<<" ";
//     }cout<<endl;

//     vector<int> bdiv = div(b);
//     for(int i=0; i<bdiv.size(); i++){
//         cout<<bdiv[i]<<" ";
//     }cout<<endl;

//     int gcdnum = gcd(adiv, bdiv);
//     cout<<"gcd is for given numbers is : "<<gcdnum;

//     return 0;
// }

//euclid algorithm - O(log(min(a,b)))
int euclidalgo(int a, int b){
    while(a>0 && b>0){
        if(a>=b){
            a=a%b; // can also use subtraction but modulo is more efficient in time complexity
        }
        else{
            b=b%a;
        }
    }

    return (a>0)? a : b;
}

int main(){
    int a=24, b=72;
    
    int gcdans = euclidalgo(a,b);
    cout<<"gcd by eculid algo is : "<<gcdans<<endl;

    //note - formula to find lcm
    int lcm = (a*b) / gcdans;
    cout<<"lcm for given two numbers is : "<<lcm<<endl;

    return 0;
}