//to perform a^b exponentiation operation
#include<iostream>
using namespace std;
int power(int a, int b);

//naive approach - tc = O(b)
// int main(){
//     int a=2,b=5;
    
//     int i=1, ans=1;
//     while(i<=b){
//         ans = ans * a;
//         i++;
//     }

//     cout<<ans<<endl;
//     return 0;
// }

//optimized approach - O(log n)
//using loops
// Example Execution
// Let a = 2, b = 5:

// 1. b = 5:
//    ans = 1, a = 2 → ans = 1 * 2 = 2, a = 4, b = 2.

// 2. b = 2:
//    ans = 2, a = 4 → ans = 2, a = 16, b = 1.

// 3. b = 1:
//    ans = 2, a = 16 → ans = 2 * 16 = 32, b = 0.

// Final result: ans = 32.

int main() {
    int a = 2, b = 5; 
    int ans = 1;     

    // while (b > 0) {
    //     if (b % 2 == 1) {
    //         ans = ans * a;
    //     }

    //     a = a * a;

    //     b = b / 2; 
    // }
    ans = power(a,b);

    cout << ans << endl;
    return 0;
}

//using recursion
int power(int a, int b){
    if(b==0)
        return 1;
    if(b==1)
        return a;

    int ans = power(a, b/2);
    
    if(b%2==0){
        return ans*ans;
    }
    else{
        return a*ans*ans;
    }
}
