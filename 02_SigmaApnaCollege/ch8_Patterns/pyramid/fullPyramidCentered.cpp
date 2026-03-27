


/*

Full Pyramid (Centered)

   1
  123
 12345
1234567


int n = 7


obersevation Ankit bhai: pahle oneSPACE and then print ODD no



❌ 3. Pattern is not symmetric

Right now output looks like:
 1
 123
 12345
 1234567


But a proper pyramid should be
   1
  123
 12345
1234567



🧠 Key Pattern Trick (VERY IMPORTANT)

Whenever you see:
Centered pyramid → think SPACES + PATTERN
formula: spaces = (total_width - current_width) / 2



*/


#include <iostream>
using namespace std;

//method2: first we print 1 at center and then start from second iteration
void fullPyramidCentric(int n) {
    cout << " " << 1 << endl;

    for(int i=3; i <= n; i = i+2) {
        for(int j=1; j <= i; j++) {
            int val = j;
            cout << val;
        }
        cout << endl;
    }
    
}


int main() {
    int n = 7;

    for(int i=1; i <= n; i = i+2) {  //update outerLoop ODD no times

        cout << " ";  //with oneSpace which acts like CENTRIC 

        for(int j=1; j <= i; j++) {
            int val = j;
            cout << val;  
        }
        cout << endl;
    }

    return 0;
}



int main() {
    int n = 7;

    cout << " " << 1 << endl;
    
    for(int i=3; i <= n; i = i+2) {
        for(int j=1; j <= i; j++) {
            int val = j;
            cout << val;
        }
        cout << endl;
    }

    return 0;
}





#include <iostream>
using namespace std;

int main() {
    int n = 7;

    for(int i = 1; i <= n; i += 2) {

        // spaces (important fix)
        for(int s = 1; s <= (n - i)/2; s++) {
            cout << " ";
        }

        // numbers
        for(int j = 1; j <= i; j++) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}





/* from GPT
Logic:
    Print spaces first
    Then print odd numbers patten


*/

#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for(int i = 1; i <= n; i++) {
        // spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // numbers
        for(int j = 1; j <= (2*i - 1); j++) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}