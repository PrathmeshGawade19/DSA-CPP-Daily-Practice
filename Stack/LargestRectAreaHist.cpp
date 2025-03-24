//to find largest rectangle area in histogram

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int> hist = {2,1,5,6,2,3};

    //step 1 - find next smaller element for each
    int n = hist.size();
    vector<int> ansNxt(n);
    stack<int> sNxt;
    sNxt.push(-1);

    int i = n-1;
    while(i >= 0){
        int curr = hist[i];
        while(sNxt.top() != -1 && hist[sNxt.top()] >= curr){
            sNxt.pop();
        }
        ansNxt[i] = sNxt.top();
        sNxt.push(i);

        i--;
    }

    cout<<"next smaller element for each is : ";
    for (int i = 0; i < n; i++) {
        cout << ansNxt[i] << " ";
    }
    cout << endl;

    //step 2 - find previous smaller element for each
    vector<int> ansPrev(n);
    stack<int> sPrev;
    sPrev.push(-1);

    int j = 0;
    while(j < n){
        int curr = hist[j];
        while(sPrev.top() != -1 && hist[sPrev.top()] >= curr){
            sPrev.pop();
        }
        ansPrev[j] = sPrev.top();
        sPrev.push(j);

        j++;
    }

    cout<<"previous smaller element of each is : ";
    for (int i = 0; i < n; i++) {
        cout << ansPrev[i] << " ";
    }
    cout << endl;

    // step 3 - find area = length * breadth
    // where length = hist[i] and breadth = ansNxt[i] - ansPrev[i] - 1
    int area = INT32_MIN;
    for(int i=0; i<n; i++){
        int l = hist[i];

        if(ansNxt[i] == -1){
            ansNxt[i] = n;
        }

        int b = ansNxt[i] - ansPrev[i] - 1;

        

        int newArea = l * b;
        area = max(area, newArea);
    }

    cout<<"largest rect area in histogram is : "<<area;

    return 0;
}