
git commit -m "feat(sigmaApnaCollege): cover revChar and validPalindrome (ch16_string)" 

/*

Palindrome Word: jo starting and end se same ho word

same prob on leetcode ques no 125  https://leetcode.com/problems/valid-palindrome/submissions/1433307963/



*/

#include <iostream>
#include <cstring>  //for strlen function
using namespace std;


bool isPalindrome(char myStr[], int n) {  //tc=O(n), sc=O(1)
    int st = 0, end = n-1;

    while(st < end) {
        if(myStr[st++] != myStr[end--]) {
            cout << "not valid palindrome \n";
            return false;
            // st++;
            // end--;
        }
    }

    cout << "valid palindrome \n";
    return true;
}



int main() {
    char word[] = "racecar";

    isPalindrome(word, strlen(word));
    return 0;
}