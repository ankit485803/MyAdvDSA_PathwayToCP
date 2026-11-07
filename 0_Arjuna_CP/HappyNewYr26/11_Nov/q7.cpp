
//7th Nov 2026 (Saturday)
qno 1882 https://leetcode.com/problems/process-tasks-using-servers

//Approach (2 Max Heaps)
//T.C : O((n+m)*logn)
//S.C : O(n)
class Solution {
public:
    typedef pair<int, int> P; //wt, idx
    typedef tuple<long, int, int> T; //finTime, wt, idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        //free servers (wt, idx)
        priority_queue<P, vector<P>, greater<P>> freeServers;

        ///Busy servers {fintTime, wt, idx}
        priority_queue<T, vector<T>, greater<T>> busyServers;

        for(int i = 0; i < n; i++) { //n
            freeServers.push({servers[i], i}); //log(n)
        }

        vector<int> result(m);

        for(int i = 0; i < m; i++) { //
            //Move busy servers to free servers if they are free by ith time
            //Busy Servers ---> Free Servers
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt, idx});
            }

            //Free Servers ---> Busy Server

            if(freeServers.empty()) {
                auto [finTime, wt, idx] = busyServers.top();
                busyServers.pop();
                result[i] = idx;
                busyServers.push({finTime + tasks[i], wt, idx});
            } else { //Free Servers ---> Busy Server //(all servers move to busy for all tasks)
                auto [wt, idx] = freeServers.top();
                freeServers.pop();
                result[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});
            }
        }
        //Tota m tasks * log(n) push/pop = Overall time compelxity of this entire for loop

        return result;
    }
};