



/*

28th Nov 2025 (Friday)


qno 1417  https://leetcode.com/problems/reformat-the-string/


1417. Reformat The String
Easy
Topics

Companies
Hint
You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).

You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.

Return the reformatted string or return an empty string if it is impossible to reformat the string.

 

Example 1:

Input: s = "a0b1c2"
Output: "0a1b2c"
Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
Example 2:

Input: s = "leetcode"
Output: ""
Explanation: "leetcode" has only characters so we cannot separate them by digits.
Example 3:

Input: s = "1229857369"
Output: ""
Explanation: "1229857369" has only digits so we cannot separate them by characters.
 

Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters and/or digits.


*/


class Solution {
public:
    string reformat(string s) {   //tc=O(n), sc=o(n)
        string letters = "", digits = "";

        //separate Letters and digits
        for(char c : s) {
            if(isalpha(c)) letters += c;
            else digits += c;
        }

        //if diff > 1, impossible
        if(abs( (int)letters.size()  - (int)digits.size()) > 1) 
        return "";

        string result = "";
        //Decide which type to place first
        bool letterTurn = letters.size() > digits.size();

        int i=0, j=0;
        while(i<letters.size() || j<digits.size()) {
            if(letterTurn) {
                result += letters[i++]; 
            } else {
                result += digits[j++];
            }

            letterTurn = !letterTurn;  //alternate
        }

        return result;
    }
};




/*

qno 1078 https://leetcode.com/problems/occurrences-after-bigram/description/


1078. Occurrences After Bigram
Easy
Topics

Companies
Hint
Given two strings first and second, consider occurrences in some text of the form "first second third", where second comes immediately after first, and third comes immediately after second.

Return an array of all the words third for each occurrence of "first second third".

 

Example 1:

Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
Example 2:

Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
 

Constraints:

1 <= text.length <= 1000
text consists of lowercase English letters and spaces.
All the words in text are separated by a single space.
1 <= first.length, second.length <= 10
first and second consist of lowercase English letters.
text will not have any leading or trailing spaces.


*/



class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> words;
        string word = "";

        // Split text into words
        for (char c : text) {
            if (c == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word); // push last word

        vector<string> result;

        // Check consecutive triplets
        for (int i = 0; i + 2 < words.size(); i++) {
            if (words[i] == first && words[i + 1] == second) {
                result.push_back(words[i + 2]);
            }
        }

        return result;
    }
};


// Time: O(n) — scanning text and checking words
// Space: O(n) — storing words



/*

qno 1592  https://leetcode.com/problems/rearrange-spaces-between-words/


1592. Rearrange Spaces Between Words
Easy
Topics

Companies
Hint
You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by at least one space. It's guaranteed that text contains at least one word.

Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.

Return the string after rearranging the spaces.

 

Example 1:

Input: text = "  this   is  a sentence "
Output: "this   is   a   sentence"
Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.
Example 2:

Input: text = " practice   makes   perfect"
Output: "practice   makes   perfect "
Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
 

Constraints:

1 <= text.length <= 100
text consists of lowercase English letters and ' '.
text contains at least one word.


*/


class Solution {
public:
    string reorderSpaces(string text) {
        //split text into words
        vector<string> words;
        string word = "";
        for(char c : text) {
            if(c == " ") {
                words.push_back(word);
                word = "";
            } else {
                word += c;
            }
        }
        words.push_back(word);

        //findSpaces
        int spaces = 0;
        for(int i=0; i<text.size(); i++) {
            if(text[i] == ' ') {
                spaces++;
            }
        }
        int n = words.size();  //no of total words in text

        //case1: onlyOneWord - Put all spaces at the end
        if(n == 1) {
            stringBuilder sb = new builder();
            sb.append(words[0]);
            for(int i=1; i<=spaces; i++) {
                sb.append(' '); //append total at least
            }
            return sb.toString();
        }

        //case2: if words more than 1 - Distribute spaces evenly between words
        stringbuilder sb = new builder();
        int spaceBetween = spaces / (n-1);
        int extraSpace = spaces % (n-1);

        for(int i=0; i<n; i++) {
            sb.append(words[i]);

            if(i != n-1) {
                for(int j=1; j<=spaceBetween; j++) {
                    sb.append(' ');
                }
            }
        }

        //addingExtraSpace
        for(int i=1; i<=extraSpace; i++) {
            sb.append(' ');
        }

        return sb.toString();
    }
};



class Solution {
public:
    string reorderSpaces(string text) {  //tc=O(n)=sc
        vector<string> words;
        string word = "";

        // Extract words from text
        for (char c : text) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty())
            words.push_back(word);  // last word

        // Count total spaces
        int spaces = 0;
        for (char c : text) {
            if (c == ' ')
                spaces++;
        }

        int n = words.size();

        // If only one word: append all spaces at end
        if (n == 1) {
            return words[0] + string(spaces, ' ');
        }

        // Calculate space distribution
        int spaceBetween = spaces / (n - 1);
        int extraSpace = spaces % (n - 1);

        // Build result
        string result = "";
        string gap(spaceBetween, ' ');

