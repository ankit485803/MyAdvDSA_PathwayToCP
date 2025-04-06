
#include <iostream>
using namespace std;
#include <string>
#include <vector>

/*
prob Link: Qno 443.   https://leetcode.com/problems/string-compression/description/


step1: Continous Chars  
step2: if count=1  &&  count>1



imp function to convert int to str:  to_string(count)

*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        //step1: Continours char  -- TC=O(n) because one iterator run in for loop and while loop
        for(int i=0; i<n; i++) {
            char ch = chars[i];
            int count = 0;

            while(i<n && chars[i] == ch) {   //step2: jab count 1 or more
                count++;  i++;
            }

            if(count == 1) {
                chars[idx++] = ch;
            } else {
                chars[idx++] = ch;
                string str = to_string(count);
                for(char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--;
        }

        chars.resize(idx);
        return idx;
    }
};


// TC = O(n) and SC = O(n)