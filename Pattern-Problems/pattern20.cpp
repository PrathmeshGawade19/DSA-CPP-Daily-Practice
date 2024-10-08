// * * * * 
// * * * _
// * * _ _
// * _ _ _

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    
    for(int i=1; i<=r; i++){
        
        for(int j=1; j<=r-i+1; j++){
            cout<<"* ";
        }

        for(int k=1; k<=i-1; k++){
            cout<<"_ ";
        }

        cout<<endl;
    }

    return 0;
}