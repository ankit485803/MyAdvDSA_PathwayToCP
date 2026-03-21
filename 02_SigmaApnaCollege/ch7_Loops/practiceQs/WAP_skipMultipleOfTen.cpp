

/*


WAP to show numb entered by user execept multiple of 10

💡 Simple Rule
break → loop band kar deta hai
continue → sirf current step skip karta hai


*/


#include <iostream>
using namespace std;

int main() {
    int n;

    while(true) {  //hmaisa ture 1 > 0
        cout << "Enter n: ";
        cin >> n;

        if(n % 10 == 0) {
            continue;  //sirf SKIP kar do multiple of 10
        }
        cout << "You have entered = " << n << endl;
    }
    //else aap yah print kar do
    //cout << "Your program get stopped because you haved entered multiple of 10 " << endl;


    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int n;

    while(true) {
        cout << "Enter n: ";
        cin >> n;

        if(n % 10 == 0) {
            continue;  // skip multiples of 10
        }

        cout << "You have entered = " << n << endl;
    }

    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int n;

    while(true) {
        cout << "Enter n: ";
        cin >> n;

        if(n % 10 == 0) {
            break;  // stop program
        }

        cout << "You have entered = " << n << endl;
    }

    cout << "Program stopped because you entered a multiple of 10." << endl;

    return 0;
}


/*


🔥 Your program IS actually an infinite loop
while(true)

➡️ This condition is always true, so logically the loop never ends on its own.

🤔 Then why does it feel like it's not infinite?

Because:

👉 The program is waiting for user input every time
👉 So it looks like it's “running normally”

But internally:

Loop never stops ❌
No break ❌
No exit condition ❌

➡️ That means it's a controlled infinite loop (interactive loop)





1. 🔴 True Infinite Loop (bad)
while(true) {
    // no input, no break
}

➡️ Runs forever, CPU busy

2. 🟢 Interactive Infinite Loop (your case)
while(true) {
    cin >> n;
}

➡️ Waits for user input → looks normal
➡️ But still technically infinite
*/