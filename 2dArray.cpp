#include<iostream>
using namespace std;
int main(){
    int arr[3][2]={{10,20},{30,40},{50,60}};
    int arrsizerow=sizeof(arr)/sizeof(arr[0]); //row size
    cout<<arrsizerow<<endl;
    int arrsizecol=sizeof(arr[0])/sizeof(arr[0][0]); //column size
    cout<<arrsizecol<<endl;
    int arrsizetotalele=sizeof(arr)/sizeof(arr[0][0]); //total size
    cout<<arrsizetotalele<<endl;

    // for(int i=0; i<arrsizerow; i++){
    //     for(int j=0; j<arrsizecol; j++){
    //         cin>>arr[i][j];
    //     }
    // }
    
    int arr2[6];
    int arr2size=sizeof(arr2)/sizeof(arr2[0]);

    for(int i=0; i<arrsizerow; i++){
        for(int j=0; j<arrsizecol; j++){
            arr2[arrsizecol*i+j]=arr[i][j]; //implementing 2d array to 1d array
        }
    }

    for(int i=0; i<arr2size; i++){
        cout<<arr2[i]<<" ";
    }

    return 0;

}