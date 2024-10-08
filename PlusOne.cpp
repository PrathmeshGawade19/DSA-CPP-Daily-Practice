//Plus One
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].
// in case of 9 --> 10, 99-->100 and so on

#include<iostream> 
using namespace std;

int main() {
    int arr[] = {9, 9};
    int arrsize = sizeof(arr)/sizeof(arr[0]);

    int arr2[arrsize+1];  // Array for storing the result when incremented

    int ans = 0, digit;
    for(int i = 0; i < arrsize; i++) {
        digit = arr[i];
        ans = (ans * 10) + digit;
    }

    ans = ans + 1;  // Increment the number by 1
    cout << "Incremented value: " << ans << endl;

    int arr2size = arrsize;  // Initialize arr2size

    bool allnines = true;
    for(int i = 0; i < arrsize; i++) {
        if(arr[i] != 9) {
            allnines = false;
            break;  // No need to check further
        }
    }

    if(allnines) {
        arr2size = arrsize + 1;  // Increment size for the case where all digits are 9
    } else {
        arr2size = arrsize;
    }

    int digit2;
    for (int i = arr2size - 1; i >= 0; i--) {  
        digit2 = ans % 10;  
        arr2[i] = digit2;    
        ans = ans / 10;     
    }

    // Output the result stored in arr2
    for (int i = 0; i < arr2size; i++) {
        cout << arr2[i];  
    }
    cout << endl;

    return 0;
}

//vector form logic
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits){
//         int n = digits.size();  // Size of the input vector

//         // Traverse from the last digit to the first
//         for (int i = n - 1; i >= 0; i--) {
//             if (digits[i] < 9) {
//                 digits[i]++;  // Increment the current digit if it's less than 9
//                 return digits;  // Return as there is no carry to propagate
//             }
            
//             // If the current digit is 9, set it to 0 and move to the next digit
//             digits[i] = 0;
//         }

//         // If we reached here, all digits were 9, so we need to insert 1 at the beginning
//         digits.insert(digits.begin(), 1);

//         return digits;  // Return the resulting vector
//     }
// };
