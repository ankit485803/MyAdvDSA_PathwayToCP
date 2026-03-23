

//Question 2 : WAP to print the multiplication table of a number, entered by the user.


#include <iostream>
using namespace std;

int tableWrite(int n) {
    int ans = n;
    
    int i = 1;
    while(i <= 10) {
        ans = ans * i;
        i++;
    }
    //cout << ans << " " << endl;
    return ans;
}



int main() {
    int n;
    cout << "enter the numb which you want to write table: ";
    cin >> n;

    cout << "Tables of " << n  << tableWrite(n) << endl;

    return 0;
}




/*

🔴 What’s wrong in your code?
ans = ans * i;

This keeps multiplying:

5 * 1 * 2 * 3 * ... * 10

So you're calculating:
👉 5 × 10! = 5 × 3628800 = 18144000 (close to your output depending on flow)

❌ But a multiplication table should be:



🔑 Key Fixes
❌ Removed ans = ans * i
❌ Removed unnecessary return value
✅ Used void function since we only print
✅ Printed each step separately
*/



void writeTable(int n) {
    for(int i = 1; i <= 10; i++) {

        cout << n << " x " << i << " = " << n * i << endl;   //5 * 1 = 5  like thisOutput
    }
}


int main() {
    int n;
    cout << "enter n: ";
    cin >> n;

    cout << "Table of " << n << "as below :" << endl;
    writeTable(n);

    return 0;
}