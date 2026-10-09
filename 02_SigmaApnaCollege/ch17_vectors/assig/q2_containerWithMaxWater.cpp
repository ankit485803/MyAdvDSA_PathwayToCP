

/*

9th Oct 2026 (Friday)

leetcode probNo 11   https://leetcode.com/problems/container-with-most-water/description/



*/

class Solution {
public:
    int maxArea(vector<int>& height) { //2nd Oct 2024 submission
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

// time Compleaxity = O(n), We used to painted approach instead of normal approach, because it reduced quadratic time complexity to the linear 


class Solution {
public:
    int maxArea(vector<int>& height) {  //today 9th Oct 2026 (Friday sem7iitp)
        int st = 0;
        int end = height.size() - 1;
        int maxWater = 0;

        while (st < end) {
            int width = end - st;
            int h = min(height[st], height[end]);

            int area = width * h;
            maxWater = max(maxWater, area);

            // Move the pointer with smaller height
            if (height[st] < height[end]) {
                st++;
            } else {
                end--;
            }
        }

        return maxWater;
    }
};