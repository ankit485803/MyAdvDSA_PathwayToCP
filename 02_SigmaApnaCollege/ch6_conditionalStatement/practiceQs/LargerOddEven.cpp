

/*


9th March 2026 (Monday)


print the larger of 2 numb
print if a odd or even 

| Statement | Purpose            |
| --------- | ------------------ |
| `cout`    | prints to terminal |
| `return`  | exits function     |


Why nothing printed? 🤔
    return in main() ends the program and sends a value to the operating system, not to the terminal.
So the value a or b is not displayed.
You must use cout to print values.



| Keyword  | Meaning                    |
| -------- | -------------------------- |
| `return` | sends value back to caller |
| `cout`   | prints on screen           |

we can explicitly make new function outsied main there return work or NOT
    Yes 👍 — if you create a separate function outside main(), then return works to send a value back to main(), but it still does NOT print anything automatically.

You must print the returned value using cout.




Function
   |
   | return value
   v
Caller (main)
   |
   | cout
   v
Terminal Output


*/

#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 10;

    // Larger number
    if(a > b) {
        cout << "Larger number: " << a << endl;
    } else {
        cout << "Larger number: " << b << endl;
    }

    // Odd or Even
    if(a % 2 == 0) {
        cout << "a is Even" << endl;
    } else {
        cout << "a is Odd" << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

int larger(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int x = 5, y = 10;

    int result = larger(x, y);   // function call

    cout << "Larger number: " << result << endl;

    return 0;
}