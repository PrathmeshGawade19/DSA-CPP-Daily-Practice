//rat in a maze problem

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> m, int n, vector<vector<int>>& visited){
    if(x>=0 && x<n && y>=0 && y<n && m[x][y]==1 && visited[x][y]==0){
        return true;
    }
    else{
        return false;
    }
}

void solve(vector<vector<int>> m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path){
    //base case
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    visited[x][y]=1;

    //D
    int newx = x+1;
    int newy = y;
    if(isSafe(newx, newy, m, n, visited)){
        path.push_back('D');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //L
    newx = x;
    newy = y-1;
    if(isSafe(newx, newy, m, n, visited)){
        path.push_back('L');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }
    
    //R
    newx = x;
    newy = y+1;
    if(isSafe(newx, newy, m, n, visited)){
        path.push_back('R');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    //U
    newx = x-1;
    newy = y;
    if(isSafe(newx, newy, m, n, visited)){
        path.push_back('U');
        solve(m, n, ans, newx, newy, visited, path);
        path.pop_back();
    }

    visited[x][y]=0;
}

int main(){
    vector<vector<int>> m = {{1,0,0,0},
                     {1,1,0,1},
                     {1,1,0,0},
                     {0,1,1,1}};
    
    int n = m.size(); //rows

    vector<string> ans;
    if(m[0][0]==0){
        cout<<"The starting cell is blocked."<<endl;
        return 0;
    }

    int srcx = 0, srcy = 0;
    vector<vector<int>> visited = m;

    for(int i=0; i<visited.size(); i++){
        for(int j=0; j<visited[0].size(); j++){
            visited[i][j] = 0;
        }
    }

    string path = "";

    solve(m, n, ans, srcx, srcy, visited, path);

    sort(ans.begin(),ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
  

    return 0;
}
