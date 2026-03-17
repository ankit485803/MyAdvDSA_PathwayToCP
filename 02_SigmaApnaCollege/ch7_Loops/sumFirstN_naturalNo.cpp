

//sum of first N natural no using iterative not mathematical formual sum = n(n+1)/2

#include <iostream>
using namespace std;

int main() {
 
    int N;
    cout << "Enter N: ";
    cin >> N;

    int sum = 0; 
    for(int i=0; i < N + 1; i++) {
        sum += i;
    }
    cout << "sum = " sum << endl;

    return 0;
}


/*

sanja@IITP:/mnt/c/Users/sanja/Desktop/Lab$ g++ sigmaApnaCollege.cpp -o codeRunFile.exe
sanja@IITP:/mnt/c/Users/sanja/Desktop/Lab$ ./codeRunFile.exe
536788995
sanja@IITP:/mnt/c/Users/sanja/Desktop/Lab$

yah ek garbage value hai
You declared N but never initialized it 👉 Since N has no value, it contains random garbage from memory, like 536788995.
for(int i = 0; i < 536788995; i++)




*/



#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;   // take input

    int sum = N * (N + 1) / 2;   //usingFormula

    cout << "sum = " <<  sum << endl;

    return 0;
}