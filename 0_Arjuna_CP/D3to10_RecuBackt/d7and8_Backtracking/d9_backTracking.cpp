


// qno 46 https://leetcode.com/problems/permutations/

// qno 78  https://leetcode.com/problems/subsets/description/



#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

/*
14th July 202 (Monday)

Recursion – The function calls itself to explore all possible subsets.

Backtracking – The function explores all possible subsets and backtracks when needed.
TC = Since each character has two choices (take or not take), there are O(2^n)
SC = O(n) (Recursive Stack) → The recursion depth is at most n leading to to O(n) AUXILIARY SPACES


recursive tree draw hoga, hn complete array ke liye nahi solve kar rahe h but single elem ke liye; start with empty elem

*/


// void printSubsets(vector<int> &arr, vector<int> &ans, int i) {
//     if (i == arr.size()) {
//         // Print the current subset stored in 'ans'
//         for (int val : ans) {
//             cout << val << " ";
//         }
//         cout << endl;
//         return;
//     }

//     // Include arr[i] in the subset
//     ans.push_back(arr[i]);
//     printSubsets(arr, ans, i + 1);

//     // Exclude arr[i] from the subset (backtrack)
//     ans.pop_back();  
//     printSubsets(arr, ans, i + 1);
// }



// int main() {
//     vector<int> arr = {1, 2, 3};
//     vector<int> ans;   // store subsets

//     printSubsets(arr, ans, 0);
//     return 0;
// }


// TC = total call * work done in each call 

// reference   C:\Users\sanja\Desktop\GitHub_ankit485803\MyAdvDSA_PathwayToCP\Algo\03_Recursion\printSubsets.cpp



void printSubS(vector<int>& arr, vector<int> ans, int i) {
         // Print the current subset stored in 'ans'
    if(i == arr.size()) {
        for(int val : ans) {
            cout << val << " ";
        }

        cout << endl;
        return;
    }

    //inclusion step
    ans.push_back(arr[i]);
    printSubS(arr, ans, i+1);

    ans.pop_back();  //backTracking wala step - remove the last added element
    //exclusion wala
    printSubS(arr, ans, i+1);   //hmko faith h recusion apna kam sahi se karega

}


int main() {
    vector<int> arr = {3, 4, 5};
    vector<int> ans;   // store subsets

    printSubS(arr, ans, 0);
    return 0;
}


