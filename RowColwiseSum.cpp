#include<iostream>

using namespace std;
int main(){
    int arr[3][3]={{3,4,11},{2,12,1},{7,8,7}};
    int arrsizerow=sizeof(arr)/sizeof(arr[0]);
    int arrsizecol=sizeof(arr[0])/sizeof(arr[0][0]);

    //row wise sum
    // for(int i=0; i<arrsizerow; i++){
    //     int sum=0;
    //     for(int j=0; j<arrsizecol; j++){
    //         sum=sum+arr[i][j];
    //     }
    //     cout<<"sum for "<<i+1<<" th index elements is : "<<sum<<endl;
    // }

    //col wise sum
    // for(int i=0; i<arrsizerow; i++){
    //     int sum=0;
    //     for(int j=0; j<arrsizecol; j++){
    //         sum=sum+arr[j][i];
    //     }
    //     cout<<"sum for "<<i+1<<" th index elements is : "<<sum<<endl;
    // }

    //row wise largest sum
    int largestsum=INT32_MIN,largestindex=-1;
    for(int i=0; i<arrsizerow; i++){
        int sum=0;
        for(int j=0; j<arrsizecol; j++){
            sum=sum+arr[i][j];
        }
        largestsum=max(largestsum,sum);
        if(largestsum==sum){
            largestindex=i;
        }
        cout<<"sum for "<<i<<" th index elements is : "<<sum<<endl;
    }
    cout<<"largest sum row wise is : "<<largestsum<<" at index of row is : "<<largestindex<<endl;

    return 0;

}