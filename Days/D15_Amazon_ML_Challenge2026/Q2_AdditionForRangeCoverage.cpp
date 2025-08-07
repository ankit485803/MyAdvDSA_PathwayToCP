



/*

Minimum Additions for Range Coverage

🧾 Problem Description
Given a sorted integer array A and an integer B, you are allowed to add or patch new elements into the array. 
The goal is to ensure that any number in the range [1, B] (inclusive) can be formed by the sum of some elements in the 
(possibly modified) array.

Your task is to return the minimum number of patches (additions) needed to achieve this.



🔒 Constraints
1 <= A.length <= 1000
1 <= A[i] <= 10⁴
A is sorted in ascending order
1 <= B <= 2³¹ - 1

🔢 Input Format
First input: An integer array A, denoting the initial sorted list of numbers.
Second input: An integer B, the upper bound of the range [1, B].

📤 Output Format
Return an integer, representing the minimum number of patches required to cover the entire range [1, B].

*/




#include <iostream>
#include <vector>
using namespace std;

int minPatches(vector<int>& A, int B) {
    long long miss = 1; // Smallest unformed sum
    int i = 0, patches = 0;

    while (miss <= B) {
        if (i < A.size() && A[i] <= miss) {
            miss += A[i];
            i++;
        } else {
            // Patch required
            miss += miss; // Same as adding a patch of 'miss'
            patches++;
        }
    }

    return patches;
}

int main() {
    vector<int> A = {1, 3, 4};
    int B = 6;

    cout << "Minimum patches required: " << minPatches(A, B) << endl;

    return 0;
}



// TC=O(n + logN), sc=O(logN)
