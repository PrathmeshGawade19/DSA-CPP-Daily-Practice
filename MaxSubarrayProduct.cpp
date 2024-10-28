#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& arr) {

        //yaha max or min dono track karo
        //agar number negative hai to swap karo max and min which basically  ensures that the new curMax will be the higher product
        int maxpro = arr[0], curMax = arr[0], curMin = arr[0];
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < 0) {
                swap(curMax, curMin); 
            }
            curMax = max(arr[i], curMax * arr[i]);
            curMin = min(arr[i], curMin * arr[i]);

            maxpro = max(maxpro, curMax);
        }

        return maxpro;
    }
};

int main(){
    vector<int> arr = {-2,0,-1};

    Solution sol;
    int maxproduct=sol.maxProduct(arr);
    cout<<maxproduct;

    return 0;
}