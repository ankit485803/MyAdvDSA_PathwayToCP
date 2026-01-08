



/*

20th Nov 2025 (Thursday)


qno  61  https://leetcode.com/problems/rotate-list/

61. Rotate List
Medium
Topics

Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109



When we rotate a linked list to the right by k positions, it means that the nodes are shifted k times to the right. The nodes that move out of the end will reappear at the start of the list.


*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {  //TC=O(n), SC=O(1)

        if (!head || !head->next || k == 0) return head; // Edge cases
        
        //step1: find lengthLL
        ListNode* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }
        
        //step2: Reduce k to avoid unnecessary rotations
        k = k % length;
        if (k == 0) return head;  // If k is a multiple of length, no rotation needed
        

        //step3: Find the new tail (n-k-1) and new head (n-k)
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            newTail = newTail->next;
        }
        
        ListNode* newHead = newTail->next;
        
        //step4: rotateList
        newTail->next = nullptr; // Break the list
        temp->next = head; // Connect the old tail to the old head
        
        return newHead;
    }
};




/*


qno  20  https://leetcode.com/problems/linked-list-components/description/


817. Linked List Components
Medium
Topics

Companies
You are given the head of a linked list containing unique integer values and an integer array nums that is a subset of the linked list values.

Return the number of connected components in nums where two values are connected if they appear consecutively in the linked list.

 

Example 1:


Input: head = [0,1,2,3], nums = [0,1,3]
Output: 2
Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.
Example 2:


Input: head = [0,1,2,3,4], nums = [0,3,1,4]
Output: 2
Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.
 

Constraints:

The number of nodes in the linked list is n.
1 <= n <= 104
0 <= Node.val < n
All the values Node.val are unique.
1 <= nums.length <= n
0 <= nums[i] < n
All the values of nums are unique.


*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {  //TC=O(n + m), SC=O(m), wher n=no of node, m=nums size

        // Step 1: Convert nums into a set for fast lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Step 2: Traverse LL and count connected components
        int count = 0;
        bool inComponent = false; 
        

        while (head) {
            if (numSet.find(head->val) != numSet.end()) { 
                if (!inComponent) { 
                    count++;
                    inComponent = true; // we are now in a component
                }
            } else {
                inComponent = false;

            }

            head = head->next; 
        }
        
        return count;
    }
};




/*


qno  2351  https://leetcode.com/problems/first-letter-to-appear-twice/description/



Code
Testcase
Testcase
Test Result
2351. First Letter to Appear Twice
Easy
Topics

Companies
Hint
Given a string s consisting of lowercase English letters, return the first letter to appear twice.

Note:

A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
s will contain at least one letter that appears twice.
 

Example 1:

Input: s = "abccbaacz"
Output: "c"
Explanation:
The letter 'a' appears on the indexes 0, 5 and 6.
The letter 'b' appears on the indexes 1 and 4.
The letter 'c' appears on the indexes 2, 3 and 7.
The letter 'z' appears on the index 8.
The letter 'c' is the first letter to appear twice, because out of all the letters the index of its second occurrence is the smallest.
Example 2:

Input: s = "abcdd"
Output: "d"
Explanation:
The only letter that appears twice is 'd' so we return 'd'.
 

Constraints:

2 <= s.length <= 100
s consists of lowercase English letters.
s has at least one repeated letter.


*/

class Solution {
public:
    char repeatedCharacter(string s) {
        
        //byObservation: consecutive same char is ans

        //iterate eachChar in str and find consective
        for(int i=0; i<s.length(); i++) {
            if(s[i] == s[i+1]) {  //sameChar
                return s[i];
            }
        }
    }
};

//this is firstApproach - Your current solution is incorrect because the problem does not guarantee that the first repeated letter appears consecutively.


class Solution {
public:
    char repeatedCharacter(string s) { //TC=O(n)
        
        unordered_set<char> seen;  //O(1) SC because only 26 char in alphabet
        for(char c : s) {
            if(seen.count(c)) {  //secound Occurence
                return c;
            }
            seen.insert(c);
        }

        return ' ';  //won't reach here

    }
};



class Solution {
public:
    char repeatedCharacter(string s) {  //TC=O(n), SC=O(1) using Arr and method2: using set
        int freq[26] = {0};

        for (char c : s) {
            if (freq[c - 'a'] == 1)
                return c;
            freq[c - 'a']++;
        }
        return ' ';
    }
};



/*

qno 434  https://leetcode.com/problems/number-of-segments-in-a-string/description/


434. Number of Segments in a String
Easy
Topics

Companies
Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.

 

Example 1:

Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
Example 2:

Input: s = "Hello"
Output: 1
 

Constraints:

0 <= s.length <= 300
s consists of lowercase and uppercase English letters, digits, or one of the following characters "!@#$%^&*()_+-=',.:".
The only space character in s is ' '.


*/


class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            // A segment starts when current char is not space
            // and either it's the first char or previous char was space
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                count++;
            }
        }
        
        return count;
    }
};




/*

qno 717  https://leetcode.com/problems/1-bit-and-2-bit-characters/


717. 1-bit and 2-bit Characters
Solved
Easy
Topics

Companies
Hint
We have two special characters:

The first character can be represented by one bit 0.
The second character can be represented by two bits (10 or 11).
Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

 

Example 1:

Input: bits = [1,0,0]
Output: true
Explanation: The only way to decode it is two-bit character and one-bit character.
So the last character is one-bit character.
Example 2:

Input: bits = [1,1,1,0]
Output: false
Explanation: The only way to decode it is two-bit character and two-bit character.
So the last character is not one-bit character.
 

Constraints:

1 <= bits.length <= 1000
bits[i] is either 0 or 1.



*/


class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        // Traverse the bits array
        while (i < bits.size() - 1) {
            // Move forward: if bits[i] is 0, move 1 step; if 1, move 2 steps
            i += bits[i] + 1;
        }
        // If we end on the last bit, it's a one-bit character
        return i == bits.size() - 1;
    }
};

// greedy approach effectively determines whether the last character is a one-bit character by iterating through the bits with simple conditions, making it both efficient and easy to understand.

// time complex = O(n), space = O(1)


class Solution {
public:
    bool helper(vector<int>& bits, int index) {  //bruteFoce tc=O(2^(n/2)), sc=O(1)
        int n = bits.size();
        if (index == n - 1) return true;  // last bit is a one-bit character
        if (index >= n) return false;     // went past the array
        
        if (bits[index] == 0) {
            // 1-bit character
            return helper(bits, index + 1);
        } else {
            // 2-bit character
            return helper(bits, index + 2);
        }
    }
    
    bool isOneBitCharacter(vector<int>& bits) {
        return helper(bits, 0);
    }
};
