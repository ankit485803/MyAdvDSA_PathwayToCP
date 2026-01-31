



/*


31st Jan 2026 (Satursday)



qno 744  https://leetcode.com/problems/find-smallest-letter-greater-than-target/?envType=daily-question&envId=2026-01-31


744. Find Smallest Letter Greater Than Target
Easy
Topics

Companies
Hint
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
Example 3:

Input: letters = ["x","x","y","y"], target = "z"
Output: "x"
Explanation: There are no characters in letters that is lexicographically greater than 'z' so we return letters[0].
 

Constraints:

2 <= letters.length <= 104
letters[i] is a lowercase English letter.
letters is sorted in non-decreasing order.
letters contains at least two different characters.
target is a lowercase English letter.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
682,186/1.2M
Acceptance Rate
55.4%
Topics
Array
Binary Search
Weekly Contest 62



*/



class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //bruteForeApporach - O(n) tc,  sc=O(1)
        int n = letters.size();

        for(int i=0; i<n; i++) {
            if(letters[i] > target) {  //checkCondition just greater using ASCII value
                return letters[i];
            }
        }
        //notFound in letter then return firstChar 
        return letters[0];
    }
};




class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //optimized using BS because sortedArr given
        int left = 0, right = letters.size()-1;
        int result = letters[0];   //defaultSet to firstChar

        while(left <= right) {
            int mid = left + (right-left)/2;

            if(letters[mid] > target) {  //searchInRightHalf
                result = letters[mid];
                right = mid - 1;

            } else {
                left = mid + 1;  //leftHalfSearching
            }
        }

        return result;
    }
};