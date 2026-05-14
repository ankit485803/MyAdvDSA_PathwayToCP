

/*

11. Identify the infinite loop.
    for( ; ; )
    for(int i=0; i<1; i--)
    for(int i=0; ; i++)
    all of the above   (ans)


12. Choose the correct default return value of function in C++.
    int   (ans)
    void
    char
    float

13. Which type of loop is guaranteed to have the body execute at least once?
    do-while loop   (ans)
    for (traditional)
    for-each
    while  


14. Evaluate the following C++ expression, if x=3, y=5, and z=10 :

++z + y - y + z + x++

    24
    23
    20
    25  (ans)


15. Which of the following code segments will produce the displayed output (one or more may be correct)?

11111 
2222 
333 
44 
5


option I to V

*/




#include <iostream>
using namespace std;

int main() {
    // Nested loop: prints decreasing counts of each number
    for(int i = 1; i <= 5; i++) {
        for(int j = i; j <= 5; j++) {
            cout << i;
        }
        cout << "\n"; // Move to next line after inner loop
    }

    return 0;
}

/*
Expected Output:

11111
2222
333
44
5
*/



#include <iostream>
using namespace std;

int main() {

    // ===============================
    // I
    cout << "// I Output:\n";
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << "\n";
    }
    /*
    Expected Output:
    1 
    2 2 
    3 3 3 
    4 4 4 4 
    5 5 5 5 5
    */

    // ===============================
    // II
    cout << "\n// II Output:\n";
    for(int i = 1; i <= 5; i++) {
        for(int j = 5; j >= 1; j--) {
            cout << i << " ";
        }
        cout << "\n";
    }
    /*
    Expected Output:
    1 1 1 1 1
    2 2 2 2 2
    3 3 3 3 3
    4 4 4 4 4
    5 5 5 5 5
    */

    // ===============================
    // III (same as II)
    cout << "\n// III Output:\n";
    for(int i = 1; i <= 5; i++) {
        for(int j = 5; j >= 1; j--) {
            cout << i << " ";
        }
        cout << "\n";
    }
    /*
    Expected Output:
    1 1 1 1 1
    2 2 2 2 2
    3 3 3 3 3
    4 4 4 4 4
    5 5 5 5 5
    */

    // ===============================
    // IV
    cout << "\n// IV Output:\n";
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5; j++) {
            cout << i << "\n";
        }
    }
    /*
    Expected Output:
    1
    1
    1
    1
    1
    2
    2
    2
    2
    2
    3
    3
    3
    3
    3
    4
    4
    4
    4
    4
    5
    5
    5
    5
    5
    */

    // ===============================
    // V (Correct one for 11111,2222,...)
    cout << "\n// V Output:\n";
    for(int i = 1; i <= 5; i++) {
        for(int j = i; j <= 5; j++) {
            cout << i;
        }
        cout << "\n";
    }
    /*
    Expected Output:
    11111
    2222
    333
    44
    5
    */

    return 0;
}

git commit -m "feat(sigmaApnaCollege): complete the MCQ test through googleForm and now ready for newChap BNS (ch9)"