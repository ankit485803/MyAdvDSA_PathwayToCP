
git commit -m "feat(sigmaApnaCollege): complete this chap by covering last topics: memberFunc, forEach loop, operator, validAnagram (ch16_string)" 

/*

3rd Oct 2026 (Saturday)

Operators in c++ String

*/

#include <iostream>
#include <string>
using namespace std;


int main() {
    string str1 = "cat";
    string str2 = "dog";
    string str3 = "cat";

    cout << (str1 == str2) << endl;   //false output give 0 nahi to 1
    cout << (str1 != str2) << endl;
    cout << (str1 < str2) <<  endl;

    return 0;
}