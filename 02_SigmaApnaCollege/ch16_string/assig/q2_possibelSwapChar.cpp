

/*

Question 2 : You are given two strings s1 and s2 of equal length. A string swap is an 
operation where you choose two indices in a string (not necessarily different) and 
swap the characters at these indices. 
Return true if it is possible to make both strings equal by performing at most one 
string swap on exactly one of the strings. Otherwise, return false. 
Example : 
Input: s1 = "bank", s2 = "kanb" Output: 
true 
Explanation: For example, swap the first character with the last character of s2 to 
make "bank".


*/


#include <iostream>
#include <string>
using namespace std;


bool isPossibleStrOneSwap(string s1, string s2) {  //bruteForce: iterate to eachChar and check using nestedLoop tc=O(n^2), sc=O(1)
    int count = 0; //swapping count

    for(int i=0; i < s1.length(); i++) {
        for(int j=0; j < s2.length(); j++) {
            if(s1[i] != s2[j]) {  //mainLogic: jo equal nahi hoga usko cont diffChar then return jab count 1
                count++;
            }
        }
    }

    return count == 1;
} //firstAttempt wrong


int main() {
    string s1 = "bank", s2 = "kanb";

    if(isPossibleStrOneSwap(s1, s2)) {
        cout << "true" << endl;
    } else {
        cout << "false, not possible to make str same using one swap" << endl;
    }

    return 0;
}


bool isPossibleStrOneSwap(string s1, string s2) {
    if(s1.length() != s2.length()) {  //baseCase
        return false;
    }

    int first = -1;
    int second = -1;
    int count = 0;

    for(int i = 0; i < s1.length(); i++) {  //tc=O(n)  one pass through the strings, sc=O(1)
        if(s1[i] != s2[i]) {
            count++;

            if(count == 1)
                first = i;
            else if(count == 2)
                second = i;
            else
                return false;  // more than 2 differences
        }
    }

    // Already equal → swap same index with itself
    if(count == 0)
        return true;

    // Exactly 2 differences → check whether swapping fixes them
    if(count == 2 &&
       s1[first] == s2[second] &&
       s1[second] == s2[first]) {
        return true;
    }

    return false;
}



//approach2: using vector DS
bool isPossibleStrOneSwap(string s1, string s2) {

    if(s1.length() != s2.length()) {
        return false;
    }

    vector<int> diff;

    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] != s2[i]) {
            diff.push_back(i);
        }
    }

    if(diff.size() == 0) {
        return true;
    }

    if(diff.size() != 2) {
        return false;
    }

    return s1[diff[0]] == s2[diff[1]] &&
           s1[diff[1]] == s2[diff[0]];
}
