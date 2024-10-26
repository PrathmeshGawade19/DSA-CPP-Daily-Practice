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

int main(){ 
    string s="Let's take LeetCode contest";

    int b=0;
    for(int i=0; i<=s.size(); i++){
        if(s[i]==' ' || i==s.size()){
            reverse(s.begin()+b,s.end()-(s.size()-i));
            b=i+1;
        }
    }

    cout<<s<<endl;

    return 0;
}