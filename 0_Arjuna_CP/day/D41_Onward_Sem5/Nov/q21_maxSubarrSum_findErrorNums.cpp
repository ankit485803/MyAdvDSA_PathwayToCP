


/*


29th Nov 2025 (Satursday)


qno 3381  https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k/


3381. Maximum Subarray Sum With Length Divisible by K
Medium
Topics

Companies
Hint
You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

 

Example 1:

Input: nums = [1,2], k = 1

Output: 3

Explanation:

The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

Example 2:

Input: nums = [-1,-2,-3,-4,-5], k = 4

Output: -10

Explanation:

The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

Example 3:

Input: nums = [-5,1,2,-3,4], k = 2

Output: 4

Explanation:

The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

 

Constraints:

1 <= k <= nums.length <= 2 * 105
-109 <= nums[i] <= 109


*/


class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        //myApproach bruteForce

        //step1: long long sum = 0;
        //sttep2: form subArr from nums
        //step3: check subArr.size() % k == 0; if yes return sum[subArr]
    }
};



class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        //myApproach - BruteForce which TLE error, tc=O(n^2), sc=O(1)
        long long maxSum = LLONG_MIN;
        int n = nums.size();

        //loopThrough all possible subArr
        for(int i=0; i<n; ++i) {
            long long currSum = 0;
            for(int j=i; j<n; ++j) {
                currSum += nums[j];
                
                //chek if the length of the subarray is divisible by k
                if((j - i +1) % k == 0) {
                    maxSum = max(maxSum, currSum);
                }            }
        }

        return maxSum;
    
    }
};



class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) { //tc=O(n)=sc
        int n = nums.size();

        // Step 1: Build the prefix sum array
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        long long ans = LLONG_MIN; 

        // Step 2: Iterate through all possible subarray starts (up to index k-1)
        for (int start = 0; start < k; start++) {
            long long currSum = 0;

            // Step 3: For each start, move i in steps of k to get subarrays of length k
            int i = start;
            while (i < n && i + k - 1 < n) {
                int j = i + k - 1;

                // Step 4: Calculate the sum of the current subarray
                long long subSum = prefSum[j] - (i > 0 ? prefSum[i - 1] : 0);

                // Step 5: Apply Kadane's algorithm to maximize the sum 
                currSum = max(subSum, currSum + subSum);
                ans = max(ans, currSum);

                i += k;  // Move i in steps of k to ensure subarrays of length divisible by k
            }
        }

        return ans;  
    }
};



/*

qno  495  https://leetcode.com/problems/teemo-attacking/description/


495. Teemo Attacking
Easy
Topics

Companies
Our hero Teemo is attacking an enemy Ashe with poison attacks! When Teemo attacks Ashe, Ashe gets poisoned for a exactly duration seconds. More formally, an attack at second t will mean Ashe is poisoned during the inclusive time interval [t, t + duration - 1]. If Teemo attacks again before the poison effect ends, the timer for it is reset, and the poison effect will end duration seconds after the new attack.

You are given a non-decreasing integer array timeSeries, where timeSeries[i] denotes that Teemo attacks Ashe at second timeSeries[i], and an integer duration.

Return the total number of seconds that Ashe is poisoned.

 

Example 1:

Input: timeSeries = [1,4], duration = 2
Output: 4
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 4, Teemo attacks, and Ashe is poisoned for seconds 4 and 5.
Ashe is poisoned for seconds 1, 2, 4, and 5, which is 4 seconds in total.
Example 2:

Input: timeSeries = [1,2], duration = 2
Output: 3
Explanation: Teemo's attacks on Ashe go as follows:
- At second 1, Teemo attacks, and Ashe is poisoned for seconds 1 and 2.
- At second 2 however, Teemo attacks again and resets the poison timer. Ashe is poisoned for seconds 2 and 3.
Ashe is poisoned for seconds 1, 2, and 3, which is 3 seconds in total.
 

Constraints:

1 <= timeSeries.length <= 104
0 <= timeSeries[i], duration <= 107
timeSeries is sorted in non-decreasing order.



*/


class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int totalPoisonedTime = 0;
        
        // Edge case: if timeSeries is empty, no poison time.
        if (timeSeries.empty()) {
            return 0;
        }

        for (int i = 1; i < timeSeries.size(); ++i) {
            // Calculate the poisoned time between consecutive attacks
            // If the next attack happens before the current poison effect ends
            // we add only the time after the current poison effect ends.
            if (timeSeries[i] < timeSeries[i - 1] + duration) {
                totalPoisonedTime += timeSeries[i] - timeSeries[i - 1];
                
            } else {
                totalPoisonedTime += duration;  // no overlap, add full duration
            }
        }

        // Add the poison duration for the first attack (full duration).
        totalPoisonedTime += duration;
        
        return totalPoisonedTime;
    }
};




