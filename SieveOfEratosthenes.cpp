//problem is to find number of prime numbers less than or equal to n

#include<iostream>
#include<vector>
using namespace std;

//naive approach - O(n^2)
// int main(){
//     int n = 10;
//     int count = 1;

//     for(int i=3; i<=n; i++){
//         int flag=0;
//         for(int j=2; j<i; j++){
//             if(i%j==0){
//                 flag=1;
//             }
//         }
//         if(flag==0){
//             count++;
//         }
//     }

//     cout<<count<<endl;
//     return 0;
// }

//sieve of erstotheres - O(n∗log(log(n)))
int main(){
    int n = 30;
    vector<bool> prime (n+1,1);

    for (int p = 2; p * p <= n; p++) {
        // If it is the next prime, mark all its multiples as false, as they are composite and not prime.
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    cout << "The prime numbers under 30 are:" << endl;

    for (int p = 2; p <= n; p++){
        if (prime[p] == true){
            cout << p << " ";
        }
    }

    return 0;
}