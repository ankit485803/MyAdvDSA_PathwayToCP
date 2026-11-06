6th Nov 2026 (Friday)

//Approach (Sorting + Sliding Window)
//T.C : O(nlogn + qlogq), n = log.size(), q = query.size()
//S.C : O(n + q)
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m = logs.size();

        auto lambda = [](vector<int>& vec1, vector<int>& vec2) {
            return vec1[1] < vec2[1];
        };

        sort(begin(logs), end(logs), lambda);

        int q = queries.size();
        vector<pair<int,int>> timeIndex(q);     // {time, original idx}
        for (int i = 0; i < q; i++) 
            timeIndex[i] = {queries[i], i};

        sort(begin(timeIndex), end(timeIndex));

        unordered_map<int,int> mp;              //count unique servers in the window
        vector<int> result(q);

        int i = 0, j = 0;
        for (auto [curtime, ind] : timeIndex) {
            int start = curtime - x;
            int end   = curtime;

            // right expand: time <= end
            while (j < m && logs[j][1] <= end) {
                mp[logs[j][0]]++;
                j++;
            }

            // left shrink: time < start
            while (i < m && logs[i][1] < start) {
                mp[logs[i][0]]--;
                if (mp[logs[i][0]] == 0) 
                    mp.erase(logs[i][0]);
                
                i++;
            }

            //mp.size() unique servers got requests. So, n - mp.size() did not recieve requests 
            result[ind] = n - mp.size();
        }

        return result;
    }
};
