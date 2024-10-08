// 1 2 3 4 
// _ 1 2 3
// _ _ 1 2
// _ _ _ 1

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    
    for(int i=1; i<=r; i++){
        int k=1;
        for(int k=1; k<=i-1; k++){
            cout<<"_ ";
        }

        for(int j=1; j<=r-i+1; j++){
            cout<<k<<" ";
            k++;
        }

        cout<<endl;
    }

    return 0;
}