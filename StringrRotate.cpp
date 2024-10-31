//Program to rotate the string
// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false

#include <iostream>
using namespace std;

int main()
{   
        string s="abcde";
        string goal="bcdea";
        
        int flag=0;
        for(int i=0; i<s.length(); i++){
            int j=0;
            s.push_back(s[j]);
            // cout<<"for i="<<i<<s<<endl;
            s.erase(s.begin(),s.begin()+1);
            // cout<<"for i="<<i<<s<<endl;
            if(s==goal){
                cout<<"true";
                flag=1;
                break;
            }
        }

        if(flag!=1){
            cout<<"false";
        }
        

    return 0;
}