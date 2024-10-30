#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Problem 1
// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "Mr Ding"
// Output: "rM gniD"

// int main(){ 
//     string s="Let's take LeetCode contest";

//     int b=0;
//     for(int i=0; i<=s.size(); i++){
//         if(s[i]==' ' || i==s.size()){
//             reverse(s.begin()+b,s.end()-(s.size()-i));
//             b=i+1;
//         }
//     }

//     cout<<s<<endl;

//     return 0;
// }

//Problem 2
// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

int main(){ 
    string s=" hello  world  ";
    string ans="";

    reverse(s.begin(),s.end());

    for(int i=0; i<s.size(); i++){
        string word="";
        while(i<s.size() && s[i]!=' '){
            word=word+s[i];
            i++;
        }

        reverse(word.begin(),word.end());

        if(word.length()>0){
            ans=ans+" "+word;
        }
    }

    cout<<ans.substr(1)<<endl;

    return 0;
}