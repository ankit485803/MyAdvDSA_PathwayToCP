
/*

date of uploaded: 14th Aug 2026 Friday 
Link: https://www.instagram.com/reel/DcBT6cUBXqr

Problem: Given an array arr[], find the maximum product of any 3 elements.

approach1: sorting 

*/

long long maxProduct(vector<int>& arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    long long option1 = 1LL * arr[n-1] * arr[n-2] * arr[n-3];
    long long option2 = 1LL * arr[0] * arr[1] * arr[n-1];

    // TC: O(n log n)
    // SC: O(1)

    return max(option1, option2);
}


//approach2: without sorting 
long long maxProduct(vector<int>& arr) {
    long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    for (int x : arr) {
        if (x >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = x;
        } else if (x >= max2) {
            max3 = max2;
            max2 = x;
        } else if (x > max3) {
            max3 = x;
        }

        if (x <= min1) {
            min2 = min1;
            min1 = x;
        } else if (x < min2) {
            min2 = x;
        }
    }

    long long option1 = max1 * max2 * max3;
    long long option2 = min1 * min2 * max1;

    // TC: O(n)
    // SC: O(1)

    return max(option1, option2);
}