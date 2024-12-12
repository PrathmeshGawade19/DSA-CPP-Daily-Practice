//problme to find non-empty subsequence of given input string 
#include<iostream>
#include<vector>
using namespace std;

void findsubsequence(string input, string output, int index, vector<string>& ans){
    //base case
    if(index>=input.length()){
        if(output.length() > 0)
            ans.push_back(output);
        return;
    }

    //exclude
    findsubsequence(input, output, index+1, ans);

    //input
    char ch = input[index];
    output.push_back(ch);
    findsubsequence(input, output, index+1, ans);
}

int main(){
    string input = "aab";

    vector<string> ans;
    int index = 0;
    string output = "";

    findsubsequence(input, output, index, ans);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}