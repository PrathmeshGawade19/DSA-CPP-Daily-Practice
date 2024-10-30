//program to compression string

// Example 1:
// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".

// Example 2:
// Input: chars = ["a"]
// Output: Return 1, and the first character of the input array should be: ["a"]
// Explanation: The only group is "a", which remains uncompressed since it's a single character.

// Example 3:
// Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
// Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        for(int i=0; i<chars.size(); i++){
            int ch=chars[i],count=0;
            while(i<chars.size() && ch==chars[i]){
                count++;
                i++;
            }

            if(count==1){
                chars[index]=ch;
                index++;
            }
            else{
                chars[index]=ch;
                index++;
                string s=to_string(count);
                for(char i:s){
                    chars[index]=i;
                    index++;
                }
            }
            i--;
        }
        chars.resize(index);
        return index;
    }
};

int main(){
    vector<char>ch={'a','a','b','b','c','c','c'};
    Solution sol;
    int ans=sol.compress(ch);
    cout<<" new length of the array after compression is : "<<ans;

    return 0;
}