//pointers - used to store address
#include<iostream>
using namespace std;
int main(){
/* 
    8int n = 15;
    int *p = &n; //& - addresss of operator
    cout<<n<<endl; 
    cout<<p<<endl; //address in hexadecimal format
    cout<<*p<<endl; // * - dereferencing operator

    int *q = NULL; //null pointer
    cout<<q<<endl;
*/

/*
    int n = 15;
    char ch = 'a';
    double d = 3.14;
    bool b = true;
    float f = 9.5;

    int *p1 = &n;
    char *p2 = &ch;
    double *p3 = &d;
    bool *p4 = &b;
    float *p5 = &f;

    cout<<"size of variable of different datatype : "<<endl;
    cout<<sizeof(n)<<endl;
    cout<<sizeof(ch)<<endl;
    cout<<sizeof(d)<<endl;
    cout<<sizeof(b)<<endl;
    cout<<sizeof(f)<<endl;

    cout<<"size of pointer pointing different datatype variable : "<<endl;
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;
*/

/*
   int num = 5;
   int *p = &num;
   cout<<p<<endl; //address of num variable
   cout<<++(*p)<<endl; //value at address increment by 1
   cout<<++p<<endl; //p points the address tot he next location incremented by 4 as int type  
*/

   //Pointers and arrays
/*
   int arr[] = {1,2,3,4,5};
   cout<<arr<<endl;
   cout<<&arr<<endl;
   cout<<&arr[0]<<endl; // all this three will have same address

   cout<<arr[1]<<endl;
   cout<<*(arr+1)<<endl;
   cout<<1[arr]<<endl;
   cout<<*(1+arr)<<endl; // all four will output same that is 2
*/

    //difference in array name as pointer and pointer variable
/*
    int arr[]={1,2,3,4,5};
    int num = 6;
    int *ptr = &num;

    cout<<sizeof(arr)<<endl; //gives size of whole array according to type the array
    cout<<sizeof(ptr)<<endl; //gives default size of pointer

    cout<<&arr<<endl; //gives address of the first element to which it is pointing
    cout<<&ptr<<endl; //gives address of the ptr variable itself

    // arr++; //can not change the starting address in array
    cout<<ptr++<<endl; // increments to the next location in memory
*/

/*
    char ch[] = "abcde";
    char c = 'z';
    char *c1 = &c;

    cout<<ch<<endl; //gives whole whole string as output 
    cout<<c1<<endl; //gives output till it finds '\0' (null character)
*/
    
    //pointers and function
    /*
    pointers(*ptr) can be passed as the parameter in function. when we call the function and pass ptr (address to which it is pointing) it works as pass by value (changes not reflected back in main function) , while when we pass *ptr (value of at the location to which it is pointing) changes are reflected back in main function thus acts as pass by reference. 
    */

    //double pointers
    /*
    int i = 50;
    int *p = &i;
    int **q = &p; // double pointer

    cout<<i<<endl;
    cout<<&i<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<q<<endl;
    cout<<*q<<endl;
    cout<<**q<<endl;
    cout<<&q<<endl;
    */

    return 0;
}