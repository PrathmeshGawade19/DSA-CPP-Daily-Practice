#include <iostream>

using namespace std;
int main()
{
    int arr[][4] = {{3, 4, 11, 80}, {2, 12, 1, 23}, {7, 8, 7, 21}};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr[0]) / sizeof(arr[0][0]);
    cout<<n<<endl;
    cout<<m<<endl;

    for (int i = 0; i < m; i++){
        if (i % 2 == 0){
            int j=0;
            while(j<n){
                cout << arr[j][i] << " ";
                j++;
            }
        }
        else{
            int k=n-1;
            while(k>=0){
                cout << arr[k][i] << " ";
                k--;
            }
        }
    }

    return 0;
}