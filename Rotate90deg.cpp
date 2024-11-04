//program to rotate image 90 deg cloclwise
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

#include <iostream>

using namespace std;
int main(){
    int arr[][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int r = sizeof(arr) / sizeof(arr[0]);
    int c = sizeof(arr[0]) / sizeof(arr[0][0]);
    int n = r;
    
    //approach 1 - using temporary 2d matrix 
    // int temp[r][c];
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         temp[j][n-i-1]=arr[i][j];
    //     }
    // }

    // //copy back to original array
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         arr[i][j]=temp[i][j];
    //     }
    // }

    // cout<<"elements in original array are : ";
    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    // }

    //approach 2 - using temporary variable
    // for (int i = 0; i < n / 2; i++) {
    //     for (int j = i; j < n - i - 1; j++) {
    //         int temp = arr[i][j];
    //         arr[i][j] = arr[n - 1 - j][i];                 // Move P4 to P1
    //         arr[n - 1 - j][i] = arr[n - 1 - i][n - 1 - j]; // Move P3 to P4
    //         arr[n - 1 - i][n - 1 - j] = arr[j][n - 1 - i]; // Move P2 to P3
    //         arr[j][n - 1 - i] = temp;                      // Move P1 to P2
    //     }
    // }

    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    // }

    //approach 3 - transpose --> reverse row
    //transpose
    for(int i=0; i<r; i++){
        for(int j=i+1; j<c; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    //reverse row
    for(int i=0; i<r; i++){
        for(int j=0; j<c/2; j++){
            swap(arr[i][j],arr[i][c-1-j]);
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
    }

    return 0;
}