        for (int i = 0; i < n; i++) {
            result += words[i];
            if (i != n - 1) {
                result += gap;
            }
        }

        // Append leftover spaces
        result += string(extraSpace, ' ');

        return result;
    }
};




/*

qno 1015  https://leetcode.com/problems/smallest-integer-divisible-by-k/description/

1015. Smallest Integer Divisible by K
Attempted
Medium
Topics

Companies
Hint
Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.

 

Example 1:

Input: k = 1
Output: 1
Explanation: The smallest answer is n = 1, which has length 1.
Example 2:

Input: k = 2
Output: -1
Explanation: There is no such positive integer n divisible by 2.
Example 3:

Input: k = 3
Output: 3
Explanation: The smallest answer is n = 111, which has length 3.
 

Constraints:

1 <= k <= 105




*/



class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // No repunit divisible by 2 or 5
        if (k % 2 == 0 || k % 5 == 0) 
            return -1;

        int num = 0;
        for (int leng = 1; leng <= k; leng++) {
            num = (num * 10 + 1) % k;
            if (num == 0) 
                return leng;
        }
        return -1;
    }
};



/*

qno  901  https://leetcode.com/problems/online-stock-span/

901. Online Stock Span
Medium
Topics

Companies
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 

Constraints:

1 <= price <= 105
At most 104 calls will be made to next.


*/


class StockSpanner {
public:
    stack<pair<int,int>> st;  // {price, span}

    StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;

        // Pop while previous prices <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }

        // Push current price and its span
        st.push({price, span});

        return span;
    }
};




/*

qno 3065 https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/

3065. Minimum Operations to Exceed Threshold Value I
Solved
Easy
Topics

Companies
Hint
You are given a 0-indexed integer array nums, and an integer k.

In one operation, you can remove one occurrence of the smallest element of nums.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

 

Example 1:

Input: nums = [2,11,10,1,3], k = 10
Output: 3
Explanation: After one operation, nums becomes equal to [2, 11, 10, 3].
After two operations, nums becomes equal to [11, 10, 3].
After three operations, nums becomes equal to [11, 10].
At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
It can be shown that 3 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
Example 2:

Input: nums = [1,1,2,4,9], k = 1
Output: 0
Explanation: All elements of the array are greater than or equal to 1 so we do not need to apply any operations on nums.
Example 3:

Input: nums = [1,1,2,4,9], k = 9
Output: 4
Explanation: only a single element of nums is greater than or equal to 9 so we need to apply the operations 4 times on nums.
 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 109
1 <= k <= 109
The input is generated such that there is at least one index i such that nums[i] >= k.



*/


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {  //tc=O(n), sc=O(1)
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int ops = 0;

        for(int i=0; i<n; i++) {
            if(nums[i] < k) {
                ops++;
            } else {
                break;
            }
        }

        return ops;
    }
};





/*

qno 2798  https://leetcode.com/problems/number-of-employees-who-met-the-target/


2798. Number of Employees Who Met the Target
Attempted
Easy
Topics

Companies
Hint
There are n employees in a company, numbered from 0 to n - 1. Each employee i has worked for hours[i] hours in the company.

The company requires each employee to work for at least target hours.

You are given a 0-indexed array of non-negative integers hours of length n and a non-negative integer target.

Return the integer denoting the number of employees who worked at least target hours.

 

Example 1:

Input: hours = [0,1,2,3,4], target = 2
Output: 3
Explanation: The company wants each employee to work for at least 2 hours.
- Employee 0 worked for 0 hours and didn't meet the target.
- Employee 1 worked for 1 hours and didn't meet the target.
- Employee 2 worked for 2 hours and met the target.
- Employee 3 worked for 3 hours and met the target.
- Employee 4 worked for 4 hours and met the target.
There are 3 employees who met the target.
Example 2:

Input: hours = [5,1,4,2,2], target = 6
Output: 0
Explanation: The company wants each employee to work for at least 6 hours.
There are 0 employees who met the target.
 

Constraints:

1 <= n == hours.length <= 50
0 <= hours[i], target <= 105


*/


class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {

        int reqEmp = 0;  //employees who works alteast targest hrs -- ans

        for(int h : hours) {
            if(h >= target) {
                reqEmp++;
            }
        }

        return reqEmp;
    }
};


/*


qno 350  https://leetcode.com/problems/intersection-of-two-arrays-ii/description/


350. Intersection of Two Arrays II
Easy
Topics

Companies
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
 

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) { //tc=O(n+m), sc=O(1)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;
        int i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j]) {
                i++;
            }
            else {
                j++;
            }
        }

        return result;
    }
};



/*

qno 378  https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/


378. Kth Smallest Element in a Sorted Matrix
Medium
Topics

Companies
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

 

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 300
-109 <= matrix[i][j] <= 109
All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
1 <= k <= n2
 

Follow up:

Could you solve the problem with a constant memory (i.e., O(1) memory complexity)?
Could you solve the problem in O(n) time complexity? The solution may be too advanced for an interview but you may find reading this paper fun.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
766,576/1.2M
Acceptance Rate
64.1%
Topics
Array
Binary Search
Sorting
Heap (Priority Queue)
Matrix

*/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        // min-heap: (value, row, col)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // push the first element of each row
        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int val = -1;
        while (k--) {
            auto curr = pq.top();
            pq.pop();

            val = curr[0];
            int r = curr[1];
            int c = curr[2];

            // push next element in the same row
            if (c + 1 < n) {
                pq.push({matrix[r][c + 1], r, c + 1});
            }
        }

        return val;
    }
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            int j = n - 1;

            // count elements <= mid in each row
            for (int i = 0; i < n; i++) {
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                count += (j + 1);
            }

            if (count < k) low = mid + 1;
            else high = mid;
        }

        return low;
    }
};



