//program to get sum of two arrays.
#include<iostream>
#include<vector>
using namespace std;

void printarray(const vector<int>& arr);

int main(){
    int arr1[]={9,9,9};
    int arr2[]={9,9,9};
    vector<int> arr3;
    
    int arr1size=sizeof(arr1)/sizeof(arr1[0]);
    int arr2size=sizeof(arr2)/sizeof(arr2[0]);

    int k=0;
    if (arr1size > arr2size) {
        arr3.resize(arr1size + 1);  
        k = arr1size;
    } else {
        arr3.resize(arr2size + 1); 
        k = arr2size;
    }
    
    int i=arr1size-1,j=arr2size-1,sum=0,carry=0;
    while(i>=0 || j>=0){
        if(i>=0 && j<0){
            sum=arr1[i]+carry;
            i--;
        }
        else if(i<0 && j>=0){
            sum=arr2[j]+carry;
            j--;
        }
        else{
            sum=arr1[i]+arr2[j]+carry;
            i--,j--;
        }
        carry=sum/10;
        arr3.at(k)=sum%10;
        k--;
    }

    if (carry != 0) {
        arr3.at(k) = carry;
    } else {
        arr3.erase(arr3.begin());  // Remove leading zero if no carry
    }

    printarray(arr3);
    
    return 0;
}

void printarray(const vector<int>& arr){

    for(int i:arr){
        cout<<i<<"\t";
    }
}