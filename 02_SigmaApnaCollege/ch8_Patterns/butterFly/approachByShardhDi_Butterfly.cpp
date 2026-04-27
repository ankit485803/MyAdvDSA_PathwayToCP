

/*

27th April 2026 (Monday) shardhDi boli pattern yad nahi karna hai only samajhana hai usko

Butterfly pattern

R1: 1st + 6sp + 1st
R2: 2st + 4sp + 2st
R3: 3st + 2sp + 3st
R2: 4st + 0sp + 4st

outerLoop: no of rows - 1 to n
innerloop: a) stars
           b) spaces 
           c) stars: 1 to i


jaha even yaye to 2 se multiple ho skta hai told by ShardhaDi



*/


#include <iostream>
using namespace std;

int main() {
    int n = 4;

    //upper
    for(int i=1; i <= n; i++) {
        //innerLoop into threeParts
        for(int j = 1; j <= i; j++) {  //STARS
            cout << "*";
        }

        for(int s = 1; s <= 2*(n - i); s++) {  //SPACES jo evenNumb mai hai so 2 aaya and then decrease -i
            cout << " ";
        }

        for(int j = 1; j <= i; j++) {  //STARS
            cout << "*";
        }

        cout << endl;  //oneLine completed Rows
    }


    //lower mai sirf outerloop ko reverse
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {  
            cout << "*";
        }

        for(int s = 1; s <= 2*(n - i); s++) {  
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {  
            cout << "*";
        }
        cout << endl;  
    }

    return 0;
}


//git commit -m "feat(sigmaApnaCollege): completed this chap8 pattern and lastly butterfly topic by ShardhaDi, with classSlides (ch8)"
//git commit -m "feat(sigmaApnaCollege): complete chapter 8 patterns including butterfly (ShardhaDi) with class slides"