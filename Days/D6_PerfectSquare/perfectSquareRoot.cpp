

// Q. 367.  https://leetcode.com/problems/valid-perfect-square/

// How to check the perfect root of a given number
// concept: arr 


#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

#include <cmath> // For sqrt and floor



bool isPerfectSquare(int num) {
    if(num < 0) return false;    //negative number ka sq root not exist

    int root = static_cast <int> (sqrt(num));   //calculate root

    return (root * root == num);  //matching

}


int main() {
    int num;
    cout << "Enter a positive number: ";
    cin >> num;


    if (isPerfectSquare(num)) {
        cout << num << " is a perfect square." << endl;
    } else {
        cout << num << " is not a perfect square." << endl;
    }

    return 0;
}

// using cmath library - time complex = O(1) = space

// In C++, the && operator is the logical AND operator. It is used to combine two or more boolean expressions and returns true only
// if both (or all) of the expressions evaluate to true. If any of the expressions evaluate to false, 
// the entire expression returns false.




// method2: Binary search

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false; // Negative numbers cannot be perfect squares
        if (num == 0 || num == 1) return true; // 0 and 1 are perfect squares

        int s = 1;
        int e = num;

        while (s <= e) {
            int mid = s + (e-s) / 2; // Calculate mid
            
            // Check if mid squared equals num
            long long midSquared = static_cast<long long>(mid) * mid; // Use long long to avoid overflow



            if (midSquared == num) {
                return true; // Perfect square found
            }

            // Adjust search bounds
            if (midSquared < num) {
                s = mid + 1; // Search in the right half
            } else {
                e = mid - 1; // Search in the left half
            }
        }

        return false; // Not a perfect square
    }
};


// timoe compl = O(log(n)), spcae = O(1) -- using Binary Search 