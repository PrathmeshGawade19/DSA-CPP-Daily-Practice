//program to print elements in 2d array in spiral form
#include <iostream>

using namespace std;
int main()
{
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9},{10, 11, 12}};
    int r = sizeof(arr) / sizeof(arr[0]);
    int c = sizeof(arr[0]) / sizeof(arr[0][0]);
    int count=0;
    int total=r*c;

    int sr=0,sc=0,er=r-1,ec=c-1;
    
    while(count < total){
        //print starting row
        for(int i=sc; count<total && i<=ec; i++){
            cout<<arr[sr][i]<<" ";
            count++;
        }
        sr++;

        //print ending col
        for(int i=sr; count<total && i<=er; i++){
            cout<<arr[i][ec]<<" ";
            count++;
        }
        ec--;

        //print ending row
        for(int i=ec; count<total && i>=sc; i--){
            cout<<arr[er][i]<<" ";
            count++;
        }
        er--;

        //print startng col
        for(int i=er; count<total && i>=sr; i--){
            cout<<arr[i][sc]<<" ";
            count++;
        }
        sc++;
    }

    return 0;
}