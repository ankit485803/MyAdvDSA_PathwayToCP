
// src of ques   https://leetcode.com/problems/container-with-most-water/description/
//concept: arrary

// method 1: Bruter force approach, time complexity = 
// pahle find out all possible container with pick 2 lines at a time, fir jake max value wala container ko print kar dege

// nested loop: 1st = n time and  2nd = n times; time complexity of nested loop = O(n^2) which is quadratic 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int maxArea(vector<int>& height) {
        int maxWater = 0;

        for(int i=0; i<height.size(); i++) {   //left boundary
            for(int j=i+1; j<height.size(); j++) {  //RB
                int w = j-i;
                int ht = min(height[i], height[j]);   //water ko controll karte h small wala,arna owerflow hoga
                int currWater = w * ht;

                maxWater = max(currWater, maxWater);
            }
        }
        return maxWater;
    }
};

// concept and code wise correct ans hai, but leetcode error dega, TLE (Time Limit Exceeded)
// because 10^5 given hai, we take 10^8 operation

// then we should Approach - nlog(n) or O(n)

//method2: two poiner appoach, jo hm PALIDRONE wala ques

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp=0, rp=height.size()-1;

        while(lp < rp) {
            int w = rp-lp;
            int ht = min(height[lp], height[rp]);
            int currWater = w * ht;
            maxWater = max(currWater, maxWater);

             // Move the pointer pointing to the shorter line
            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxWater;
    }
};

// time Compleaxity = O(n), We used to painted approach instead of normal approach,
// because it reduced QUADRATIC time complexity to the LINEAR 