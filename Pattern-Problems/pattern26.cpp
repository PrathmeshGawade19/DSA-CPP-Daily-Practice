// _ _ _ 1 
// _ _ 2 3
// _ 4 5 6
// 7 8 9 10

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    int k=1;
    for(int i=1; i<=r; i++){
        
        for(int l=1; l<=r-i; l++){
            cout<<"_ ";
        }

        for(int j=1; j<=i; j++){
            cout<<k<<" ";
            k++;
        }
        
        cout<<endl;
    }

    return 0;
}