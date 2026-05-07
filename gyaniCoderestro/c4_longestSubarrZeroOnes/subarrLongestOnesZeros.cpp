

/*

7th May 2026 (Thursday)

prob: find Longest subarray with equal number of 0s and 1s
Link: https://www.instagram.com/reel/DXorURZASIp   (27 April Mondau uploaded)


given arr A[7] = [0, 1, 0, 1, 0, 0, 1]
count of zeros = count of ones


method1: nestedLoop tc=O(n^2), sc=O(1)


method2: optimized convert all the zeros into -1 and then this prob become largest subarr with 0 sum and using hashmap + prefixSum tc=O(n)=sc

*/


#include <iostream>
#include <vector>
using namespace std;


int longestSubarrayEqual0and1(vector<int>& arr) {

    int n = arr.size();
    int maxLen = 0;

    // Generate all subarrays
    for(int start = 0; start < n; start++) {

        int count0 = 0;
        int count1 = 0;

        for(int end = start; end < n; end++) {

            // Count 0s and 1s
            if(arr[end] == 0) {
                count0++;
            }
            else {
                count1++;
            }

            // Equal number of 0s and 1s
            if(count0 == count1) {

                int currLen = end - start + 1;

                maxLen = max(maxLen, currLen);
            }
        }
    }

    return maxLen;
}

#include <unordered_map>

int main() {
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1};

    int ans = longestSubarrayEqual0and1(arr);
    cout << "Longest Length = " << ans;

    return 0;
}






// Optimized Approach
int maxLength(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> firstSeen;

    int prefixSum = 0;
    int maxLen = 0;

    firstSeen[0] = -1;

    for(int i = 0; i < n; i++) {

        // Convert:
        // 0 -> -1
        // 1 -> +1

        if(arr[i] == 0) {
            prefixSum += -1;
        }
        else {
            prefixSum += 1;
        }

        // First time prefixSum seen
        if(firstSeen.find(prefixSum) == firstSeen.end()) {

            firstSeen[prefixSum] = i;
        }
        else {

            int storedIndex = firstSeen[prefixSum];
            int length = i - storedIndex;
            maxLen = max(maxLen, length);
        }
    }

    return maxLen;
}


int main() {
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1};
    cout << maxLength(arr);

    return 0;
}