
//merge two arr into single arr

// Qno 88.   https://leetcode.com/problems/merge-sorted-array/description

//concept req:  sorting, two pointer, arr


#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>


void mergeSortedArr(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Initialize the last index for merging
    int last = m + n - 1;

    // Define pointers for nums1 and nums2
    int i = m - 1;  // Pointer for nums1 
    int j = n - 1;  // Pointer for nums2

    // Merge in reverse order    -- O(m + n)  where m - nums1, n -- nums2
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[last--] = nums1[i--];
        } else {
            nums1[last--] = nums2[j--];
        }
    }

    // Copy remaining elements of nums2 (if any)
    while (j >= 0) {
        nums1[last--] = nums2[j--];
    }
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0};
    int m = 3;  // Number of valid elements in nums1

    vector<int> nums2 = {2, 5, 6};
    int n = nums2.size();

    // Using my function
    cout << "Merged array in ascending order:" << endl;

    mergeSortedArr(nums1, m, nums2, n);

    // Printing merged array
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}


// time complex = O(m + n) , space = O(1)

