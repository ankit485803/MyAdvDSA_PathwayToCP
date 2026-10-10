

/*

9th Oct 2026 (Friday)

qno 1541  https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/?envType=daily-question&envId=2026-10-09


*/


//Approach (Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0; //insertions

        int count = 0;
        int i = 0;

        while(i < n) {
            if(s[i] == '(') {
                count++;
                i++;
            } else { //')'
                if(count > 0) {
                    count--;
                } else {
                    result++; //adding a '('
                }

                if(i+1 < n && s[i+1] == ')') {
                    i += 2;
                } else {
                    result++; //adding a ')'
                    i++;
                }
            }
        }

        return result + count*2;
    }
};
