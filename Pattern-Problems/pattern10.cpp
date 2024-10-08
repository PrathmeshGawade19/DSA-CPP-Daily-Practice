// 1     
// 2 1   
// 3 2 1 
// 4 3 2 1

#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of rows to print : ";
    cin>>r;
    cout<<"enter number of columns to print : ";
    cin>>c;

    for(int i=1; i<=r; i++){
        int k=i;
        for(int j=1; j<=i; j++){
            cout<<k<<" ";
            k--;
        }
        cout<<endl;
    }

    //instead of using k change cout<<(i-j+1)
    return 0;
}