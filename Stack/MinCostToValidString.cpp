//to find minimum cost to make string valid

#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s = "{{}}}";
    stack<char> st;

    if(s.length() % 2 == 1){
        cout<<"Number of braces are odd thus given exp can't be made valid."<<endl;
        return 0;
    }

    int i=0;
    while(i < s.length()){
        char ch = s[i];
        if(ch == '{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        i++;
    }

    int a=0; //number of open braces
    int b=0; //number of close braces

    while(!st.empty()){
        if(st.top() == '{'){
            a++;
            st.pop();
        }
        else{
            b++;
            st.pop();
        }
    }

    cout<<"number of open braces are "<<a<<endl;
    cout<<"number of closed braces are "<<b<<endl;

    int ans = ((a+1)/2 + (b+1)/2);
    cout<<"Minimum cost to make string valid is "<<ans<<endl;

    return 0;
}