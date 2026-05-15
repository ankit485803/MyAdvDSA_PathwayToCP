

/*

15th May 2026 (Friday)

convert binary to decimal form 
given nums = 10010

1*2 pow4  + 0*2 pow3  + 0*2 pow2  + 1*2 pow1 + 0*2 pow0

this maths approach we want to implements here to print the decimalForm

*/


#include <iostream>
using namespace std;
#include <cmath>  //req for pow


//helperFun to calculate size of total digits
int sizeNum(int num) {
    int s = 0; 
    while(num > 0) {
        int lastD = num % 10;
        s++;
        num /= 10;  //removeLast
    }
    return s;
}


int convertBinaryToDecimal(int nums) {
    while(nums > 0) {
        int last = nums % 10;
        int n = sizeNum(nums);

        for(int i=0; i<n; i++) {
            int base = 2, exponent = i;
            
            int ans = last * (pow(base, exponent));  //mainLogic
            return ans;
        }
    }
}




int main() {
    int nums = 10010;

    cout << "decimal form = " << convertBinaryToDecimal(nums) << endl;

    return 0;
}



/*
Your logic idea is correct, but the implementation has a few problems:
    return ans; is inside the loop, so the function exits immediately.
    You are not adding all terms together.
    nums is never reduced inside convertBinaryToDecimal().
    sizeNum(nums) is not needed.
    The exponent should increase from right to left.

ok


*/


#include <iostream>
#include <cmath>
using namespace std;

int convertBinaryToDecimal(int nums) {
    int exponent = 0;
    int decimalForm = 0;

    while(nums > 0) {
        int lastD = nums % 10;

        decimalForm += lastD * pow(2, exponent);  //move rightToLeft

        exponent++;
        nums /= 10;   // removeLastD  The loop removes one digit in every iteration so tc=O(logN)
    }

    return decimalForm;
}

int main() {
    int nums = 10010;

    cout << "decimal form = " << convertBinaryToDecimal(nums) << endl;

    return 0;
}