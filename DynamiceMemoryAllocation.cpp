//dynamic memory allocation and some other basic concepts
#include<iostream>
using namespace std;

/*
//pass by reference using reference variable as parameter
void incrnum(int& n){
    n++;
}
*/

int main(){
/*
    int i=5;
    int& j=i; //reference variable
    cout<<i<<endl;
    cout<<j<<endl;
    cout<<++i<<endl;
    cout<<++j<<endl;

    incrnum(i);
    cout<<i<<endl;
*/

/*
    int n;
    cout<<"enter the size of array you want : ";
    cin>>n;
    int *arr=new int[n];
    //dynamic memory allocation - uses heap memory and new keyword

    cout<<"input the elements in the array : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"output of the elements in the array : ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    delete []arr; //imp to free the heap memory as it doesn't gets free automatically like stack (static)
*/

/*
    //In 2d arrays
    int row,col;
    cout<<"enter number of the rows & cols you want: ";
    cin>>row>>col;

    int **arr = new int*[row];
    for(int i=0 ;i<row; i++){
        arr[i] = new int[col];
    } 

    cout<<"input the elements :";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"output of the elements :"<<endl;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<row; i++){
        delete arr[i];
    }
    delete []arr;
*/

// other concepts - macros, global & local variable, inline function, default argument

    return 0;
}
