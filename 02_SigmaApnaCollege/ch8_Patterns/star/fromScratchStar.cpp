

/*

2nd April 2026 (Thursday - midSemCapstoneProj reportSubmission)
due to midSemReportSubmission of capstoneProj not able to continute for 5 days

print the InvertedStar pattern using generalize formual


shardhaDi ne boli es tarah ke prob mail innerLoop mai formula kuch es tarh hoga: j = n-i, n-i+1, n-i-1 


****
***
**
*


*/

#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for(int i=1; i<=n; i++) {  //outerLoop-no of rows
        for(int j=1; j <= n-i+1; j++) {  //innerLoop- kya print karna hai aur kab tak karna hai
            cout << "*" << " "; 
        }
        cout << endl;  //jab innerLoop end ho baha jane se pahle newline hona chahiye 
    }

    return 0;
}
