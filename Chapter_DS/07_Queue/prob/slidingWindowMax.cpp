

// qno 239   https://leetcode.com/problems/sliding-window-maximum/


class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {  //O(n)
            deque<int> dq;  
            vector<int> res;
    
            //1st wind
            for(int i=0; i<k; i++) {  //O(k)
                while(dq.size() > 0 && nums[dq.back()] <= nums[i] )  {
                    dq.pop_back();
                }
    
                dq.push_back(i);
            }
    
            for(int i=k; i<nums.size(); i++) {  //O(n-k)
                res.push_back(nums[dq.front()]);
    
                //remove not part of curr wind
                while(dq.size() > 0 && dq.front() <= i-k) {
                    dq.pop_front();
                }
    
                //remove the smaller vals
                while(dq.size() > 0 && nums[dq.back()] <= nums[i] )  {
                    dq.pop_back();
                }
    
                dq.push_back(i);
    
            }
    
            res.push_back(nums[dq.front()]);
    
            return res;
        }
    };
    
    //TC = O(n) = SC