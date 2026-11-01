
git commit -m "feat(sigmaApnaCollege): start newChap and covers access (ch20_Recursion)" 

/*


31st Oct 2026 (Saturday)



*/

#include <iostream>
using namespace std;

//recursion funct 
void func() {
    cout << "function call..work\n";
    func();
}


//factorial
int factorial(int n) {
    if(n == 0) {  //baseCase matlab wah smallestProb mika value pata ho
        return  1;
    }

    return n * factorial(n-1);
}

int main() {
    //func();

    int ans = factorial(5);
    cout << "factorial = " << ans << endl;

    return 0;
}