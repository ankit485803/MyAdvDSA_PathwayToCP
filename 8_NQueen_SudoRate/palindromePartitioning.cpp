

#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>



// qno 131   https://leetcode.com/problems/palindrome-partitioning/description/

/* concept req: Recursion & BackeTracking

Given a string s, partition s such that every substring of the partition is a  palindrome
 Return all possible palindrome partitioning of s.


*/



class Solution {
public:

    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }

    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans) {

        if(s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for(int i=0; i<s.size(); i++) {
            string part = s.substr(0, i+1);

            if(isPalin(part)) {
                partitions.push_back(part);
                getAllParts(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);   
        return ans;
    }
};


// TC = O(n * 2^n) 