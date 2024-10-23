//program to execute selection sort - O(n^2)
#include<iostream>
using namespace std;

void printarray(int arr[],int arrsize);

int main(){
    int arr[]={64,25,12,22,11};
    int arrsize=sizeof(arr)/sizeof(int);

    for(int i=0; i<arrsize-1; i++){
        int minIndex=i;
        for(int j=i+1; j<arrsize; j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

    printarray(arr,arrsize);

    return 0;
}

void printarray(int arr[],int arrsize){
    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }
}