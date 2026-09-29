

/*

29th Sep 2026 (Tuesday)

Convert all char into uppercase

position = word[i] - 'a';
for uppercase: word[i] = postion + 'A'  = word[i] - 'a' + 'A';


Your conversion logic is based on the ASCII relationship:
'a' → 'A'
'b' → 'B'
'c' → 'C'
...
'z' → 'Z'

The difference between lowercase and uppercase letters is 32.



*/


#include <iostream>
#include <cstring>
using namespace std;

void convertToUpper(char word[], int n) {  //tc=O(n), sc=O(1)

    for(int i=0; i<n; i++) {
        char ch = word[i];

        if(ch >= 'A' && ch <= 'Z') {  //uppercase 
            continue;
        } else {  //lowercase
            word[i] = ch - 'a' + 'A';
        }
    }
}

void convertToLower(char word[], int n) {
    for(int i=0; i<n; i++) {
        char ch = word[i];

        if(ch >= 'a' && ch <= 'z') {
            continue;
        } else {
            word[i] = ch - 'A' + 'a';
        }
    }
}


int main() {
    char word[] = "ApPle";
    
    convertToUpper(word, strlen(word));
    cout << word << endl;

    char word2[] = "ABcD";
    convertToLower(word2, strlen(word2));
    cout << word2 << endl;

    return 0;
}