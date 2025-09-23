




// hm directly Binary seach nahi apply kar sakte h, roateed arr par, because half sphere is not sorted

//Qno 33    https://leetcode.com/problems/search-in-rotated-sorted-array/


#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>    //yah algo to add karo


// approach - jab normally Binary search apply nahi ho raha tha tab (problem = arr is not sorted in Left half or righ so we can't apply BS directly), 
// solution -- to use modify BS jismia give condition to check pahle ki tarf proceed karna h okkkk, then same steps repeat


class Solution {
public:
    int search(vector<int>& A, int tar) {
        int st = 0, end = A.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (A[mid] == tar) { // When mid
                return mid;
            }

            // Check LEFT-HALF sorted
            if (A[st] <= A[mid]) {
                if (A[st] <= tar && tar < A[mid]) { // Apply BS in left half
                    end = mid - 1;
                } else { // Right half case
                    st = mid + 1;
                }
            } else { // RIGHT HALF
                if (A[mid] < tar && tar <= A[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1; // When not found
    }
};


// approach is used modify Binary search algo
//time compl = O(log(n)) , spcae = O(1)