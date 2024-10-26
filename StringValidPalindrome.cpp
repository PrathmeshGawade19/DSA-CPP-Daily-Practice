//String Valid Palindrome Check

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//problem 1
char UppertoLower(char ch){
    if(ch>='A' && ch<='Z'){
        char result=ch-'A'+'a';
        return result;
    }
    else{
        return ch;
    }  
}

int main(){
    vector<char> str={'a','b','m'};
    
    int flag=0;
    for(int i=0,j=str.size()-1; i<=j; i++,j--){
        if(UppertoLower(str[i])!=UppertoLower(str[j])){
            cout<<"not a palindrome"<<endl;
            flag=1;
            break;
            
        }
    }

    if(flag==0){
        cout<<"it is palindrome"<<endl;
    }


    return 0;
}

//problem 2 
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// bool CheckValid(char ch) {
//     return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
// }

// char UppertoLower(char ch) {
//     if (ch >= 'A' && ch <= 'Z') {
//         return ch - 'A' + 'a';
//     }
//     return ch;
// }

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         int i = 0, j = s.size() - 1;
        
//         while (i < j) {
//             while (i < j && !CheckValid(s[i])) {
//                 i++;
//             }
            
//             while (i < j && !CheckValid(s[j])) {
//                 j--;
//             }
            
//             if (UppertoLower(s[i]) != UppertoLower(s[j])) {
//                 return false;
//             }
            
//             i++;
//             j--;
//         }
        
//         return true;
//     }
// };
