//Sort 0 1
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={0,1,1,0,0,1,0};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    //logic1
    // int visited[arrsize];

    // int count0,count1;
    // for(int i=0; i<arrsize; i++){
    //     int count=0;
    //     if(visited[i]!=arr[i]){
    //         for(int j=0; j<arrsize; j++){
    //             if(arr[i]==arr[j]){
    //                 visited[j]=arr[i];
    //                 count++;
    //             }
    //         }
    //         if(arr[i]==0){
    //             count0=count;
    //         }
    //         else{
    //             count1=count;
    //         }
    //     }        
    // }
    // cout<<"count of 0 is :"<<count0<<endl;
    // cout<<"count of 1 is :"<<count1<<endl;

    // for(int i=0; i<count0; i++){
    //     arr[i]=0;
    // }
    // for(int i=count0; i<arrsize; i++){
    //     arr[i]=1;
    // }
    // for(int i=0; i<arrsize; i++){
    //     cout<<arr[i]<<"\t";
    // }

    //logic2
    // sort(arr,arr+arrsize);
    // for(int i=0; i<arrsize; i++){
    //     cout<<arr[i]<<"\t";
    // }

    //logic3
    int i=0,j=arrsize-1;
    while(i<j){
        if(arr[i]==0){
            i++;
        }
        else if(arr[j]==1){
            j--;
        }
        else{
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }




    return 0;
}