// A fancy string is a string where no three consecutive characters are equal.

// Given a string s, delete the minimum possible number of characters from s to make it fancy.

// Return the final string after the deletion. It can be shown that the answer will always be unique.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        int count = 1;
        string result;
        result += s[0]; 
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++; 
            } else {
                count = 1;
            }

            // Only add character if it's not the third in a row
            if (count < 3) {
                result += s[i];
            }
        }

        return result;
    }
};

int main(){
    string s="aaabaaaa";
    Solution sol;
    string result=sol.makeFancyString(s);
    cout<<result;
}