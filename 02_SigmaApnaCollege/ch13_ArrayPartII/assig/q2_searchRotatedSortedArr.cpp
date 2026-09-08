

/*

8th Sep 2026 (Tuesday)

LeetCode qno 31  https://leetcode.com/problems/search-in-rotated-sorted-array/description/



*/



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