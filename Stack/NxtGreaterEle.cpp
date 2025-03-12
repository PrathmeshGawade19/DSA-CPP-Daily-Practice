//find next greatest element
//The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> num1 = {2,4};
    vector<int> num2 = {1,2,3,4};
    stack<int> s;
    unordered_map<int, int> ans;
    vector<int> v;

    for (int i = num2.size() - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= num2[i]) {
            s.pop();
        }

        ans[num2[i]] = s.empty() ? -1 : s.top();

        s.push(num2[i]);
    }

    for (int num : num1) {
        cout << num << ":" << ans[num] << endl;
        v.push_back(ans[num]);
    }

    cout<<"In vector : ";
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;


    return 0;
}