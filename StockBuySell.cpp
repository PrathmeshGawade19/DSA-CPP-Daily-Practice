//best time to buy and sell stock
#include<iostream>
using namespace std;
int main(){
    int arr[]={7,6,4,3,1};
    int arrsize=sizeof(arr)/sizeof(arr[0]);
    //assume everyday as a selling day to build a logic

    int maxprofit=0,bestbuy=arr[0];
    for(int i=1; i<arrsize; i++){
        if(arr[i]>bestbuy){
            maxprofit=max(maxprofit,arr[i]-bestbuy);
        }
        bestbuy=min(bestbuy,arr[i]);   
    }

    cout<<maxprofit<<endl;

    return 0;
}