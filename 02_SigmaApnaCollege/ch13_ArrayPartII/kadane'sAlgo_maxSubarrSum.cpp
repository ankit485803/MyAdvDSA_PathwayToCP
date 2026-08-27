

/*

27th Aug 2026 (Thursday)

Kadane's Algo is to find the maxSubarrSum, eska beautify yah hai ki jab currSum < 0 ho the value ko reinitialize kar do

*/

#include <iostream>
using namespace std;
#include <climits>


void maxSubarrSum_usingKadane(int *arr, int n) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0; i<n; i++) {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);
        
        if(currSum < 0) {
            currSum = 0;
        }
    }

    cout << "max subarr sum = " << maxSum << endl;
}


int main() {
    int arr[] = {2, 3, 6, -5, 4};
    int n = sizeof(arr) / sizeof(int);

    maxSubarrSum_usingKadane(arr, n);

    return 0;
}
