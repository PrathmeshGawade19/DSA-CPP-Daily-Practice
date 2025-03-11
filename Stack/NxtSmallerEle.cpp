//to find next smaller element in an array for every element
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

//brute force
// int main(){
//     vector<int> v = {2, 1, 4, 3};
//     vector<int> ans;

//     for(int i=0; i<v.size(); i++){
//         int flag = 0;
//         for(int j=i+1; j<v.size(); j++){
//             if(v[i]>v[j]){
//                 ans.push_back(v[j]);
//                 flag = 1;
//             }  
//         }
//         if(flag == 0){
//             ans.push_back(-1);
//         }
//     }

//     for(int i=0; i<ans.size(); i++){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;

//     return 0;
// }

//optimized appraoch using stack
int main(){
    stack<int> s;
    s.push(-1);
    vector<int> v = {2, 1, 4, 3};
    vector<int> ans;

    int x;
    for(int i=v.size()-1; i>=0; i--){
        while(s.top()>=v[i]){
            s.pop();
        }   

        x = s.top();
        ans.push_back(x);

        if(s.top()<v[i]){
            s.push(v[i]);   
        }

    }

    reverse(ans.begin(), ans.end());

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//Previous Smaller Element
// int main(){
//     stack<int> s;
//     s.push(-1);
//     vector<int> v = {2, 1, 4, 3};
//     vector<int> ans;

//     int x;
//     for(int i=0; i<v.size(); i++){
//         while(s.top()>=v[i]){
//             s.pop();
//         }   

//         x = s.top();
//         ans.push_back(x);

//         if(s.top()<v[i]){
//             s.push(v[i]);   
//         }

//     }

//     for(int i=0; i<ans.size(); i++){
//         cout<<ans[i]<<" ";
//     }
//     cout<<endl;
//     return 0;
// }