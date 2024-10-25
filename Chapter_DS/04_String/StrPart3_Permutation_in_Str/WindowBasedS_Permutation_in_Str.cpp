


#include <iostream>
using namespace std;
#include <vector>


/*  Qno 567   https://leetcode.com/problems/permutation-in-string/description/

in permutation: no of char + freq of char  is always same 

concept1:  if Constraints in ques given -- lowecase + uppercase + specailChar + digits. In this case hnko nahi pata h kitna freq hai, then
then it's solutin hai aap ek unordered map create karo and store <char, int> will read in HASTING chapter


concept2: s1 and s2 consist of lowercase English letters. then hmko pata h sirf 26 char hoga



step1:  store the freq of char in s1
s2: search s1 permutation in s2 using    sliding  WINDOW BASED SEARCHING tecniq
 
int indx = s1[i] - 'a'    //here ASCII val - ASCII se subtract hoga, good approch to find index



*/




class Solution {
public:
    // Function to check if two frequency arrays are the same
    bool isFreqSame(int freq1[], int freq2[]) {  // O(1) because char is fixed (26)
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        int windFreq[26] = {0};

        // Build the frequency array for s1
        for (int i = 0; i < s1.length(); i++) {   // O(n)
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();
        int s2Length = s2.length();

        // Create the initial window in s2
        for (int i = 0; i < windSize && i < s2Length; i++) {
            windFreq[s2[i] - 'a']++;
        }

        // Check the initial window
        if (isFreqSame(freq, windFreq)) {  // found
            return true;
        }

        // Slide the window over s2
        for (int i = windSize; i < s2Length; i++) {
            // Add the new character to the window
            windFreq[s2[i] - 'a']++;
            // Remove the character that is left behind
            windFreq[s2[i - windSize] - 'a']--;

            // Check if the current window matches
            if (isFreqSame(freq, windFreq)) {  // found
                return true;
            }
        }

        return false;
    }
};














/* 
Total Time Complexity:
Combining all these parts:

Building frequency array for  s1 = O(m)
Creating initial window in s2 = O(m)
Checking initial window: O(1)

Sliding the window: O(n) or said O(1)

overall TC = O(n) and SC = O(1)



*/