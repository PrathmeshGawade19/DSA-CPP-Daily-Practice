// A 
// B C
// D E F
// G H I J

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    char ch='A';
    for(int i=1; i<=r; i++){
        for(int j=1; j<=i; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }

    return 0;
}