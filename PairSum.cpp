//Pair Sum
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int s=12;

    int arrsize=sizeof(arr)/sizeof(arr[0]);

    // for(int i=0; i<arrsize; i++){
    //     for(int j=i+1; j<arrsize; j++){
    //         if(arr[i]+arr[j]==s){
    //             cout<<"Pair Sum is : ("<<arr[i]<<","<<arr[j]<<")"<<endl;
    //         }
    //     }
    // }

    //Triplet Sum
    for(int i=0; i<arrsize; i++){
        for(int j=i+1; j<arrsize; j++){
            for(int k=j+1; k<arrsize; k++){
                if(arr[i]+arr[j]+arr[k]==s){
                    cout<<"Pair Sum is : ("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<")"<<endl;
                }
            }
        }
    }


    return 0;
}