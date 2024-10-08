//Sort 0 1 2
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={0,2,2,1,0,1,1,2,1,1,1,2,0,1,0,2};
    int arrsize=sizeof(arr)/sizeof(arr[0]);

    //logic1
    int visited[arrsize];

    int count0,count1,count2;
    for(int i=0; i<arrsize; i++){
        int count=0;
        if(visited[i]!=arr[i]){
            for(int j=0; j<arrsize; j++){
                if(arr[i]==arr[j]){
                    visited[j]=arr[i];
                    count++;
                }
            }
            if(arr[i]==0){
                count0=count;
            }
            else if(arr[i]==1){
                count1=count;
            }
            else{
                count2=count;
            }
        }        
    }
    cout<<"count of 0 is :"<<count0<<endl;
    cout<<"count of 1 is :"<<count1<<endl;
    cout<<"count of 2 is :"<<count2<<endl;

    for(int i=0; i<count0; i++){
        arr[i]=0;
    }
    for(int i=count0; i<count0+count1; i++){
        arr[i]=1;
    }
    for(int i=count0+count1; i<arrsize; i++){
        arr[i]=2;
    }
    for(int i=0; i<arrsize; i++){
        cout<<arr[i]<<"\t";
    }

    



    return 0;
}