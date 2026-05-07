

/*
6th May 2026 (Wednesday)

Link: https://www.instagram.com/reel/DX9h7JoBVrN

Range of target element in an array 👩‍💻 | Upper Bound | Binary Search
Shortcut of Binary Search 👩‍💻

BinarySearch apply using normal and STL lowerUpperBound

concepts: 
    lower_bound: apply on sortedArr, iterator/index >= target
    upper_bound: same as lowerB sirf diff yaha equal nahi hota strictly greater  iterator/index > target

Syntax:
For Array:
lower_bound(arr, arr + n, target);
upper_bound(arr, arr + n, target);

--------------------------------------------------

For Vector:
lower_bound(v.begin(), v.end(), target);
upper_bound(v.begin(), v.end(), target);

--------------------------------------------------

Important:
These functions return ITERATOR.

To get index:
For Array:
iterator - arr

For Vector:
iterator - v.begin()

--------------------------------------------------

TC = O(log n), sc=O(1) same as binarySearch 


*/



/*

Binary Search STL:
lower_bound & upper_bound

lower_bound:
first element >= target

upper_bound:
first element > target

TC = O(log n)

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int arr[] = {1, 2, 4, 4, 4, 6, 8};
    int n = 7;
    int target = 4;

    // ARRAY
    cout << "Array:\n";

    cout << "lower_bound index = "
         << lower_bound(arr, arr + n, target) - arr
         << endl;

    cout << "upper_bound index = "
         << upper_bound(arr, arr + n, target) - arr
         << endl;


    // VECTOR
    vector<int> v = {1, 2, 4, 4, 4, 6, 8};

    cout << "\nVector:\n";

    cout << "lower_bound index = "
         << lower_bound(v.begin(), v.end(), target) - v.begin()
         << endl;

    cout << "upper_bound index = "
         << upper_bound(v.begin(), v.end(), target) - v.begin()
         << endl;

    return 0;
}


git commit -m "feat(gyaniCoderestro): c4_longestSubarrZeroOnes, BS shortcut using lower and upperbound"