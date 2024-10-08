//Swap alternate an array
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int arrsize=sizeof(arr)/sizeof(arr[0]);
    
    //logic 1
    for(int i=0; i<arrsize; i=i+2){
        if(i+1<arrsize){
            swap(arr[i],arr[i+1]);
        }
    }

    // //logic 2
    // for(int s=0,e=s+1; s<arrsize & e<arrsize; s=s+2,e=e+2){
    //     int temp;
    //     temp=arr[s];
    //     arr[s]=arr[e];
    //     arr[e]=temp;
    // }

    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }

    return 0;
}