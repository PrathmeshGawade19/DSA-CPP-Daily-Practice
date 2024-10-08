//Miscellenous Pattern 2 #Dabang Pattern
// 1 2 3 4 5 5 4 3 2 1 
// 1 2 3 4 * * 4 3 2 1 
// 1 2 3 * * * * 3 2 1
// 1 2 * * * * * * 2 1
// 1 * * * * * * * * 1 

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
        int m=r-i+1;
        for(int j=1; j<=r-i+1; j++){
            cout<<k<<" ";
            k++;
        }

        for(int j=1; j<=i-1; j++){
            cout<<"* ";
        }

        for(int j=1; j<=i-1; j++){
            cout<<"* ";
        }

        for(int j=1; j<=r-i+1; j++){
            cout<<m<<" ";
            m--;
        }

        cout<<endl;
    }

    return 0;
}