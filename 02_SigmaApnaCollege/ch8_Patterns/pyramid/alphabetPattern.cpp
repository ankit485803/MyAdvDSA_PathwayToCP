

/*

Alphabet Pattern



A
AB
ABC
ABCD




*/



#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cout << char('A' + j);
        }
        cout << endl;
    }

    return 0;
}



/*
🔥 Bonus: Reverse Alphabet Pattern

ABCD
ABC
AB
A



*/



#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < i; j++) {
            cout << char('A' + j);
        }
        cout << endl;
    }

    return 0;
}