//program to add array form of integer 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printarray(const vector<int>& arr);

int main() {
    vector<int> num = {1, 2, 0, 0};
    int k = 34;
    vector<int> result;

    int i = num.size() - 1, sum = 0, carry = 0;

    while (i >= 0 || k != 0 || carry != 0) {
        int digit = k % 10;
        if (i >= 0) {
            sum = num[i] + digit + carry;
            i--;
        } else {
            sum = digit + carry;
        }
        carry = sum / 10;
        result.push_back(sum % 10);

        k = k / 10;
    }

    reverse(result.begin(), result.end());
    printarray(result);

    return 0;
}

void printarray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << "\t";
    }
    cout << endl;
}
