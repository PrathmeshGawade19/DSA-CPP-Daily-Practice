//max rectangle in binary matrix with all 1's
//given a binary matrix M of size n x m. find the max area of a rectangle formed only of 1's in the given matrix,

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    vector<vector<int>> v = {{1,0,1,1,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    // cout<<v.size()<<endl;
    // cout<<v[0].size()<<endl;

    vector<int> v1;
    vector<int> v2(v[0].size(), 0);
    vector<int> maxArea;

    for(int i=0; i<v.size(); i++){
        for(int k=0; k<v[0].size(); k++){
            v1.push_back(v[i][k]);
        }
        for(int l=0; l<v1.size(); l++){
            if(v1[l] == 1){
                v2[l] = v1[l] + v2[l];
            }
            else{
                v2[l] = 0;
            }    
        }
        cout<<"ele in v1 :";
        for(int i=0; i<v1.size(); i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;

        cout<<"ele in v2 :";
        for(int i=0; i<v2.size(); i++){
            cout<<v2[i]<<" ";
        }
        cout<<endl;

        //step 1 - find next smaller element for each
        int n = v2.size();
        vector<int> ansNxt(n);
        stack<int> sNxt;
        sNxt.push(-1);

        int p = n-1;
        while(p >= 0){
            int curr = v2[p];
            while(sNxt.top() != -1 && v2[sNxt.top()] >= curr){
                sNxt.pop();
            }
            ansNxt[p] = sNxt.top();
            sNxt.push(p);

            p--;
        }

        //step 2 - find previous smaller element for each
        vector<int> ansPrev(n);
        stack<int> sPrev;
        sPrev.push(-1);

        int j = 0;
        while(j < n){
            int curr = v2[j];
            while(sPrev.top() != -1 && v2[sPrev.top()] >= curr){
                sPrev.pop();
            }
            ansPrev[j] = sPrev.top();
            sPrev.push(j);

            j++;
        }

        // step 3 - find area = length * breadth
        // where length = hist[i] and breadth = ansNxt[i] - ansPrev[i] - 1
        int area = INT32_MIN;
        for(int i=0; i<n; i++){
            int l = v2[i];

            if(ansNxt[i] == -1){
                ansNxt[i] = n;
            }

            int b = ansNxt[i] - ansPrev[i] - 1;

            int newArea = l * b;
            area = max(area, newArea);
        }

        cout<<"largest rect area in histogram is : "<<area<<endl;
        maxArea.push_back(area);
        v1.clear();
    }

    cout <<"max area of rect formed in given matric is : "<<*max_element(maxArea.begin(), maxArea.end());
    
    return 0;
}