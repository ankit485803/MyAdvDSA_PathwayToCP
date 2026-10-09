
git commit -m "feat(sigmaApnaCollege): complete this class lecture of this chap  (ch17_vectors)" 
/*

7th Oct 2026 (Wednesday)

Leetcode probNo 645 https://leetcode.com/problems/set-mismatch/description/



*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {  //first attempt ankit
        //two work: duplicate, missingElm

        vector<int> ans;
        //duplicateElem find and push using twoPointer
        int st = 0, end = nums.size();
        while(st < end) {
            if(nums[st] == nums[end]) {
                ans.push_back(nums[st]);
            }
            st++;
            end--;
        }

        //missingElem logic: check original from 1 to n, which is not in nums then push in ans
        int n = nums.size();
        vector<int> original(n);  //from 1 to n
    }
};


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);  //sc=O(n)=tc today submission 9th OCt 2026 

        int duplicate = -1, missing = -1;

        // Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Find duplicate and missing elements
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                duplicate = i;
            }
            else if (freq[i] == 0) {
                missing = i;
            }
        }

        return {duplicate, missing};
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {  //sc=O(n)=tc today submission 9th OCt 2026 
        sort(nums.begin(), nums.end());

        int duplicate = -1, missing = -1;
        int n = nums.size();

        // Find duplicate
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                duplicate = nums[i];
                break;
            }
        }

        // Find missing number
        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] == 2) {
                missing = nums[i] - 1;
                break;
            }
        }

        // Handle missing number n (e.g. [1, 1])
        if (nums[n - 1] != n) {
            missing = n;
        }

        return {duplicate, missing};
    }
};


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {  //tc=O(n), sc=o(1)  nov 29, 2025 submission
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





