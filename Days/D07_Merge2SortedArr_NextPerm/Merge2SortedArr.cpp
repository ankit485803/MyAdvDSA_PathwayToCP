
// Qno 88    https://leetcode.com/problems/merge-sorted-array/



#include <iostream>
#include <vector>
using namespace std;
//yah algo to add karo
#include <algorithm>



//method1: Brute force - directly one by one compare karte, new arr mai store kar dege,  ..... but space complex = O(n) ho jayega -- hmko O(1) mai karna h














//method2: space complex = O(1) mai karna h without extra space
// fist arr1: mai hi arr2 ko store karte h by compare from BACKWARD, because bigger element come last (arr is given in sorted order)

//my old solution
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Initialize the last index for merging
    int last = m + n - 1;

    // Define pointers for nums1 and nums2
    int i = m - 1;  // Pointer for nums1 
    int j = n - 1;  // Pointer for nums2

    // Merge in reverse order    -- O(m + n)  where m - nums1, n -- nums2
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[last--] = nums1[i--];
        } else {
            nums1[last--] = nums2[j--];
        }
    }

    // Copy remaining elements of nums2 (if any)
    while (j >= 0) {
        nums1[last--] = nums2[j--];
    }

    }
};


// solution using two pointer approach, time complex = O(m + n) , space = (1)



//by shardha didi
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {

        //initilize
        int idx = m+n-1, i = m-1, j = n-1;


        //1st part-- when LARGER
        while(i >= 0 && j >= 0) {
            if(A[i] >= B[j]) {
                A[idx --] = A[i --]; 
            } else {
                A[idx --] = B[j --]; 
            }
        }

        //2nd part, when smaller
        while(j >= 0) {
            A[idx --] = B[j --]; 
        }

    }
};


//worst case mai time complex = O(m + n) , space = O(1)
//this prob is solved by merge sort in O(nlog(n)) = T.C.