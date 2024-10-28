#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s1 = "a";
    string s2 = "ab";

    // approach 1 - TLE as it check all permutations
    //  string s1copy(s1);

    // int flag = 0;
    // next_permutation(s1.begin(), s1.end());
    // if (s2.find(s1) < s2.size())
    // {
    //     cout << "substring exist" << endl;
    //     flag = 1;
    // }

    // for (int i = 0; s1 != s1copy; i++)
    // {
    //     if (s2.find(s1) < s2.size())
    //     {
    //         cout << "substring exist" << endl;
    //         flag = 1;
    //         break;
    //     }
    //     next_permutation(s1.begin(), s1.end());
    // }

    // if (flag == 0)
    // {
    //     cout << "substring NOT exist" << endl;
    // }

    // approach 2 - frequency-count-based sliding window approach
    class Solution
    {
    private:
        bool checkEqual(int a[26], int b[26])
        {
            for (int i = 0; i < 26; i++)
            {
                if (a[i] != b[i])
                {
                    return false;
                }
            }
            return true;
        }

    public:
        bool checkInclusion(std::string s1, std::string s2)
        {
            // for s1 character array to store count of each character
            int count1[26] = {0};
            for (int i = 0; i < s1.length(); i++)
            {
                int index = s1[i] - 'a';
                count1[index]++;
            }

            // traverse s2 in window size of s1.length() and then compare
            int i = 0;
            int windowsize = s1.length();
            int count2[26] = {0};

            while (i < windowsize && i < s2.length())
            {
                int index = s2[i] - 'a';
                count2[index]++;
                i++;
            }

            if (checkEqual(count1, count2))
            {
                return true;
            }

            while (i < s2.length())
            {
                char newchar = s2[i];
                int index = newchar - 'a';
                count2[index]++;

                char oldchar = s2[i - windowsize];
                index = oldchar - 'a';
                count2[index]--;

                i++;

                if (checkEqual(count1, count2))
                    return true;
            }

            return false;
        }
    };

    return 0;
}