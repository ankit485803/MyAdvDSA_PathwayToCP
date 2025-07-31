





/*

6th April 2025 (Sunday) Gas statio LecNo 82 Shardha Di

 qno 134  https://leetcode.com/problems/gas-station/description/

 concept used: array and greedy

*/


class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int totGas = 0, totCost = 0;
    
            for(int val : gas) {
                totGas += val;
            }
    
            for(int val : cost) {
                totCost += val;
            }
    
    
            if(totGas < totCost) {
                return -1;
            }
    
    
            //unique solution always exists
            int start = 0, currGas = 0;
    
            for(int i=0; i<gas.size(); i++) {
                currGas += (gas[i] - cost[i]);
    
                if(currGas < 0) {
                    start = i+1;
                    currGas = 0;
                }
            }
    
            return start;
            
        }
    };
    
    
    // using Greedy approach, TC = O(n), SC = O(1)




//optimize 


class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int totGas = 0, totCost = 0;
    
    
    
    
            //unique solution always exists
            int start = 0, currGas = 0;
    
            for(int i=0; i<gas.size(); i++) {
                //optimize calculate gas here instead of outside
                totGas += gas[i];
                totCost += cost[i];
    
                currGas += (gas[i] - cost[i]);
    
                if(currGas < 0) {
                    start = i+1;
                    currGas = 0;
                }
            }
    
            
            // if(totGas < totCost) {
            //     return -1;
            // }
    
            // return start;
    
    
            return totGas < totCost ? -1 : start;
            
        }
    };
    
    
    // using Greedy approach, TC = O(n), SC = O(1)