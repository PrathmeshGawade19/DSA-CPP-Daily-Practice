//Find unique number of occurences of elements in an array
#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int arr[]={1, 2, 2, 0, 0};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    sort(arr,arr+arrsize);
    int visited[arrsize];
    int countarr[arrsize];

    for(int i=0; i<arrsize-1; i++){
        int count=0;

        if(visited[i]!=arr[i]){
            for(int j=0; j<arrsize; j++){
                if(arr[i]==arr[j]){
                    visited[j]=arr[i];
                    count++;
                    countarr[i]=count;
                }
            }
        }        
    }

    int countarrsize=sizeof(countarr)/sizeof(countarr[0]);
    sort(countarr,countarr+countarrsize);

    int temp=0;
    for(int i=0; i<countarrsize; i++){
        for(int j=i+1; j<countarrsize; j++){
            if(countarr[i]==countarr[j]){
                temp++;
            }
        }     
    }

    if(temp==0){
        cout<<"unqiue occurence YES";
    }
    else{
        cout<<"NO unique occurence";
    }


    
    return 0;
}