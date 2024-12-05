//merge sort using recursion
//better than selection, insertion, bubble sort as tc is O(nlogn) in worst case
//sc is O(n)
#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int s, int e){
    int mid = s + (e-s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainarrayindex = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[mainarrayindex];
        mainarrayindex++;
    }

    mainarrayindex = mid + 1;
    for(int i=0; i<len2; i++){
        second[i] = arr[mainarrayindex];
        mainarrayindex++;
    }

    //then write code for merge two sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainarrayindex = s;
    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[mainarrayindex] = first[index1];
            mainarrayindex++;
            index1++;
        }
        else{
            arr[mainarrayindex] = second[index2];
            mainarrayindex++;
            index2++;
        }
    }

    while(index1<len1){
        arr[mainarrayindex] = first[index1];
        mainarrayindex++;
        index1++;
    }

    while(index2<len2){
        arr[mainarrayindex] = second[index2];
        mainarrayindex++;
        index2++;
    }

}

void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = s + (e-s) / 2;
    //left part sort karo
    mergeSort(arr, s, mid);
    //right part sort karno
    mergeSort(arr, mid+1, e);
    //merege karo
    merge(arr, s, e);
}

int main(){
    int arr[] = {2,5,1,6,9,100,-1,30};
    int n = sizeof(arr)/sizeof(int);

    mergeSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}