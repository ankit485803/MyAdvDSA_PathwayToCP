

/*

Tichnas Sir and Bond Ma’am have one array of sizes n each. After a lot of talks, they decided to find their Bonding Value. We find the bonding value by doing the following things -

Choose a sub-array from the first array and replace it with a corresponding sub-array from the second array.

Now find the maximum consecutive sub-array sum in the modified first array. The maximum such value is known as the Bonding value. Help them in finding their bonding value and output it.

Note - You can only choose and replace at max once.


*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the maximum subarray sum using Kadane's algorithm
long long maxSubarraySum(const vector<long long>& arr) {
    long long maxSum = LLONG_MIN, currentSum = 0;
    for (long long val : arr) {
        currentSum = max(val, currentSum + val);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

long long solution(int n, vector<int> arr1, vector<int> arr2) {
    // Step 1: Calculate the maximum subarray sum in the original array
    vector<long long> arr1Long(arr1.begin(), arr1.end());
    long long originalMax = maxSubarraySum(arr1Long);

    // Step 2: Find the maximum bonding value by trying to replace a subarray from arr1 with arr2
    long long bondingMax = originalMax;

    // Prefix and suffix sums for arr2
    vector<long long> prefixSum(n, 0), suffixSum(n, 0);

    prefixSum[0] = arr2[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr2[i];
    }

    suffixSum[n - 1] = arr2[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffixSum[i] = suffixSum[i + 1] + arr2[i];
    }

    // Iterate over all possible subarrays
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            // Calculate the sum of arr2 from i to j
            long long arr2Sum = prefixSum[j] - (i > 0 ? prefixSum[i - 1] : 0);

            // Replace arr1[i...j] with arr2[i...j] and compute the new array
            vector<long long> modifiedArr = arr1Long;
            for (int k = i; k <= j; ++k) {
                modifiedArr[k] = arr2[k];
            }

            // Calculate the max subarray sum for the modified array
            long long modifiedMax = maxSubarraySum(modifiedArr);
            bondingMax = max(bondingMax, modifiedMax);
        }
    }

    return bondingMax;
}

int main() {
    // Example 1
    int n1 = 2;
    vector<int> arr1_1 = {4, -2};
    vector<int> arr2_1 = {1, 2};
    cout << solution(n1, arr1_1, arr2_1) << endl; // Output: 6

    // Example 2
    int n2 = 8;
    vector<int> arr1_2 = {-2, 2, -3, 1, -1, -1, 1, 0};
    vector<int> arr2_2 = {4, -3, 3, 3, 2, -5, 3, 4};
    cout << solution(n2, arr1_2, arr2_2) << endl; // Output: 12

    return 0;
}



// Score = 110 / 150