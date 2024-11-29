#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set<int>s;
        int n = grid.size();
        int a,b;
        int expsum = 0,actualsum = 0;
        for(int i=0; i<n ; i++){
            for(int j=0; j<n; j++){
                actualsum = actualsum + grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        expsum = (n*n) * (n*n+1)/2;
        b = expsum + a - actualsum;
        ans.push_back(b);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>grid = {{1,3},{2,2}};
    vector<int>ans;
    ans = sol.findMissingAndRepeatedValues(grid);

    for(int i:ans){
        cout<<i<<" ";
    }

    return 0;
}