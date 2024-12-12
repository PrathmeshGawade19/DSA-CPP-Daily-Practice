//problem to find subsets i.e power set of given input array 
#include<iostream>
#include<vector>
using namespace std;

void findsubsets(vector<int> input, vector<int> output, int index, vector<vector<int>>& ans){
    //base case
    if(index>=input.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    findsubsets(input, output, index+1, ans);

    //input
    int ele = input[index];
    output.push_back(ele);
    findsubsets(input, output, index+1, ans);
}

int main(){
    vector<int> input = {1,2,3};

    vector<vector<int>> ans;
    int index = 0;
    vector<int> output;

    findsubsets(input, output, index, ans);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}