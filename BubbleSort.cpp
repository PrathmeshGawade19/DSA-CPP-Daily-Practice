//program to execute bubble sort - O(n^2) in bestcase O(n)
#include<iostream>
using namespace std;

void printarray(int arr[],int arrsize);

int main(){
    int arr[]={10,1,7,6,14,9};
    int arrsize=sizeof(arr)/sizeof(int);

    for(int i=0; i<arrsize-1; i++){
        bool swapped=false;
        for(int j=0; j<arrsize-i-1; j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
    }

    printarray(arr,arrsize);

    return 0;
}

void printarray(int arr[],int arrsize){
    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }
}