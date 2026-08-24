
// 24th Aug 2026 (Monday - Last somwari Saban months) uploaded date: 7th Aug Friday 

// Problem: Find the 3rd largest element in an array.

// Approach 1: Sorting
// Concepts: Sorting, Array
// TC: O(n log n), SC: O(1)

int thirdLargest(vector<int>& arr) {
    int n = arr.size();

    if (n < 3)
        return -1;

    sort(arr.begin(), arr.end());

    return arr[n - 3];
}


// Approach 2: Single Pass
// Concepts: Greedy, Array, 3 Maximums
// TC: O(n), SC: O(1)

int thirdLargest(vector<int>& arr) {
    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int x : arr) {
        if (x > first) {
            third = second;
            second = first;
            first = x;
        }
        else if (x > second && x != first) {
            third = second;
            second = x;
        }
        else if (x > third && x != second && x != first) {
            third = x;
        }
    }

    return third == INT_MIN ? -1 : third;
}