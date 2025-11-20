


/*

7th Nov 2025 (Friday)


qno 3315   https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/


3318. Find X-Sum of All K-Long Subarrays I
Easy
Topics

Companies
Hint
You are given an array nums of n integers and two integers k and x.

The x-sum of an array is calculated by the following procedure:

Count the occurrences of all elements in the array.
Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
Calculate the sum of the answering array.
Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

 

Example 1:

Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

Output: [6,10,12]

Explanation:

For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the answering array. Hence, answer[0] = 1 + 1 + 2 + 2.
For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the answering array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the answering array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
Example 2:

Input: nums = [3,8,7,8,7,5], k = 2, x = 2

Output: [11,15,15,15,12]

Explanation:

Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].

 

Constraints:

1 <= n == nums.length <= 50
1 <= nums[i] <= 50
1 <= x <= k <= nums.length



*/

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {  //TC= O((n - k + 1) * k log k), SC = O(k)
        vector<int> answer;  
        
        //SliddingWindow Approach
        for (int i = 0; i <= nums.size() - k; i++) {

            // Step1: Get the subarray nums[i..i+k-1]
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            
            // Step2: countFreqEachElem in SubArr
            unordered_map<int, int> freq;
            for (int num : subarray) {
                freq[num]++;
            }
            
            // Step3: SortElem by Freq and value (in case of tie) TC=O(log d)
            vector<pair<int, int>> freqList;
            for (auto& entry : freq) {
                freqList.push_back({entry.second, entry.first});
            }
            sort(freqList.rbegin(), freqList.rend()); // SortFreq (and value for tie-breaking)
            

            // Step 4: Keep the top 'x' most frequent elements
            int xSum = 0;
            for (int i = 0; i < min(x, (int)freqList.size()); i++) {
                xSum += freqList[i].second * freqList[i].first; // Element * its frequency
            }
            
            // Step 5: Add the x-sum to the answer
            answer.push_back(xSum);
        }
        
        return answer;
    }
};



/*

qno 557  https://leetcode.com/problems/reverse-words-in-a-string-iii/description/



557. Reverse Words in a String III
Easy
Topics

Companies
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "Mr Ding"
Output: "rM gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.


*/

class Solution {
public:

    //helper to reverse a single word using two pointers
    string revWord(string w) {
        //twoPointer
        int left = 0;
        int right = w.length() - 1;

        while(left < right) {
            swap(w[left], w[right]);
            left++;
            right--;
        }

        return w;
    }


    string reverseWords(string s) {
        
        //directly call funct revWord and apply for sentene
        string ans = "", word = "";
        
        for (char c : s) {
            if (c == ' ') {
                // reverse completed word
                ans += revWord(word) + " ";
                word = "";
            } else {
                word += c;
            }
        }
        // reverse last word (no space after it)
        ans += revWord(word);
        
        return ans;

         
    } //TC=O(n) each character is processed once, SC=O(n) for output string
};  







/*

qno 80  https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

Learn In-placeAlgo which word dirctly on input dataStr without req extraSpace ----  https://en.wikipedia.org/wiki/In-place_algorithm



80. Remove Duplicates from Sorted Array II
Medium
Topics

Companies
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.



*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //TC=O(n), SC=O(1)

        int pos = 0; // position to place next valid element

        for (int num : nums) {
            // Step1: always keep first 2 numbers
            if (pos < 2 || num != nums[pos - 2]) {
                nums[pos] = num;
                pos++;
            }
        }

        return pos; // new length
    }
};



/*

qno 821  https://leetcode.com/problems/shortest-distance-to-a-character/description/


821. Shortest Distance to a Character
Easy
Topics

Companies
Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.

The distance between two indices i and j is abs(i - j), where abs is the absolute value function.

 

Example 1:

Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
Example 2:

Input: s = "aaab", c = "b"
Output: [3,2,1,0]
 

Constraints:

1 <= s.length <= 104
s[i] and c are lowercase English letters.
It is guaranteed that c occurs at least once in s.


*/


class Solution {
public:
    vector<int> shortestToChar(string s, char c) { 
        int n = s.size();
        vector<int> ans(n, n);  // init with large value (max possible distance)

        // Step1: Left → Right pass
        int prev = -n;  
        for (int i = 0; i < n; i++) {
            if (s[i] == c) prev = i;
            ans[i] = i - prev;
        }

        // Step2: Right → Left pass
        prev = 2 * n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) prev = i;
            ans[i] = min(ans[i], prev - i);
        }

        return ans;
    }
};



//TC=O(n) two simple linear scans, SC=O(n) output vector only (can’t avoid it)