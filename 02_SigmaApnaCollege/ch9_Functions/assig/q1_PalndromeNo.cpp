

/*

13th May 2026 (Wednesday) Assig 

Question 1 : Write a function to check if a number is a palindrome in C++.
(121 is a palindrome, 321 is not)

Anumber is called a palindrome if the number is equal to the reverse of a number.
Eg : 121 is a palindrome because the reverse of 121 is 121 itself. On the other hand,
321 is not a palindrome because the reverse of 321 is 123, which is not equal to 321

Base Dependence:
Palindromic properties depend on the base; a number can be a palindrome in base 
 but not in binary (base 
).

Similarly A palindromic word (or word palindrome) is a word that reads the same backward as forward.
Single-Letter Words: The words "I" and "A" are natural palindromes.eg Mom", "Dad", "Wow", "Eye", "Pop


*/
int revNumUsingStr(int num) {  //tc=O(n)=sc
    string s = to_string(num);
    reverse(s.begin(), s.end());

    int ans = stoi(s);  //convert string to integer
    return ans;
}


#include <iostream>
using namespace std;
#include <string>

int revNumIterative(int num) {  //tc=O(n), sc=O(1)
    int r = 0;
    while(num > 0) {
        r = r * 10 + (num % 10);  //r*10 + lastDigit
        num /= 10;  //removeLastD
    }
    return r;
}


bool isPalindromeNo(int numb) {
    int revNum = revNumIterative(numb);

    return (numb == revNum);
}

int main() {
    int numb = 12321;

    if(isPalindromeNo(numb)) {
        cout << numb << " is a Palindrome No" << "\n";
    } else {
        cout << numb << " is not palindrome" << "\n";
    }


    return 0;
}




#include <iostream>
#include <string>  //req STL
#include <algorithm>  //req
using namespace std;

bool isPalindromeWord(string word) {
    string rev = word;

    reverse(rev.begin(), rev.end());

    return (word == rev);
}

int main() {
    string word = "MADAM";

    if(isPalindromeWord(word)) {
        cout << word << " is a Palindrome Word" << "\n";
    }
    else {
        cout << word << " is NOT a Palindrome Word" << "\n";
    }

    return 0;
}