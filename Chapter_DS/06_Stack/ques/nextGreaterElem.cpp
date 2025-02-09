


#include <iostream>
#include <stack>
#include <vector>
using namespace std;


/*


arr[i] --> immediately greater 
i -> right

threee things:
1.  right ele
2. greater than curr ele
3. immediately




*/



int main() {


    vector<int> arr = {6, 8, 0, 1, 3};


    //next greater ele
    stack<int> s;
    vector<int> ans(arr.size(), 0);


    for(int i=arr.size()-1; i>=0; i--) {  // O(n) yaha while loop only sirf updation ka kam kar raha h -- O(n) + O(n)
        while(s.size() > 0 &&  s.top()  <= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }


    //printing ans
    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}




// TC = O(n) = SC

// qno 490  https://leetcode.com/problems/next-greater-element-i/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;   // Map to store the next greater element for nums2
        stack<int> s;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // Pop elements from the stack that are smaller than or equal to nums2[i]
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            // If the stack is empty, there's no greater element for nums2[i]
            if (s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }

            // Push the current element onto the stack
            s.push(nums2[i]);
        }

        // Step 2: Generate the result for nums1 using the map
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }

        return ans;  // Return the result
    }
};

// Test the solution
int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
