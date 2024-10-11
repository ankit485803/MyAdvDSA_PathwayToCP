
// https://www.hackerearth.com/problem/algorithm/painters-partition/

// concept - alternate of Binary Search, similar to Book Allocation prob

/* Prob:
Given N Board of length of each given in the form of arr and M Painters such that
 each painter takes  one unit of time to a paint, 1 unit of board

N = board leng in arrary form, M = no of painters

Q. The task is to find the minimum time paint all boards under the constraint that any painter will only continuous section of board.

*/
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>

// code ko Part A (minTimeToPaint) + B (isPossible) mai divide karte h

//funct to check possible
int isPossible(vector<int> &arr, int n, int m, int maxAllowedTime) {
    int painter = 1, time = 0;


    for(int i=0; i<n; i++) {   //ADDING
        if(time + arr[i] <= maxAllowedTime) {
            time += arr[i];

        } else {
            painter ++;
            time = arr[i];
        }
    }

    // return painter > m ? false : true;
    return painter <= m;
}



// minimun Time to paint wala funct
int minTimeToPaint(vector<int> &arr, int n, int m) {
    int sum = 0, maxVal = INT8_MIN;
    for(int i=0; i<n; i++) {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, ans = -1;    //aab RANGE mil gaya hmko

    while(st <= end) {
        int mid = st + (end-st)/2;

        if(isPossible(arr, n, m, mid)) {  //LEFT
            ans = mid;
            end = mid -1;

        }  else {  //RIGHT
            st = mid + 1;
        }
    }

    return ans;
    
}






//main funt
int main() {
    vector<int> arr = {40, 30, 10, 20};
    int n = 4, m = 2;      //n = no of books, m = no of student 

    cout << minTimeToPaint(arr, n, m) << endl;
    return 0;

}



// time complex = O(log(sum) * n)
