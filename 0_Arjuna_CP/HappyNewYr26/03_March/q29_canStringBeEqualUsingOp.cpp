


/*


29th March 2026 (Sunday)


qno 2839 https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/?envType=daily-question&envId=2026-03-29


2839. Check if Strings Can be Made Equal With Operations I
Attempted
Easy
Topics
premium lock icon
Companies
Hint
You are given two strings s1 and s2, both of length 4, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that j - i = 2, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

 

Example 1:

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: We can do the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbad".
- Choose the indices i = 1, j = 3. The resulting string is s1 = "cdab" = s2.
Example 2:

Input: s1 = "abcd", s2 = "dacb"
Output: false
Explanation: It is not possible to make the two strings equal.
 

Constraints:

s1.length == s2.length == 4
s1 and s2 consist only of lowercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
51,751/102.9K
Acceptance Rate
50.3%
Topics
Mid Level
String
Biweekly Contest 112



*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {  //wrongAns
        //bruteForce: constaint is too small 

        int i = 0, j = 2;  //j-i = 2

        while(i <= 3 && j <= 3) {  //size 4 only
            if(s1[i][j]  !=  s2[i][j] ) {
                swap(s1[i][j] );  //we applied to s1 
                i++;
                j++;
            }
        }

        return s1 == s2;
        
    }
};


/*
💡 Why sorting helps

Remember:
You can swap index 0 ↔ 2
So "ac" and "ca" are effectively the same group
👉 Sorting makes both forms identical



🧩 Internally (for small size)
For 2 elements, sort() basically does:
if (a1[0] > a1[1]) swap(a1[0], a1[1]);
That’s it — just one comparison!

🚀 Final intuition
👉 Sorting is just a tool to check:
“Do both groups contain the same letters, regardless of order?”


*/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {  //tc=O(1)=sc
        // group 1: indices 0 and 2
        string a1 = {s1[0], s1[2]};
        string a2 = {s2[0], s2[2]};
        
        // group 2: indices 1 and 3
        string b1 = {s1[1], s1[3]};
        string b2 = {s2[1], s2[3]};
        
        sort(a1.begin(), a1.end());
        sort(a2.begin(), a2.end());
        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());
        
        return (a1 == a2) && (b1 == b2);
    }
};




return (
    (s1[0] == s2[0] && s1[2] == s2[2] || s1[0] == s2[2] && s1[2] == s2[0]) &&
    (s1[1] == s2[1] && s1[3] == s2[3] || s1[1] == s2[3] && s1[3] == s2[1])
);



vector<int> even1(26), even2(26);  //for general
vector<int> odd1(26), odd2(26);

for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
        even1[s1[i] - 'a']++;
        even2[s2[i] - 'a']++;
    } else {
        odd1[s1[i] - 'a']++;
        odd2[s2[i] - 'a']++;
    }
}

return even1 == even2 && odd1 == odd2;


//Approach-1 (Constant time check of 0,2 and 1,3 indices)
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        //index 0 and 2
        bool condition1 = (s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0]);


        //index 1 and 3
        bool condition2 = (s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]);

        return condition1 && condition2;
    }
};



//Approach-2 - Using map for grouping even and odd indices
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};

        int n = s1.length();

        for(int i = 0; i < 4; i++) {
            if(i%2 == 0) { //even indices
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else { //odd indices
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0 || odd[i] != 0)
                return false;
        }

        return true;
    }
};



/*

qno 2840  https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/


2840. Check if Strings Can be Made Equal With Operations II
Medium
Topics

Companies
Hint
You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.

 

Example 1:

Input: s1 = "abcdba", s2 = "cabdab"
Output: true
Explanation: We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
- Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
- Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
Example 2:

Input: s1 = "abe", s2 = "bea"
Output: false
Explanation: It is not possible to make the two strings equal.
 

Constraints:

n == s1.length == s2.length
1 <= n <= 105
s1 and s2 consist only of lowercase English letters.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
31,985/56.6K
Acceptance Rate
56.5%
Topics
Senior
Hash Table
String
Sorting
Biweekly Contest 112


*/




//Approach - Using map for grouping even and odd indices
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};

        int n = s1.length();

        for(int i = 0; i < n; i++) {
            if(i%2 == 0) { //even indices
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else { //odd indices
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0 || odd[i] != 0)
                return false;
        }

        return true;
    }
};