/*

qno 2446  https://leetcode.com/problems/determine-if-two-events-have-conflict/description/

2446. Determine if Two Events Have Conflict
Easy
Topics

Companies
Hint
You are given two arrays of strings that represent two inclusive events that happened on the same day, event1 and event2, where:

event1 = [startTime1, endTime1] and
event2 = [startTime2, endTime2].
Event times are valid 24 hours format in the form of HH:MM.

A conflict happens when two events have some non-empty intersection (i.e., some moment is common to both events).

Return true if there is a conflict between two events. Otherwise, return false.

 

Example 1:

Input: event1 = ["01:15","02:00"], event2 = ["02:00","03:00"]
Output: true
Explanation: The two events intersect at time 2:00.
Example 2:

Input: event1 = ["01:00","02:00"], event2 = ["01:20","03:00"]
Output: true
Explanation: The two events intersect starting from 01:20 to 02:00.
Example 3:

Input: event1 = ["10:00","11:00"], event2 = ["14:00","15:00"]
Output: false
Explanation: The two events do not intersect.
 

Constraints:

event1.length == event2.length == 2
event1[i].length == event2[i].length == 5
startTime1 <= endTime1
startTime2 <= endTime2
All the event times follow the HH:MM format.




The toMinutes function converts a time in HH:MM format into the total number of minutes since midnight by:
        Extracting and converting the hours to minutes.
        Adding the minutes part to get the total.



*/

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {  //tc=O(1)=sc
        // Helper function to convert "HH:MM" time format to minutes since midnight
        auto toMinutes = [](const string& time) -> int {
            return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        };

        // Convert both event times to minutes
        int start1 = toMinutes(event1[0]);
        int end1 = toMinutes(event1[1]);
        int start2 = toMinutes(event2[0]);
        int end2 = toMinutes(event2[1]);

        // Check if the events overlap
        return start1 <= end2 && start2 <= end1;
    }
};



//eg
string time = "01:15";
// Extract hours: "01" -> stoi("01") -> 1
// Convert hours to minutes: 1 * 60 = 60
// Extract minutes: "15" -> stoi("15") -> 15
// Total minutes: 60 + 15 = 75
int totalMinutes = toMinutes(time); // Result is 75

//eg2- how to convet
string time = "10:45";
// Extract hours: "10" -> stoi("10") -> 10
// Convert hours to minutes: 10 * 60 = 600
// Extract minutes: "45" -> stoi("45") -> 45
// Total minutes: 600 + 45 = 645
int totalMinutes = toMinutes(time); // Result is 645


//mainSyntax
auto toMinutes = [](const string& time) -> int {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
};




/*

qno 2278  https://leetcode.com/problems/percentage-of-letter-in-string/


2278. Percentage of Letter in String
Solved
Easy
Topics

Companies
Hint
Given a string s and a character letter, return the percentage of characters in s that equal letter rounded down to the nearest whole percent.

 

Example 1:

Input: s = "foobar", letter = "o"
Output: 33
Explanation:
The percentage of characters in s that equal the letter 'o' is 2 / 6 * 100% = 33% when rounded down, so we return 33.
Example 2:

Input: s = "jjjj", letter = "k"
Output: 0
Explanation:
The percentage of characters in s that equal the letter 'k' is 0%, so we return 0.
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.
letter is a lowercase English letter.


*/


class Solution {
public:
    int percentageLetter(string s, char letter) { //tc=O(n), sc=O(1)
        int n = s.size();

        int count = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == letter) {
                count++;  // Increment count if the character matches the letter
            }
        }
        int percentLetter = (count * 100) / n;  //simply apply percentageFormaula

        return  percentLetter;
    }
};



/*

qno 645  https://leetcode.com/problems/set-mismatch/


Code
Testcase
Testcase
Test Result
645. Set Mismatch
Attempted
Easy
Topics

Companies
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

 

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]
Example 2:

Input: nums = [1,1]
Output: [1,2]
 

Constraints:

2 <= nums.length <= 104
1 <= nums[i] <= 104


*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {  //tc=O(n), sc=o(1)
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> err(2); // To store duplicate and missing number
        int missing = 1;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                err[0] = nums[i]; // Duplicate number
            }
            
            // Check if the number is expected or missing
            if (nums[i] == missing) {
                missing++;
            }
        }
        
        // The missing number will be the last missing value
        err[1] = missing;

        return err;
    }
};
