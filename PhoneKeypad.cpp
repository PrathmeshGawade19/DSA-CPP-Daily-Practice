//to find letter combinations of a phone number given 
#include<iostream>
#include<vector>
using namespace std;

void solve(string digits, string output, int index, vector<string>& ans, string mapping[]){
    //base case
    if(index >= digits.length()){
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0'; //to convert char to int type 
    string value = mapping[number];

    for(int i=0; i<value.length(); i++){
        output.push_back(value[i]);
        solve(digits, output, index+1, ans, mapping);
        output.pop_back(); //IMP to backtrack here
    }
}

int main(){
    string digits = "23";
    vector<string> ans;
    if(digits.size()==0){
        cout<<ans[0]<<endl;
    }
    string output = "";
    int index = 0;

    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(digits, output, index, ans, mapping);

    cout<<"Letter combinations of a phone number given are : ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    cout<<"Count of total combinations is : "<<ans.size()<<endl;

}