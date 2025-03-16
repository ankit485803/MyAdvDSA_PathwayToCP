


// qno  387  https://leetcode.com/problems/first-unique-character-in-a-string/ 

// in another words first non-repeating character in string



class Solution {
    public:
        int firstUniqChar(string s) {
            unordered_map<char, int> m;
            
            // First pass: count the frequency of each character
            for(int i = 0; i < s.size(); i++) {
                m[s[i]]++;
            }
            
            // Second pass: find the first character with a frequency of 1
            for(int i = 0; i < s.size(); i++) {
                if(m[s[i]] == 1) {
                    return i;
                }
            }
            
            return -1;  // No unique character found
        }
    };
    
    
    // TC = O(n) = SC
    