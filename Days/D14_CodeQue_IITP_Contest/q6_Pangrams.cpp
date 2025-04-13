
/*
https://www.hackerrank.com/contests/codequest-iitp/challenges/pangrams



A pangram is a string that contains every letter of the alphabet. Given a sentence determine whether it is a pangram in the English alphabet. Ignore case. Return either pangram or not pangram as appropriate.

Example

The string contains all letters in the English alphabet, so return pangram.

Function Description

Complete the function pangrams in the editor below. It should return the string pangram if the input string is a pangram. Otherwise, it should return not pangram.

pangrams has the following parameter(s):

string s: a string to test
Returns

string: either pangram or not pangram
Input Format

A single line with string .

Constraints


*/





string pangrams(string s) {
    vector<bool> seen(26, false);
    int count = 0;

    for (char c : s) {
        if (isalpha(c)) {
            c = tolower(c);
            int index = c - 'a';
            if (!seen[index]) {
                seen[index] = true;
                count++;
            }
        }
    }

    return count == 26 ? "pangram" : "not pangram";
}
