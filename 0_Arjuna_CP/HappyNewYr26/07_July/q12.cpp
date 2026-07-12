
qno 1331 https://leetcode.com/problems/rank-transform-of-an-array/

//Approach - Sort and use map
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> temp(arr);
        sort(begin(temp), end(temp));

        int rank = 1;
        unordered_map<int, int> rankMap;
        vector<int> result(n);

        for(int i = 0; i < n; i++) {
            if(i > 0 && temp[i] > temp[i-1]) {
                rank++;
            }
            rankMap[temp[i]] = rank;
        }

        for(int i = 0; i < n; i++) {
            result[i] = rankMap[arr[i]];
        }

        return result;

    }
};