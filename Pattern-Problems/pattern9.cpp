// 1 
// 2 3
// 3 4 5
// 4 5 6 7

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    for(int i=1; i<=r; i++){
        int k=i;
        for(int j=1; j<=i; j++){
            cout<<k<<" ";
            k++;
        }
        cout<<endl;
    }

//instead of using k change int j=i and j<2*i to get same pattern
    return 0;
}