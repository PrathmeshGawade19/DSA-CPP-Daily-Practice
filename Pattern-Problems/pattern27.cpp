//Miscellenous Pattern 1
// _ _ _ 1 _ _ _ 
// _ _ 1 2 1 _ _ 
// _ 1 2 3 2 1 _ 
// 1 2 3 4 3 2 1

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
        int m=i-1;
        for(int j=1; j<=r-i; j++){
            cout<<"_ ";
        }

        for(int j=1; j<=i; j++){
            cout<<k<<" ";
            k++;
        }

        for(int j=1; j<i; j++){
            cout<<m<<" ";
            m--;
        }

        for(int j=1; j<=r-i; j++){
            cout<<"_ ";
        }
        
        cout<<endl;
    }

    return 0;
}