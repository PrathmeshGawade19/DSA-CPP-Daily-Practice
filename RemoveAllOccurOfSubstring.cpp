// Remove All Occurrences of a Substring

#include<iostream>
using namespace std;
int main(){
    string s="daabcbaabcbc";
    string part="abc";

    while(s.find(part)<s.size()){
        s.erase(s.find(part),part.size());
        cout<<s<<endl;
    }
    cout<<s; 

    return 0;
}