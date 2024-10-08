//Power of 2
#include<iostream>
#include<math.h>
using namespace std;

class Solution {
    public:
    bool isPowerOfTwo(int n) {
        int ans=1;
        for(int i=0; i<=30; i++){
            int ans=pow(2,i);
            if(ans==n){
                return true;
            }
            if(ans<INT32_MAX/2)
            ans=ans*2;
        }
        return false;
        
    }
};

int main(){
    Solution sol;
    bool ans = sol.isPowerOfTwo(32);
    cout << ans; 

    return 0;
}