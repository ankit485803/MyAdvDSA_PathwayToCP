


/*

2nd May 2026 (Saturday)

Question 3 : Print the Palindromic Pattern with Numbers.
For n = 5

    1
   212
  32123
 4321234
5432112345



myThoughProcess:
outerLoop - no of rows (int i=1; i <= n; i++)
innerLoop - kya print karna hai aur kab tak workDone - yaha pe three kam ho raha hai so three innerLoop need
            partA spaces: decrease ho raha hai w.r.t value of i (int s=1;  s <= n-i; s++)
            partB middleNumb: jo left triangle form kar raha hai with decrease number mai print ho raha so start loop in revOrder mai(int j=i; j >= 1; j--) cout << j;
            partB lastTraingleNum: incNumb jo (int j=2; j <= i; j++) cout << j;


cout << endl;  //newline
cout << '\n';  //littleFast           

*/



#include <iostream>
using namespace std;

int main() {
    int n = 5;

    for(int i=1; i<=n; i++) {
        //threeKam innerLoops req

        for(int s=1; s <= n-i; s++) {  //SPACES partA
            cout << " ";
        }
        
        for(int j = i; j >= 1; j--) {  //numb partB
            cout << j;
        }

        for(int j = 2; j <= i; j++) {
            cout << j;
        }

        cout << '\n';  //newLine
    }

    return 0;
}



/* output

sanja@IITP:/mnt/c/Users/sanja/Desktop/LabSession$ g++ sigmaApnaCollege.cpp -o myRunFile.exe && ./myRunFile.exe
    1
   212
  32123
 4321234
543212345



*/

//Slight optimization (optional) Reduce cout calls:
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n = 5;

    for(int i = 1; i <= n; i++) {
        cout << string(n - i, ' ');

        for(int j = i; j >= 1; j--) cout << j;
        for(int j = 2; j <= i; j++) cout << j;

        cout << '\n';
    }
}


//git commit -m "feat(sigmaApnaCollege): done all the ques of assig of this and restructure directory for newChap(ch8)"