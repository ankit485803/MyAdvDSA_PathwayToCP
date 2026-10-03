

/*

3rd Oct 2026 (Saturday)

Anagram word: aisa word jo derived from the same word's char but the waska arrangement different ho


*/

#include <iostream>
#include <string>
using namespace std;


bool isAnagram(string str1, string str2) {
    if(str1.length() != str2.length()) {  //baseCase
        cout << "not valid anagram\n";
        return false;
    }

    //step1: store count of char
    int count[26] = {0};
    for(int i=0; i < str1.length(); i++) {
        int idx = str1[i] - 'a';
        count[idx]++;
    }

    //step2: traverse str2
    for(int i=0; i < str2.length(); i++) {
        int idx = str2[i] - 'a';
        if(count[idx] == 0) {
            cout << "not valid anagram\n";
            return false;
        }
        count[idx]--;
    }

    cout << "valid anagram\n";
    return true;
}


int main() {
    string str1 = "anagram";
    string str2 = "nagaram";

    isAnagram(str1, str2);

    return 0;
}