/*


qno 215  https://leetcode.com/problems/kth-largest-element-in-an-array/


215. Kth Largest Element in an Array
Solved
Medium
Topics

Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
3,346,106/4.9M
Acceptance Rate
68.6%
Topics
Array
Divide and Conquer
Sorting
Heap (Priority Queue)
Quickselect


*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());  //tc=O(logN)

        return nums[n - k];  //laseELm will kth greater
    }
};


/*

qno 1968  https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/description/


1968. Array With Elements Not Equal to Average of Neighbors
Attempted
Medium
Topics

Companies
Hint
You are given a 0-indexed array nums of distinct integers. You want to rearrange the elements in the array such that every element in the rearranged array is not equal to the average of its neighbors.

More formally, the rearranged array should have the property such that for every i in the range 1 <= i < nums.length - 1, (nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].

Return any rearrangement of nums that meets the requirements.

 

Example 1:

Input: nums = [1,2,3,4,5]
Output: [1,2,4,5,3]
Explanation:
When i=1, nums[i] = 2, and the average of its neighbors is (1+4) / 2 = 2.5.
When i=2, nums[i] = 4, and the average of its neighbors is (2+5) / 2 = 3.5.
When i=3, nums[i] = 5, and the average of its neighbors is (4+3) / 2 = 3.5.
Example 2:

Input: nums = [6,2,0,9,7]
Output: [9,7,6,2,0]
Explanation:
When i=1, nums[i] = 7, and the average of its neighbors is (9+6) / 2 = 7.5.
When i=2, nums[i] = 6, and the average of its neighbors is (7+2) / 2 = 4.5.
When i=3, nums[i] = 2, and the average of its neighbors is (6+0) / 2 = 3.
Note that the original array [6,2,0,9,7] also satisfies the conditions.
 

Constraints:

3 <= nums.length <= 105
0 <= nums[i] <= 105


*/


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {  //tc=O(n logN), sc=O(n) for storing result
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> ans(n);

        int mid = (n - 1) / 2;     // last index of first half
        int high = n - 1;          // last index of second half

        // Fill even indices with smaller half
        for (int i = 0; i < n; i += 2) {
            ans[i] = nums[mid--];
        }

        // Fill odd indices with larger half
        for (int i = 1; i < n; i += 2) {
            ans[i] = nums[high--];
        }

        return ans;
    }
};



/*

qno 324  https://leetcode.com/problems/wiggle-sort-ii/description/


324. Wiggle Sort II
Attempted
Medium
Topics

Companies
Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

You may assume the input array always has a valid answer.

 

Example 1:

Input: nums = [1,5,1,1,6,4]
Output: [1,6,1,5,1,4]
Explanation: [1,4,1,5,1,6] is also accepted.
Example 2:

Input: nums = [1,3,2,2,3,1]
Output: [2,3,1,3,1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
0 <= nums[i] <= 5000
It is guaranteed that there will be an answer for the given input nums.
 

Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?

*/


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;  // copy original
        sort(temp.begin(), temp.end());

        int mid = (n - 1) / 2;     // end of smaller half
        int high = n - 1;        

        // Fill wiggle pattern
        for (int i = 0; i < n; i += 2) {
            nums[i] = temp[mid--];   // smaller values on even
        }
        for (int i = 1; i < n; i += 2) {
            nums[i] = temp[high--];  
        }
    }
};



/*


qno 1619  https://leetcode.com/problems/mean-of-array-after-removing-some-elements/description/


1619. Mean of Array After Removing Some Elements
Attempted
Easy
Topics

Companies
Hint
Given an integer array arr, return the mean of the remaining integers after removing the smallest 5% and the largest 5% of the elements.

Answers within 10-5 of the actual answer will be considered accepted.

 

Example 1:

Input: arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
Output: 2.00000
Explanation: After erasing the minimum and the maximum values of this array, all elements are equal to 2, so the mean is 2.
Example 2:

Input: arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
Output: 4.00000
Example 3:

Input: arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
Output: 4.77778
 

Constraints:

20 <= arr.length <= 1000
arr.length is a multiple of 20.
0 <= arr[i] <= 105


*/


class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int x = n / 20;      // 5%  also given constaint arr size multiple of 20
        double sum = 0;

        for (int i = x; i < n - x; i++) {
            sum += arr[i];
        }

        return sum / (n - 2 * x);
    }
};
