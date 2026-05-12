

/*

print all primeNo in range of 2 to n

In C++, modularity is the practice of breaking a large, complex program into smaller, independent, and
 manageable pieces called modules. Each module handles a specific part of the program's functionality and can be developed, tested,
  and maintained separately before being combined into a single system.

  
*/


#include <iostream>
using namespace std;

bool isPrime(int num) {
    if(num <= 1) return false;
    
    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            return false;  //moreThan2 factors
        }
    }
    return true;
}


void printAllPrime(int n) {  //tc=O(n* sqrt(n)), sc=O(1)
    for(int i=2; i <= n; i++) {

        if(isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}


void generalPrintPrime(int firstNo, int lastNo) {
    for(int i = firstNo; i <= lastNo; i++) {
        if(isPrime(i)) {
            cout << i << " ";  //primeNo with spaces
        }
    }
    cout << endl;  //newLine
}



int main() {
    int n = 10;
    int firstNo = 5, lastNo = 50;

    cout <<  "All primeNo b/w 2 to n: "; 
    printAllPrime(n);

    //cout << "All the prime b/w firstNo and lastNo are: ";
    //generalPrintPrime(10, 50); 
    cout << "All the prime b/w "<< firstNo << " and " << lastNo << " are: ";
    generalPrintPrime(firstNo, lastNo);
    

    return 0;
}