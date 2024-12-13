//program to illustrate use of modular arithmetic to avoid overflow condition and deal with large number results
/*
--> Key Elements of the Code:
1. Modular Arithmetic: The key operation in this code is `fact = (fact * i) % m;`. By calculating the factorial modulo m at each step of the loop, you ensure that the value of `fact` never grows too large and stays within the range of the data type. Without this step, the factorial value would grow extremely fast and exceed the range of standard data types.
    
2. Long Long Data Type: The `long long` data type is used to store the value of the factorial. In C++, the `int` data type typically has a maximum value of 2^31 - 1, which is approximately 2.1 billion. Since factorial values grow very quickly, for numbers as large as 212, the factorial would far exceed this limit, making it necessary to use `long long` to store larger values, which can hold values up to 2^63 - 1 (about 9.2 quintillion).

--> What Would Happen Without Modular Arithmetic:
If you didn't use modular arithmetic, the factorial value would quickly grow beyond the range of `int` or `long long`, leading to **overflow**. For example:
*   212! is a very large number (roughly 10^395).
*   Without the modulus operation, the result would be incorrect because the number would not fit in the variable's storage, and would overflow or wrap around (i.e., the value would become unpredictable).

Even if the `long long` data type is used, the factorial value would still exceed the storage limit without modular arithmetic, causing incorrect results or overflow. Modular arithmetic ensures that we never compute values too large to handle by reducing the number at each step.

--> Why Modular Arithmetic is Important:
When computing large values like factorials, we want to keep intermediate results manageable. The modulus operation ensures that at each step of the loop, `fact` remains within a range that can be correctly stored and managed.
By using:
fact = (fact * i) % m;
you limit `fact` to the range of 0 ≤ fact < m, preventing it from growing too large.
*/

#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n = 212;
    int m = 1000000007;

    int i=1;
    long long fact = 1;
    while(i<=n){
        fact = (fact * i) % m;
        i++;
    }

    cout<<"factorial is : "<<fact<<endl;

    return 0;
}

//formulae - 
// Addition: (a + b) % m == ((a % m) + (b % m)) % m
// Subtraction: (a - b) % m == ((a % m) - (b % m)) % m
// Multiplication: (a * b) % m == ((a % m) * (b % m)) % m
// Exponentiation: (a^b) % m == ((a % m)^b) % m
// Division: (a / b) % m requires finding the modular inverse of b.