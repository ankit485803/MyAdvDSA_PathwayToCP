

/*

20th Aug 2026 (Thursday) max subarr Sum 


*/

#include <iostream>
using namespace std;
#include <climits> //for INT_MIN or INT_MAX

void maxSubarrSum(int *arr, int n) {
    for(int st = 0; st < n; st++) {
        for(int end = st; end < n; end++) {

            int currSum = 0;
            for(int i = st; i <= end; i++) {
                currSum += arr[i];
            }
            cout << currSum << ",";
        }

        cout << endl;
    }

}


int main() {
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    maxSubarrSum(arr, n);

    return 0;
}


/* OUTPUT
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
2,-1,5,0,4,6,
-3,3,-2,2,4,
6,1,5,7,
-5,-1,1,
4,6,
2,
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$

*/


void maxSubarrSum(int *arr, int n) {   //tc=O(n^3) bruteForce
    int maxSum = INT_MIN;

    for(int st = 0; st < n; st++) {
        for(int end = st; end < n; end++) {

            int currSum = 0;
            for(int i = st; i <= end; i++) {
                currSum += arr[i];
            }
            cout << currSum << ",";
            maxSum = max(maxSum, currSum);
            //max(a, max(b, c));  //for three num and similar min function built in
        }

        cout << endl;
    }

    cout << "maximum subarr sum = " << maxSum << endl;

}


//optimized bruteForce in which remove one loop completely  tc=O(n^2)
void maxSubarrSum(int *arr, int n) {
    int maxSum = INT_MIN;

    for(int st = 0; st < n; st++) {   //start = 2
        int currSum = 0;
        for(int end = st; end < n; end++) {  //end = 2, 3, 4, 5
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }

    cout << "maximum subarr sum = " << maxSum << endl;
}


git commit -m "feat(sigmaApnaCollege): cover topic printSubarr and maxSumSubarr (ch13 arrPart II)" 