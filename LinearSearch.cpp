//Linear Search 
//Time complexity - O(n) linear
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[5];
    int search=1;
    int arrsize=sizeof(arr)/sizeof(arr[0]);
    
    cout<<"enter the elements :";
    for(int i=0; i<arrsize; i++){
        cin>>arr[i];
    }

    for(int i=0; i<arrsize; i++){
        if(search==arr[i]){
            cout<<"we got it!!!"<<arr[i]<<"at index :"<<i;
            break;
        } 
    }

    return 0;
}