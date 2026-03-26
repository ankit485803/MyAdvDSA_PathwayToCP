

/*


26th March 2026 (Thursday)

print star like this

*
* * 
* * *
* * * *



*/



#include <iostream>
using namespace std;

int main() {
    int N = 4;

    string val = " * ";
    for(int i=1; i <= N; i++) {  //outerLoop no of rows
        for(int j=1; j <= i; j++) {  //kya print karna 
            cout << val;
        }

        cout << endl;
    }

    return 0;
}
