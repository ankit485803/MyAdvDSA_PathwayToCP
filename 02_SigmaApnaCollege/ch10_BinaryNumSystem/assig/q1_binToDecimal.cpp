

/*

20th May 2026 (Wednesday)

*Try to use the proper as well as the shortcut method of powers of 2, as taught in the
lecture.


Question 1 : Convert the following binary numbers into decimal forms :
        ● 111111
        ● 10110
        ● 10011
        ● 110010



*/


#include <iostream>
using namespace std;


int binToDecimal(int num) {
    int n = num;  //makeCopy
    int decForm = 0;
    int pow = 1;  //2^0, 2^1, 2^2, 2^3, ....

    while(n > 0) {
        int lastD = n % 10;
        decForm += lastD * pow;  //mainLogic
        pow = pow * 2;  //updation
        n = n / 10;  //removeLast
    }

    return decForm;
}

int main() {
    int num1 = 111111;
    int num2 = 10110;  //eg2
    int num3 = 10011;
    int num4 = 110010;

    cout << "Decimal Form of " << num1 << " = " << binToDecimal(num1) << endl; 
    cout << "Decimal Form of " << num2 << " = " << binToDecimal(num2) << endl; 
    cout << "Decimal Form of " << num3 << " = " << binToDecimal(num3) << endl; 
    cout << "Decimal Form of " << num4 << " = " << binToDecimal(num4) << endl; 


    return 0;
}



#include <iostream>
using namespace std;

int binToDecimal(int num) {
    int n = num;
    int decForm = 0;
    int pow = 1;

    while(n > 0) {
        int lastD = n % 10;
        decForm += lastD * pow;

        pow = pow * 2;
        n = n / 10;
    }

    return decForm;
}

int main() {

    cout << "111111 -> " << binToDecimal(111111) << endl;
    cout << "10110 -> " << binToDecimal(10110) << endl;
    cout << "10011 -> " << binToDecimal(10011) << endl;
    cout << "110010 -> " << binToDecimal(110010) << endl;

    return 0;
}


/*
4️⃣ Notes / Things to be careful about
Binary numbers stored as integers:
This works for small numbers, but if a binary number is very long (e.g., more than 31 bits), integers may overflow.
In that case, storing the binary number as a string is safer.
Shortcut method:
Shortcut means: instead of calculating 2^0, 2^1… every time, you just sum the powers of 2 where the digit is 1.
Your code already does it automatically because pow doubles each iteration.

*/


int binToDecimalStr(string s) {
    int dec = 0;
    int pow = 1;
    for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] == '1') dec += pow;
        pow *= 2;
    }
    return dec;
}