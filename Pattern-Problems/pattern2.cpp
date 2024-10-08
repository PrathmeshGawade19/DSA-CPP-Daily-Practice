// 1 1 1 1 
// 2 2 2 2
// 3 3 3 3
// 4 4 4 4

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}