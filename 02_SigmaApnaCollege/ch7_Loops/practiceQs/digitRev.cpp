


/*

20th March 2026 (Friday)

print th digit of given numb in rev order using while loop





*/



#include <iostream>
using namespace std;

int main() {
    int n = 10829;

    cout << "print lastDigits in reverse order: \n";

    while(n > 0) {
        int lastDigit = n % 10;
        
        cout << lastDigit << " ";
        n = n / 10;   //removing lastDigit  n /= 10;
    }
    cout << endl;

    return 0;
}









int reversed = 0;

while(n > 0) {
    int lastDigit = n % 10;
    reversed = reversed * 10 + lastDigit;
    n /= 10;
}
cout << reversed;






#include <iostream>
using namespace std;
#include <vector>


int main() {
    int n = 10829;

    cout << "print Digits in the same order: \n";
    vector<int> digits;

    while(n > 0) {
        int lastDigit = n % 10;
        digits.push_back(lastDigit);
        n /= 10;   
    }
    cout << endl;

    sort(digits.end(), digits.begin());  //sorts in revOrder
    cout << digits << endl;

    return 0;
}


//C++ cannot print a vector directly. That’s exactly what your error is saying.



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n = 10829;

    cout << "print Digits in the same order: \n";
    vector<int> digits;

    while(n > 0) {
        int lastDigit = n % 10;
        digits.push_back(lastDigit);
        n /= 10;   
    }

    // reverse to get original order
    for(int i = digits.size() - 1; i >= 0; i--) {
        cout << digits[i] << " ";
    }

    cout << endl;
    return 0;
}




#include <iostream>
using namespace std;

int main() {
    int n = 10829;

    int reversed = 0;
    int temp = n;

    // Step 1: Reverse the number
    while(temp > 0) {
        int lastDigit = temp % 10;
        reversed = reversed * 10 + lastDigit;
        temp /= 10;
    }

    cout << "Digits in same order:\n";

    // Step 2: Print digits of reversed number
    while(reversed > 0) {
        int digit = reversed % 10;
        cout << digit << " ";
        reversed /= 10;
    }

    cout << endl;
    return 0;
}



// ⚠️ Important Limitation
// This method fails if number ends with 0
// Example:
// n = 1200
// Reversed becomes:
// 21   ❌ (zeros lost)



#include <iostream>
using namespace std;

int main() {
    int n = 10829;

    int divisor = 1;

    // Find divisor
    while(n / divisor >= 10) {
        divisor *= 10;
    }

    cout << "Digits in same order:\n";

    // Extract digits
    while(divisor > 0) {
        int digit = n / divisor;
        cout << digit << " ";
        n %= divisor;
        divisor /= 10;
    }

    cout << endl;
    return 0;
}