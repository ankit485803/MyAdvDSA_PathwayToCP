

/*

print numb in decreasing order from n to 1

method1: using loop tc=O(n), sc=O(1)
for(int i=n; i>=1; i--) {
    cout << i << " ";
    cout << endl;
}


method2: using recursion tc=O(n)=sc

call stack
*/

#include <iostream>
using namespace std;


void printNum(int n) {
    //three thing: baseCase, hmko kya karna hai, and innerFun kya karega
    if(n == 0) {
        return;
    }

    cout << n << " ";  //kaam
    printNum(n-1);  //faith, next call by innerFun
}


void printNumAscending(int n) {
    //three thing: baseCase, hmko kya karna hai, and innerFun kya karega
    if(n == 0) {
        return;
    }

    printNumAscending(n-1);  //increasing order mai
    cout << n << " ";  
    
}


int main() {

    printNum(5);

    return 0;
}


void printNumUsingLoop(int n) {

    for(int i = n; i >= 1; i--) {
        cout << i << " ";
    }
}