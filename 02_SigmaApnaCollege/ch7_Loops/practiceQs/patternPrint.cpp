

/*

18th March 2026 (Wednesday)

print the pattern 
                    ****
                    ****
                    ****
                    ****



like this using for loop



🧠 Key Observation
Inner loop prints stars in a row
Outer loop repeats rows
Newline (endl) moves to next row



*/


#include <iostream>
using namespace std;


void patternPrint() {
    //nestedLoop used rowCols wise

    for(int i=0; i<4; i++) {  //row
        for(int j=0; j<4; j++) {   //cols wise
            cout << " * ";
        }
        cout << endl; //moveToNext row
    }
}


void numbPrint(int N) {
    for(int i = N; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
}


int main() {
    int N = 10;

    cout << "Print pattern: \n" << endl;
    patternPrint();

    cout << "\n print numb N to 1: \n";
    numbPrint(N);

    return 0;
}