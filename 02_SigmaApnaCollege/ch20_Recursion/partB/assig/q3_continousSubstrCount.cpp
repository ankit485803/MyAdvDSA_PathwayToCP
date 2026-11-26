

/*

Question 3 : We are given a string S, we need to find the count of all contiguous 
substrings starting and ending with the same character. [Leetcode Premium Qs] 


Sample Input 1 : S = "abcab" 
Sample Output 1 : 7 
There are 15 substrings of "abcab" : a, ab, abc, abca, abcab, b, bc, bca, bcab, c, ca, cab, a, 
ab, b 
Out of the above substrings, there are 7 substrings : a, abca, b, bcab, c, a and b. So, only 
7 contiguous substrings start and end with the same character. 


Sample Input 2 : S = "aba" Sample 
Output 2 : 4 
The substrings are a, b, a and aba

*/


#include <iostream>
#include <string>
using namespace std;

int countSubstr(string s, int i, int j) {

    // Base case
    if (i == s.length()) {
        return 0;
    }

    if (j == s.length()) {
        return countSubstr(s, i + 1, i + 1);
    }

    int count = 0;

    // Check starting and ending characters
    if (s[i] == s[j]) {
        count = 1;
    }

    // Recursive call
    return count + countSubstr(s, i, j + 1);
}

int main() {
    string s = "abcab";

    cout << countSubstr(s, 0, 0);
    cout << endl;

    return 0;
}


// tc=o(n^2) checks all possible starting and ending index combinations.
// sc=O(n^2) maximum recursive call stack depth in this implementation.