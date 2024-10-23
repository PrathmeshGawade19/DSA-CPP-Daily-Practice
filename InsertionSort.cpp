//program to execute insertion sort - O(n^2)
#include<iostream>
using namespace std;

void printarray(int arr[],int arrsize);

int main(){
    int arr[]={10,1,7,4,8,2,11};
    int arrsize=sizeof(arr)/sizeof(int);

    //here we shift and not swap
    for(int i=1; i<arrsize; i++){
        int temp=arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=temp;
    }

    printarray(arr,arrsize);

    return 0;
}

void printarray(int arr[],int arrsize){
    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }
}