

/*

Question 5 : Write a function that accepts a character (ch) as parameters & returns
the character that occurs after ch in the English alphabet.

Eg : input = ‘c’, return value = ‘d’
Note : for ch = ‘z’, return ‘a’

we know all int or char store in ASCII value internally

| Data Type | Space Complexity |
| --------- | ---------------- |
| `char`    | `O(1)`           |
| `int`     | `O(1)`           |
| `float`   | `O(1)`           |
| `string`  | Usually `O(n)`   |

*/


#include <iostream>
using namespace std;
#include <string>  //req


string nextChPrint(char c) {
    char result = 'c' + 1;  //we know all int or char store in ASCII value internally

    return result;
}


char nextChPrint(char c) {
    char r = c + 1;  

    return r;
}


// Function to return next character
char nextCharacter(char c) {

    if (c == 'z') {  //baseCase as per ques
        return 'a';
    }

    return c + 1;
}




int main() {
    char ch = 'f';
    
    cout << "Next char after {" << ch << "} = " << nextChPrint(ch) << endl;

    return 0;
}



/*
output

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
sigmaApnaCollege.cpp: In function ‘std::string nextChPrint(char)’:
sigmaApnaCollege.cpp:9:12: error: could not convert ‘result’ from ‘char’ to ‘std::string’ {aka ‘std::__cxx11::basic_string<char>’}
    9 |     return result;
      |            ^~~~~~
      |            |
      |            char
sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$




*/



#include <iostream>
using namespace std;

// Function to return next character
char nextCharacter(char c) {

    if (c == 'z') {
        return 'a';
    }

    return c + 1;
}

int main() {

    char ch = 'f';

    cout << "Next char after {"
         << ch << "} = "
         << nextCharacter(ch)
         << endl;

    return 0;
}


git commit -m "feat(sigmaApnaCollege): done all the Assig 5 ques of thisChap string (ch9)"
