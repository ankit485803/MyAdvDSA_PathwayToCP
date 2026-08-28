

/*

28th Aug 2026 (Friday - Happy Raksha Bandhan)

same concepts used in leetcode probNo 42  https://leetcode.com/problems/trapping-rain-water/description/

*/


#include <iostream>
using namespace std;
#include <climits>


void trapWater(int *heights, int n) {
    int leftMax[20000];
    leftMax[0] = INT_MIN;

    for(int i=0; i<n; i++) {
        leftMax[i] = max(leftMax[i-1], heights[i-1]);
        cout << leftMax[i] << ",";
    }

    cout << endl;
}

int main() {
    int heights[7] = {4, 2, 0, 6, 3, 2 ,5};
    int n = sizeof(heights) / sizeof(int);
    
    trapWater(heights, n);

    return 0;
}



#include <iostream>
#include <climits>
using namespace std;

int trapWater(int *heights, int n) {
    int leftMax[20000], rightMax[20000];

    leftMax[0] = heights[0];
    rightMax[n - 1] = heights[n - 1];

    // Calculate left maximum
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], heights[i]);
    }

    // Calculate right maximum
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], heights[i]);
    }

    int waterTrapped = 0;

    for (int i = 0; i < n; i++) {
        int currWater = min(leftMax[i], rightMax[i]) - heights[i];

        if (currWater > 0) {
            waterTrapped += currWater;
        }
    }

    cout << "my water trapped = " << waterTrapped << endl;

    return waterTrapped;
}

int main() {
    int heights[7] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(heights) / sizeof(int);

    trapWater(heights, n);

    return 0;
}


git commit -m "feat(sigmaApnaCollege): complete this chapter and trappingRainwater, buySellStocks prob  (ch13 arrPart II)" 