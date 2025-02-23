//to check given string expression is balanced or not i.e given parenthesis experssion is valid or not
#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s = "())";

    stack<char> st;

    int i=0;
    int flag = 0;
    while(i < s.length()){
        if(s[i] == '[' || s[i] == '{' || s[i] == '('){
            st.push(s[i]);
        }
        else{
            if(!st.empty()){
                if(st.top()=='(' && s[i]==')' || st.top()=='[' && s[i]==']' || st.top()=='{' && s[i]=='}'){
                    st.pop();
                }
                else if(s[i] == ']' || s[i] == '}' || s[i] == ')'){
                    cout<<"exp is unbalanced"<<endl;
                    flag = 1;
                    break;
                }
            }
            else{
                cout<<"exp is unbalanced"<<endl;
                flag = 1;
                break;
            } 
        }
        i++;
    }

    if(flag != 1){
        if(!st.empty()){
            cout<<"exp is unbalanced"<<endl;
        }
        else{
            cout<<"exp is balanced"<<endl;
        }
    }

    return 0;
}