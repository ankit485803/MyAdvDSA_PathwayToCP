


/* 7th April 2025 (Monday - Day12)

https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1


You are given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.

For example:

If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

Note:  Return -1 if you can't reach the end of the array.

Examples : 


Input: arr = [1, 4, 3, 2, 6, 7]
Output: 2 
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
Input: arr = [0, 10, 20]
Output: -1
Explanation: We cannot go anywhere from the 1st element.




solution by GreedyApproach
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        
        
        int n = arr.size();
        if(n <= 1) return 0;  //already at end 
        if(arr[0] == 0) return -1;    //can't move at all
        
        
        int jumps = 0, currEnd = 0, farthest = 0;
        
        for(int i=0; i<n-1; i++) {
            farthest = max(farthest, i+ arr[i]);
            
            
            if(i == currEnd) {
                jumps++;
                currEnd = farthest;
                
                
                if(currEnd <= i) return -1;  //can't move forward
                
            }
        }
        
        return (currEnd >= n-1) ? jumps : -1;
        
        
        //solve by GreedyApproach TC=O(n), SC=O(1)
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends







//print N to 1 without loop
void print_Nto1(int N) {
    if(N == 0) return;

    cout << N << " ";  //print currNo
    print_Nto1(N - 1);  //recursiveCall
}



//print 1 to N without loop
void print_1toN(int N) {
    if(N == 0) return;

    print_Nto1(N - 1);
    cout << N << " ";
}


// print GFG n times
void print_GFG(int n) {
    if(n == 0) return;  //baseCase

    print_GFG(n-1);
    cout << "GFG" << " "; 
}

