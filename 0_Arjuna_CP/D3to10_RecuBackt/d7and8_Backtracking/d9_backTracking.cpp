


// qno 46 https://leetcode.com/problems/permutations/

// qno 78  https://leetcode.com/problems/subsets/description/



#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

/*
Recursion – The function calls itself to explore all possible subsets.

Backtracking – The function explores all possible subsets and backtracks when needed.
TC = Since each character has two choices (take or not take), there are O(2^n)
SC = O(n) (Recursive Stack) → The recursion depth is at most n leading to to O(n) AUXILIARY SPACES



*/


void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
    if (i == arr.size()) {
        // Print the current subset stored in 'ans'
        for (int val : ans) {
            cout << val << " ";
        }
        cout << endl;
        return;
    }

    // Include arr[i] in the subset
    ans.push_back(arr[i]);
    printSubsets(arr, ans, i + 1);

    // Exclude arr[i] from the subset (backtrack)
    ans.pop_back();  
    printSubsets(arr, ans, i + 1);
}



int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ans;   // store subsets

    printSubsets(arr, ans, 0);
    return 0;
}


// TC = total call * work done in each call 

// ref   C:\Users\sanja\Desktop\GitHub_ankit485803\MyAdvDSA_PathwayToCP\Algo\03_Recursion\printSubsets.cpp