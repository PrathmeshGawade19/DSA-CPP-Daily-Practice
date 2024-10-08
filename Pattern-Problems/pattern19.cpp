// _ _ _ * 
// _ _ * *
// _ * * *
// * * * *

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    
    for(int i=1; i<=r; i++){
        for(int k=r-1; k>=i ; k--){
            cout<<"_ ";
        }

        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        cout<<endl;
    }

    return 0;
}