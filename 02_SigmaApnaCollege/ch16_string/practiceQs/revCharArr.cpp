
git commit -m "feat(sigmaApnaCollege): convert charArr input and convertToUppercase, lowercase (ch16_string)" 
/*

30th Sep 2026 (Wednesday)

reverse charArr using two pointer approach


*/

#include <iostream>
#include <cstring>
using namespace std;


void reverseChar(char word[], int n) {  //tc=O(n), sc=O(1)
    int st = 0, end = n - 1;

    while(st < end) {  //yaha equality hold nahi karta hai because ODD ke case mai same ko reswap karta
        swap(word[st], word[end]);
        st++;
        end--;
    }
}


int main() {
    char word[] = "code";

    reverseChar(word, strlen(word));
    cout << "reverse = " << word << endl;

    return 0;
}


void reverseChar(char word[], int n) {  //both same
    int st = 0, end = n - 1;

    while(st < end) {  
        swap(word[st++], word[end--]);
        // st++;
        // end--;
    }
}
