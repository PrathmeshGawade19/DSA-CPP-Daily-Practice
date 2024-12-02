//four sum problem

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for (int i = 0; i < arr.size(); i++) {
            if (i > 0 && arr[i] == arr[i - 1]) { // imp case 1
                continue;
            }

            for (int j = i + 1; j < arr.size();) {
                int p = j + 1, q = arr.size() - 1;
                while (p < q) {
                    long long sum = (long long)arr[i] + (long long)arr[j] +
                                    (long long)arr[p] + (long long)arr[q];
                    if (sum < target)
                        p++;
                    if (sum > target)
                        q--;
                    if (sum == target) {
                        vector<int> trip = {arr[i], arr[j], arr[p], arr[q]};
                        ans.push_back(trip);
                        p++, q--;
                        while (p < q && arr[p] == arr[p - 1]) { // imp case 2
                            p++;
                        }
                    }
                }

                j++; // imp case 3
                while (j < arr.size() && arr[j] == arr[j - 1]) {
                    j++;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;

    vector<vector<int>> ans;
    ans = sol.fourSum(arr, target);

    int r = ans.size();
    int c = ans[0].size();

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
