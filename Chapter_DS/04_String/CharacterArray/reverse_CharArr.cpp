

#include <iostream>
#include <cstring> // For strlen
using namespace std;
#include <vector>

// qno 344   https://leetcode.com/problems/reverse-string/description/



class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int st = 0, end = s.size()-1;

        while(st < end) {   //TC=O(n)
        
            swap(s[st++], s[end--]);   //swapping 
        }
    }
};



// time complex = O(n), SC = O(1)