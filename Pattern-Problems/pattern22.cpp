// 1 1 1 1 
// _ 2 2 2
// _ _ 3 3
// _ _ _ 4

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    
    for(int i=1; i<=r; i++){

        for(int k=1; k<=i-1; k++){
            cout<<"_ ";
        }
        
        for(int j=1; j<=r-i+1; j++){
            cout<<i<<" ";
        }

        cout<<endl;
    }

    return 0;
}