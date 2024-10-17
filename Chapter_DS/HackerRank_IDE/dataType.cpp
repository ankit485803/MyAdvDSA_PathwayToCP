

/*
Note: You can also use cin and cout instead of scanf and printf; however, 
if you are taking a million numbers as input and printing a million lines, it is faster to use scanf and printf.



why
In summary, `scanf` and `printf` are faster than `cin` and `cout` for large volumes of data because they have 
less overhead from buffering and synchronization. They handle raw input and output directly, making them more efficient for 
bulk operations. For performance-critical applications, 
especially with millions of numbers, using the C-style functions is recommended.

*/


//e.g:    Using scanf and printf (no change needed):
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
int main() {
    int numbers[1000000];

    // Input
    for (int i = 0; i < 1000000; ++i) {
        scanf("%d", &numbers[i]);
    }

    // Output
    for (int i = 0; i < 1000000; ++i) {
        printf("%d\n", numbers[i]);
    }

    return 0;
}
*/


//eg using cin / cout



int main() {
    int numbers[10];

    // Input
    for (int i = 0; i < 10; ++i) {
        cin >> numbers[i];
    }

    // Output
    for (int i = 0; i < 10; ++i) {
        cout << numbers[i] << "\n";
    }

    return 0;
}





//main coding
#include <iostream>
#include <iomanip> // For std::setprecision
using namespace std;

int main() {
    // Define variables
    int num1;
    long num2;
    char num3;
    float num4;
    double num5;

    // Taking input
    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    // Output printing
    cout << num1 << endl;                     // Print int
    cout << num2 << endl;                     // Print long
    cout << num3 << endl;                     // Print char
    cout << fixed << setprecision(3) << num4 << endl; // Print float with 3 decimal places
    cout << fixed << setprecision(9) << num5 << endl; // Print double with 9 decimal places

    return 0;
}
