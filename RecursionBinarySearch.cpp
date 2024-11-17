//binary search using recusion concept
//base case and recursive relation are important two components of recursion
#include<iostream>
using namespace std;

bool bs(int arr[], int s, int e, int key){
    if(s>e){ //base case
        return false;
    }
    
    int mid = s+(e-s)/2;
    if(arr[mid]==key){
        return true;
    }
    
    if(arr[mid]<key){ //recursive relation
        return bs(arr,mid+1,e,key);
    }
    else{
        return bs(arr,s,mid-1,key);
    }

}

int main(){
    int arr[] = {1,2,3,4,5};
    int key = 30;
    int s = 0, e = 4;

    bool ans = bs(arr,s,e,key);
    cout<<ans;


    return 0;
}