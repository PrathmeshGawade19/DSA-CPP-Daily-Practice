#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

/*
vector<int> commonEle(vector<int>& v1, vector<int>& v2){
    vector<int> res;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // Find intersection of two vector
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] < v2[j])
            i++;
        else if (v1[i] > v2[j])
            j++;
        else {
            res.push_back(v1[i]);
            i++;
            j++;
        }
    }

    return res;
}

int main(){
    vector<vector<int>> m = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};

    cout<<m.size()<<endl; //rows
    cout<<m[0].size()<<endl; //cols

    int rcount, ccount;
    vector<int> rceleb;
    vector<int> cceleb;

    //brute force approach
    //row checking - all must be zero for celebrity
    for(int i=0; i<m.size(); i++){
        rcount = 0;
        for(int j=0; j<m[0].size(); j++){
            if(m[i][j] == 0){
                rcount++;
            }
        }
        if(rcount == m[0].size()){
            rceleb.push_back(i);
        }
    }

    cout<<"person obeying row conditon are : ";
    for(int i=0; i<rceleb.size(); i++){
        cout<<rceleb[i]<<endl;
    }

    //col checking - all must be one expect diagonal for celebrity
    for(int i=0; i<m[0].size(); i++){
        ccount = 0;
        for(int j=0; j<m.size(); j++){
            if(m[j][i] == 1){
                ccount++;
            }
        }
        if(ccount == m.size()-1){
            cceleb.push_back(i);
        }
    }

    cout<<"person obeying col conditon are : ";
    for(int i=0; i<cceleb.size(); i++){
        cout<<cceleb[i]<<endl;
    }

    vector<int> res = commonEle(rceleb, cceleb);

    for (auto i : res){
        cout<<"celebrity/celebrities in the party are : "<<i<< " ";
    }
    cout<<endl;

    return 0;
}
*/

// approach 2 - using stack
int main()
{
    vector<vector<int>> m = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    stack<int> s;
    int flag = 0;

    // base case
    if (m.size() == 1)
    {
        cout << "the celebrity in the party is : " << m[0][0] << endl;
        flag = 1;
    }

    if (flag != 1)
    {
        // put all elements inside stack i.e 0, 1, 2
        for (int i = 0; i < m.size(); i++)
        {
            s.push(i);
        }

        // pop 2 ele A, B at at time check if A knows B or B knows A
        //  if A knows B discard A and push B again in stack
        //  if B knows A discard B and push A again in stack
        // keep of doing this till s.size() != 1
        while (s.size() != 1)
        {
            int A, B;
            A = s.top();
            s.pop();
            B = s.top();
            s.pop();

            if (m[A][B] == 1)
            {
                s.push(B);
            }
            else if (m[B][A] == 1)
            {
                s.push(A);
            }
        }

        int r = s.top();

        cout << "potential candidate to be celebrity is : " << r << endl;

        // now remaining single ele is potential candiate to be the celebrity so check the 2 conditions of being celebrity for the ele remained in the stack
        // 1st check all row values are zero as celebrity knows no one
        int rcount = 0;
        for (int i = 0; i < m[0].size(); i++)
        {
            if (m[r][i] == 0)
            {
                rcount++;
            }
        }

        // 2nd check for cols where count of 1's should be m.size()-1 for being a celebrity
        int ccount = 0;
        for (int i = 0; i < m.size(); i++)
        {
            if (m[i][r] == 1)
            {
                ccount++;
            }
        }

        if (rcount == m[0].size() && ccount == m.size() - 1)
        {
            cout << "the celebrity in the party is : " << r << endl;
        }
        else
        {
            cout << "there is no celebrity in the party" << endl;
        }

        return 0;
    }
}