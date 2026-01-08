


/*

13th June 2025 (Friday) https://takeuforward.org/data-structure/count-frequency-of-each-element-in-the-array/

Problem statement: Given an array, we have found the number of occurrences of each element in the array.

Examples:

Example 1:
Input: arr[] = {10,5,10,15,10,5};
Output: 10  3
	 5  2
        15  1
Explanation: 10 occurs 3 times in the array
	      5 occurs 2 times in the array
              15 occurs 1 time in the array



method1: using MAP  -- TC=O(n)=SC
method2: LOOP 

*/


#include <iostream>
#include <unordered_map>
using namespace std;

void countFrequencies(int arr[], int n) {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print frequencies
    for (auto it : freq) {
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    countFrequencies(arr, n);

    return 0;
}
