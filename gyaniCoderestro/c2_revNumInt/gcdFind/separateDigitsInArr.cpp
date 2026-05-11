
/*
11th May 2026 (Monday)

qno 2553  https://leetcode.com/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-11

*/


class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {  //tc=O(totalDigits), sc=O(1)
        vector<int> ans;

        for(int num : nums) {
            string s = to_string(num);  //convert int to str

            //now mainLogic
            for(char ch : s) {
                ans.push_back(ch - '0');  //push into ans
            }
        }

        return ans;
    }
};





// method2 without string
class Solution {
public:
    
    vector<int> helperSeparate(int num) {
        vector<int> temp;

        // extract digits from last
        while(num > 0) {
            int digit = num % 10;
            temp.push_back(digit);
            num /= 10;
        }

        // reverse order to maintain original sequence
        reverse(temp.begin(), temp.end());

        return temp;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            vector<int> digits = helperSeparate(nums[i]);

            for(int d : digits) {
                ans.push_back(d);
            }
        }

        return ans;
    }
};