


/*

print the inverted star pattern


* * * *
* * *
* *
*



*/


#include <iostream>
using namespace std;

int main() {
    int N = 4;

    for(int i=N; i >= 1; i--) {
        for(int j=i; j >= 1; j--) {   //revOrder mai loop karo for invetedStarTraingle shape
            cout << "*" << " ";
        }
        cout << endl;
    }



    return 0;
}




for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N - i + 1; j++) {
        cout << "* ";
    }
    cout << endl;
}