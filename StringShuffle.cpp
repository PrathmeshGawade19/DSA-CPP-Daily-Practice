#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s = "codeleet";
    vector<int> indices = {4, 5, 6, 7, 0, 2, 1, 3};
    string shuffled = s;

    for (int i = 0; i < s.size(); i++)
    {
        int index = indices[i];
        shuffled[index] = s[i];
    }

    cout << shuffled;

    return 0;
}