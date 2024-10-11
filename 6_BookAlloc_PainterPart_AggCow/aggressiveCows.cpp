

// https://www.spoj.com/problems/AGGRCOW/

/* Prob
Assign C cows to N stalls such that minimum distance between them is largest possible.
Return largest minimum distance, if late then cow fight because she is very aggresive

this is similar to book alloc wala ques

*/

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>


int isPossible(vector<int> &arr, int N, int C, int minAllowedDist) {    //complex = O(n)
    int cows = 1, lastStallPos = arr[0];

    for(int i=0; i<N; i++) {
        if(arr[i]-lastStallPos >= minAllowedDist) {
            cows++;
            lastStallPos = arr[i];
        }

        if(cows == C) {
            return true;
        }
    }

    return false;
}



int getDistance(vector<int> &arr, int N, int C) {
    sort(arr.begin(), arr.end());

    int st = 1, end = arr[N-1] - arr[0], ans = -1;

    while(st <= end) {     //complex = O(log(RANGE))
        int mid = st + (end-st)/2;

        if(isPossible(arr, N, C, mid)) {   //RIGHT
            ans = mid;
            st = mid + 1;

        } else {  //LEFT
            end = mid - 1;
        }
    }

    return ans;

}






int main() {
    int N = 5, C = 3;
    vector<int> arr = {1, 2, 8, 4, 9};

    cout << getDistance(arr, N, C) << endl;
    return 0;
}



// total complex = O(log(RANGE) * n)


// pattern obeserve from all 3 ques 