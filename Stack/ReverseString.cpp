//reverse a string using stack
#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s = "gawade";
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        st.push(s[i]);
    }

    string ans;
    while(!st.empty()){
        char ch =  st.top();
        st.pop();
        ans.push_back(ch);
    }

    //reverse string
    cout<<ans<<endl;

    return 0;
}