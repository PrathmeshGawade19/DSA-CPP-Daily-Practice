//check balanced string
// You are given a string num consisting of only digits. A string of digits is called balanced if the sum of the digits at even indices is equal to the sum of digits at odd indices.

// Return true if num is balanced, otherwise return false.

// Example 1:

// Input: num = "1234"

// Output: false

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num = "1234";
    int size = num.length();
    cout<<"size of the string is "<<size<<endl;

    int i = 0, j = 1;

    // even
    int sum1 = 0;
    while (i < size)
    {
        int n = num[i] - '0';
        cout<<num[i]<<endl;
        sum1 = sum1 + n;
        i = i + 2;
    }
    cout<<"sum1 is "<<sum1<<endl;

    // odd
    int sum2 = 0;
    while (j < size)
    {
        int n = num[j] - '0';
        cout<<num[j]<<endl;
        sum2 = sum2 + n;
        j = j + 2;
    }
    cout<<"sum2 is "<<sum2<<endl;

    if (sum1 == sum2)
    {
        cout<<"true"<<endl;
    }

    cout<<"false"<<endl;
}
