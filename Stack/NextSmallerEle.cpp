//to find next/first smaller element of every element in given vector

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {2, 1, 4, 3};
    int n = v.size();

    vector<int> ans(n);

    stack<int> s;
    s.push(-1);

    int i = n-1;
    while(i >= 0){
        int curr = v[i];
        while(s.top() >= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);

        i--;
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}