



/*

16th Oct 2025 (Thursday)

qno 682   https://leetcode.com/problems/baseball-game/




682. Baseball Game
Easy
Topics

Companies
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.

The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.

 

Example 1:

Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.
Example 2:

Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
Example 3:

Input: ops = ["1","C"]
Output: 0
Explanation:
"1" - Add 1 to the record, record is now [1].
"C" - Invalidate and remove the previous score, record is now [].
Since the record is empty, the total sum is 0.
 

Constraints:

1 <= operations.length <= 1000
operations[i] is "C", "D", "+", or a string representing an integer in the range [-3 * 104, 3 * 104].
For operation "+", there will always be at least two previous scores on the record.
For operations "C" and "D", there will always be at least one previous score on the record



*/


class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        //intilize record where store operation[i] and update 
        vector<int> record;  //SC=O(n)

        for(const string& op : operations) {  //O(n) TC
            if(op == "C") {
                record.pop_back();  //invalid prevScore

            } else if(op == "D") {
                record.push_back(2 * record.back());  //double prevS

            } else if(op == "+") {
                //sum of lastTwoScore
                record.push_back(record[record.size()-1]  + record[record.size()-2] );

            } else {
                //convert operation to an interge and add it to record
                record.push_back(stoi(op));
            }


        }


        //calculate totalSum in record
        int total = 0;
        for(int score : record) {  //O(n)
            total += score;
        }

        return total;




    }
};


//TC=O(n), sc=O(n)



/*

qno 2996  https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/




2996. Smallest Missing Integer Greater Than Sequential Prefix Sum
Easy
Topics

Companies
Hint
You are given a 0-indexed array of integers nums.
A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.
Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.

 

Example 1:
Input: nums = [1,2,3,2,5]
Output: 6
Explanation: The longest sequential prefix of nums is [1,2,3] with a sum of 6. 6 is not in the array, therefore 6 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.


Example 2:
Input: nums = [3,4,5,1,12,14,13]
Output: 15
Explanation: The longest sequential prefix of nums is [3,4,5] with a sum of 12. 12, 13, and 14 belong to the array while 15 does not. Therefore 15 is the smallest missing integer greater than or equal to the sum of the longest sequential prefix.
 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50



*/


class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // Step1: sortArr TC=O(n LogN)
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        
        // Step2: Find the LongSeqPrefix and calculate its sum - TC=O(n)
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] == nums[i - 1] + 1) {
                sum += nums[i]; // Add to sum if sequential
            } else {
                break; // Stop if no longSeq
            }
        }
        
        // Step3: Store arrElem in a set for O(1) lookup
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        // Step4: Find the smallest missing integer >= sum  TC-O(n)
        for (int i = sum; ; ++i) {
            if (num_set.find(i) == num_set.end()) {
                return i; // Return the first missing int
            }
        }
    }
};

//TC=(nLogN), sc=O(n) for the unordered set storing arrElem



/*

qno 14  https://leetcode.com/problems/longest-common-prefix/
 


14. Longest Common Prefix
Easy
Topics

Companies
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters if it is non-empty.

*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        //baseCase
        if (strs.empty()) return "";
        
        string prefix = strs[0];


        for (int i = 1; i < strs.size(); ++i) {  //tc=O(m *  n), sc=0(1)
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                ++j;
            }

            // Reduce the prefix to the commonPart
            prefix = prefix.substr(0, j);
            if (prefix == "") return "";
        }


        return prefix;
    }
};
