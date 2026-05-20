


/*

20th May 2026 (wednesday)


qno 2657  https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/?envType=daily-question&envId=2026-05-20

2657. Find the Prefix Common Array of Two Arrays
Solved
Medium
Topics

Companies
Hint
You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

 

Example 1:

Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
Example 2:

Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
 

Constraints:

1 <= A.length == B.length == n <= 50
1 <= A[i], B[i] <= n
It is guaranteed that A and B are both a permutation of n integers.
 
Discover more
Programming
Interview Prep Course
Seen this question in a real interview before?
1/6
Yes
No
Accepted
271,607/310.3K
Acceptance Rate
87.5%
Topics
Senior
Array
Hash Table
Bit Manipulation
Biweekly Contest 103


*/




class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {  //tc=O(n^3), sc=O(1) bruteForce
        int n = A.size();
        vector<int> result(n);

        for(int i=0; i<n; i++) {
            int count = 0;
            for(int x = 0; x <= i; x++) {
                //find if we have A[x] in B not till index i
                for(int y = 0; y <= i; y++) {  //B
                    if(B[y] == A[x]) {
                        count++;
                        break;
                    }
                }
            }

            result[i] = count;
        }

        return result;
    }
};




//Approach-1 (Brute Force)
//T.C : O(n^3)
//S.C : O(1)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        for(int i = 0 ; i < n; i++) {
            int count = 0;

            for(int x = 0; x <= i; x++) { //A
                //Find if we have A[x] in B or not till index i
                for(int y = 0; y <= i; y++) { //B
                    if(B[y] == A[x]) {
                        count++;
                        break;
                    }
                }
            }

            result[i] = count;

        }

        return result;
    }
};


//Approach-2 (Better Approach)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        vector<bool> isPresentA(n+1, false); //isPresent[i] = true, means i is present in A
        vector<bool> isPresentB(n+1, false); //....

        for(int i = 0; i < n; i++) {
            isPresentA[A[i]] = true;
            isPresentB[B[i]] = true;

            int count = 0;
            for(int num = 1; num <= n; num++) {
                if(isPresentA[num] == true && isPresentB[num] == true) {
                    count++;
                }
            }

            result[i] = count;
        }

        return result;
    }
};


//Approach-3 (Optimal Approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n);

        unordered_map<int, int> mp;

        int count = 0;
        for(int i = 0; i < n; i++) {
            mp[A[i]]++;
            if(mp[A[i]] == 2) {
                count++;
            }

            mp[B[i]]++;
            if(mp[B[i]] == 2) {
                count++;
            }

            result[i] = count;
        }

        return result;
    }
};