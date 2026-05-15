
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



/*

q2. Pattern of starts

ref src: D:\GitProj\MyAdvDSA_PathwayToCP\02_SigmaApnaCollege\ch8_Patterns\diamondPattern\diamondStarPattern.cpp




*/




vector<string> startPattern(int n) {  //tc=O(n*n) due to nestedloop

    for(int i=9; i>1; i=i-2) {  //upperHalf
        if(n == 5) {
            cout << "*" << " ";
            cout << endl;
        }

        //lowerHalf
        for(int j=1; j<9; i=i+2) {
            cout << "*" << " ";
            cout << endl;
        }
    }



};




// int main() {
//     int n = 5;
//     cout << "The starts pattern as" << startPattern(n) << endl;

//     return 0;
// }





/*

print this

*
***
*****
***
*





*/

#include <iostream>
using namespace std;

void starPattern(int n) {
    // Upper Half
    for(int i = 1; i <= n; i += 2) {

        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    // Lower Half
    for(int i = n - 2; i >= 1; i -= 2) {

        for(int j = 1; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }
}

int main() {
    int n = 5;

    cout << "Star Pattern:\n";
    starPattern(n);

    return 0;
}