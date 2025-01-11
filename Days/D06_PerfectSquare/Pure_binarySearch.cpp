
// Qno 704   https://leetcode.com/problems/binary-search/

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>


class Solution {
public:
    int search(vector<int>& A, int targ) {
        //initilize
        int st = 0, end = A.size()-1;
        
        while(st <= end) {

            int mid = st + (end - st)/2;

            if(targ > A[mid]) {
                st = mid+1;
            } else if(targ < A[mid]) {
                end = mid-1;
            } else {
                return mid;
            }
        }

        return -1;    //when not found
    }
};


// puer Bimary search karga - O(log(n))