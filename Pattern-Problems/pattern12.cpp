// A B C 
// A B C
// A B C

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
            char ch='A'+j-1;
            cout<<ch<<" ";
        }
        cout<<endl;
    }

    return 0;
}