//Reverse an array
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,100,102};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    for(int s=0,e=arrsize-1; s<e; s++,e--){
        int temp;
        temp=arr[s];
        arr[s]=arr[e];
        arr[e]=temp;
    }

    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }

    return 0;
}