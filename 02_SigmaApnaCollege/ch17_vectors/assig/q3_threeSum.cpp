
git commit -m "feat(sigmaApnaCollege): done with assig ques and now ready for newChap (ch17_vectors)" 

/*

leetcode probNo 15  https://leetcode.com/problems/3sum/description/


*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {  //tcO(n^2) nestedLoop, sc=O(1)
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int st = i + 1;
            int end = n - 1;

            while (st < end) {
                int sum = nums[i] + nums[st] + nums[end];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[st], nums[end]});

                    st++;
                    end--;

                    // Skip duplicate second elements
                    while (st < end && nums[st] == nums[st - 1]) {
                        st++;
                    }

                    // Skip duplicate third elements
                    while (st < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                }
                else if (sum < 0) {
                    st++;
                }
                else {
                    end--;
                }
            }
        }

        return ans;
    }
};




class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {  //submssion on 5th Dec 2024
        int n = nums.size();
        vector<vector<int>> ans;  

        sort(nums.begin(), nums.end());  // Sorting step - O(n log n)

        for (int i = 0; i < n; i++) {
            // Skip duplicate elements for the first element in the triplet
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;

            while (j < k) {  // Two-pointer approach - O(n^2)
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;  // Move left pointer to the right to increase the sum
                } else if (sum > 0) {
                    k--;  // Move right pointer to the left to decrease the sum
                } else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Skip duplicate elements for the second and third elements
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;  // Make sure to return the result at the end
    }
};


//method3: twoPointer app -- TC=O(nlogn + n^2), SC=O(uniqueTriplets)