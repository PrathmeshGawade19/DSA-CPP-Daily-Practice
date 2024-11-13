/*Example 1:

Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
Example 2:

Input: num = 4009
Output: 13
Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        vector<int> sortnum;

        int count = 0;
        while(count<4){
            sortnum.push_back(num%10);
            num/=10;
            count++;
        }

        sort(sortnum.begin(),sortnum.end());

        
        int new1 = (sortnum[0] * 10) + sortnum[2];
        int new2 = (sortnum[1] * 10) + sortnum[3];
        int ans = new1 + new2;
        return ans;
    }
};


int main(){
    Solution sol;
    int num = 2932;
    
    cout<<sol.minimumSum(num);

    return 0;
}