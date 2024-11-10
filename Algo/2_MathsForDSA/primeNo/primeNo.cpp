
#include <iostream>
using namespace std;



/* Prime Number

n:  if 2  to   root2, if divisible then nonPrime, else prime

for(i = 2;  i*i <= n;  i++) {

    if(n % i == 0) {
        return "Not a prime no"
        }

        return "Prime"
    
    }


*/


string isPrime(int n) {
    
    for(int i=2;  i*i <= n; i++) {   //O(n)
        if(n % i == 0) {
            return "Non prime";
        }

    }

    return "Prime";   //when not divisible by any other no
}



int main() {
    int n = 42;
    int n2 = 41;

    cout << isPrime(n2) << endl;


    return 0;
}


// TC = O(n), SC = O(1)