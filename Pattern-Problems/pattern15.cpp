// A     
// B B   
// C C C 

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    
    for(int i=1; i<=r; i++){
        for(int j=1; j<=i; j++){
            char ch='A'+i-1;
            cout<<ch<<" ";
        }
        cout<<endl;
    }

    return 0;
}