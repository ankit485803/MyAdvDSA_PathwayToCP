
git commit -m "feat(sigmaApnaCollege): complete this chap by covering last topics: memberFunc, forEach loop, operator, validAnagram (ch16_string)" 
/*

4th Oct 2026 (Sunday)

Question 1 : Count how many times lowercase vowels occurred in a String entered 
by the user.


Yes, you can change the function type to void, but because void functions cannot return a value,
 you must print the result inside the function instead of using return count;.



function name can be: getVowelCount 
areAlmostEqual

*/


#include <iostream>
#include <string>
using namespace std;


int countLowerVowel(string str) {
    int count = 0;

    for(int i=0; i < str.length(); i++) {
        if(str[i] == 'a' || str[i] ==  'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {   //these 5 vowels using OR operator 
            count++;
        }
    }
    return count;
}


void countLowerVowel(string str) {  //tc=O(n) strLength, sc=O(1)
    int vowCount = 0;

    for(int i=0; i < str.length(); i++) {
        if(str[i] == 'a' || str[i] ==  'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {   
            vowCount++;
        }
    }

    cout << "no of lowercase vowels = " << vowCount << endl;
}



int main() {
    string str = "applE";

    //cout << "no of lowercase vowels = " << countLowerVowel(str) << endl;
    countLowerVowel(str);

    return 0;
}