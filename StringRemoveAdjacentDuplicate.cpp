//1047. Remove All Adjacent Duplicates In String
#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {

        //brute force approach can led to O(n^2) complexity
        // int flag=0;
        // while (s.length() > 1 && flag==0) {
        //     int i = 0;
        //     while (i < s.length() - 1) {
        //         if (s[i] == s[i+1]) {
        //             s.erase(i, 2);
        //             break;
        //         }
        //         else if(i == s.length() - 2){
        //             flag=1;
        //             break;
        //         }
        //         i++;
        //     }
        // }
        // return s;

        //stack approach O(n)complexity
        string result;
        for(char ch:s){
            if(result.empty()==false && ch==result.back()){
                result.pop_back();
            }
            else{
                result.push_back(ch);
            }
        }

        return result;
    }
};

int main(){
    string s="abbaca";
    Solution sol;
    string s2=sol.removeDuplicates(s);

    cout<<s2;
}