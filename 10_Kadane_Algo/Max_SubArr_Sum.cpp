



/*

qno 53   https://leetcode.com/problems/maximum-subarray/


recap on C:\Users\sanja\Desktop\GitProj\MyAdvDSA_PathwayToCP\0_Arjuna_CP\D41_Onward_Sem5\q1_maxSubArrSum_UsingKadaneAlgo.cpp


*/

#include <iostream>
#include <vector>
using namespace std;


// Max SubArr Sum using KADDANE'S algo
int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    for (int st = 0; st < n; st ++) {
        for (int end=st; end < n; end++) {
            for (int i=st; i<end; i++) {
                cout << arr[i];
            }
            cout << " ";

        }
        cout << endl;
    }
    return 0;
}

// Brute Force approach
// Max SubArr Sum using KADDANE'S algo
int main() {
    int n = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    // Brute Force approach
    int maxSum = INT8_MAX;

    for (int st = 0; st < n; st ++) {
        int currSum = 0;
        for (int end=st; end < n; end++) {
            currSum += arr[end];
            maxSum = max(currSum, maxSum);

        }
    }
    cout << "max subarray sum = " << maxSum << endl;
    return 0;

    // Kadane's algo
    