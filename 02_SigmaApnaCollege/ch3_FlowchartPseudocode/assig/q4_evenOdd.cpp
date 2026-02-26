

/*
Question 4 : Flowchart & Pseudocode to print if a number N is EVEN or ODD.
Input : n
Output: Even or Odd

*/

#include <iostream>
using namespace std;

bool isEvenOdd(int n) {
    if(n % 2 == 0) {
        return true;
        cout << "EVEN" << endl;
    } else {
        return false;
        cout << "ODD " << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "The number " << n << " is " << isEvenOdd(n) << endl;
    
    return 0;
}



/*
sanja@IITP:/mnt/c/Users/sanja/Desktop/Lab$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/Lab$ ./codeRunFile.exe
Enter n: 44
The number 44 is 1
sanja@IITP:/mnt/c/Users/sanja/Desktop/Lab$

🔎 Why It Prints 1
Your function returns a bool.
In C++:
    true → prints as 1
    false → prints as 0



❌ Another Problem in Your Code
Inside your function:
⚠️ Anything written after return never executes.
Because return immediately exits the functio


*/



#include <iostream>
using namespace std;

bool isEven(int n) {
    return (n % 2 == 0);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (isEven(n))
        cout << "The number " << n << " is EVEN" << endl;
    else
        cout << "The number " << n << " is ODD" << endl;

    return 0;
}