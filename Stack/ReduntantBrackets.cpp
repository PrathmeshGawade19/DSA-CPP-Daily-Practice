//to check given string experssion has redundant brackets or not

#include<iostream>
#include<stack>
using namespace std;

int main(){
    string s = "(b)";
    stack<char> st;
    bool isRedundant = true;

    int i=0;
    while(i<s.length()){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/' || st.top() == '%'){
                    st.pop();
                    st.pop();
                    isRedundant = false;
                }
                else{
                    isRedundant = true;
                    break;
                }
            }
        }
        i++;
    }

    if(isRedundant == false){
        cout<<"given string has NO redundant brackets"<<endl;
    }
    else{
        cout<<"given string has redundant brackets"<<endl;
    }


    return 0;
}