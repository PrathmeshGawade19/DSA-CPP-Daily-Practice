//Find unique element in an array
#include<iostream>
using namespace std;
int main(){
    int arr[]={10,20,291,10,30,30,20};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    // //logic1
    // for(int i=0; i<arrsize; i++){
    //     int count=0;
    //     for(int j=0; j<arrsize; j++){
    //         if(arr[i]==arr[j]){
    //             count++;
    //         }
    //     }
    //     cout<<"count of "<<arr[i]<<" is : "<<count<<endl;
    //     if(count==1){
    //         cout<<"count is 1 so "<<arr[i]<<" is unquie element :) "<<endl;
    //     }
    // }

    //logic2
    int unique=0;
    for(int i=0; i<arrsize; i++){
        unique=unique^arr[i];
    }
    if(unique!=0){
    cout<<"unique element in array is: "<<unique;

    }
    else{
    cout<<"oops! there is no unique element in array :(";       
    }



    
    
    return 0;
}