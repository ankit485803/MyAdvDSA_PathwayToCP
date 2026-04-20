

/*

17th April 2026 (Friday)

column wise approach by Shardha Di

02_SigmaApnaCollege\ch8_Patterns\star\holloRec\hollowRect.png


*/

#include <iostream>
using namespace std;


int main() {
    int n = 4;

    for(int i=1; i <= n; i++) {
        cout << "*";  //firstC

        for(int j=1; j <= n-1; j++) {
            if(i == 1 || i == n) {
                cout << "*";  // firstLine and last
            } else {
                cout << " ";  //SPACES
            }
        }

        cout << "*" << endl;  //lastColumn complete stars
    }

    return 0;
}