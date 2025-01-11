


#include <iostream>
#include <vector>
using namespace std;
//yah algo to add karo
#include <algorithm>



using namespace std;

void nextPermutation(vector<int>& nums) {
    // Step 1: Identify the pivot
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {   //TC = O(n)
        i--;
    }

    if (i >= 0) { // Step 2: Find the successor,  TC = O(n)
        int j = nums.size() - 1;    
        while (nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]); // Step 3: Swap
    }

    // Step 4: Reverse the suffix
    reverse(nums.begin() + i + 1, nums.end());
}

// Example usage
int main() {
    vector<int> nums = {1, 2, 3, 6, 5, 4};
    nextPermutation(nums);

    cout << "The Lexicography No below = " << endl;
    
    for (int num : nums) {
        cout << num << " "; // Output: 1 2 4 3 5 6
    }
    cout << endl;

    return 0;
}



// final TC = O(n)+O(n) = O(n), SC = O(1)