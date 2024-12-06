//quick sort using recursion
//tc - avg, best case O(nlogn) and worst case - O(n^2)
//sc - best case - O(nlogn) and worst case - O(n)

#include<iostream>
#include<algorithm>
using namespace std;

int partition(int arr[], int s, int e){
    int pivot = arr[s];

    //count elements less than pivot and then swap corrct position element to place pivot it to its correct position.
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] < pivot){
            count++;
        }
    }
    int pivotindex = s + count;
    swap(arr[s],arr[pivotindex]); //IMP - If we did swap(pivot, arr[pivotIndex]), it wouldn't change the array, because pivot is just a copy of arr[s] and not an actual array element.

    //arrange elements according to the condition |ele's less than pivot|pivot|ele's equal to or greater than pivot|
    int i=s, j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<arr[pivotindex]){
            i++;
        }
        while(arr[j] >= arr[pivotindex]){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i],arr[j]);
        }
    }

    return pivotindex;
}

void quicksort(int arr[], int s, int e){
    //base case
    if(s>=e){
        return;
    }

    //partitioning 
    int p = partition(arr,s,e);

    //recusion to sort left part
    quicksort(arr, s, p-1);
    //recursion to sort right part
    quicksort(arr, p+1, e);
}

int main(){
    int arr[] = {3,1,4,5,2,-1,200,-202};
    int n = sizeof(arr)/sizeof(int);

    quicksort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}