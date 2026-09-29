

/*

29th Sep 2026 (Tuesday - book delivered The Intelligence  Investor)

How to take input in character array


*/

#include <iostream>
using namespace std;
#include <cstring>


int main() {
    // char word[30];
    // cin >> word;  //yah ignore karna hai whitespace

    // cout << "your word is : " << word << endl;
    // cout << "length = " << strlen(word) << endl;


    char sentence[30];
    cin.getline(sentence, 30);  
    cin.getline(sentence, 30, '*');  //yaha pe third argument delimiter hota hai  jo not print after 

    cout << "your sentence is : " << sentence << endl;
    cout << "length = " << strlen(sentence) << endl;

    return 0;
}