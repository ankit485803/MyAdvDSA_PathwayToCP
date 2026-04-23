

/*

23rd April 2026 (Thursday)


print the diamond 

   *
  ***
 *****
*******
*******
 *****
  ***
   *     



so Ankit convert this prob into 

   1
  123
 12345
1234567
1234567
 12345
  123
   1   


*/


#include <iostream>
using namespace std;


int main() {
    int n = 7;

    //case1: upperHalf
    for(int i=1; i <= n; i = i+2) {
        //spaces
        for(int s = 1; s <= (n-i)/2; s++) {
            cout << " ";
        }
        for(int j=1; j <= i; j++) {  //digits
            cout << j;
        }
        cout << endl; 
    }


    //case2: for lowerInvertedShape
    for(int i = n; i >= 1; i = i - 2) {
        for(int s = (n-i)/2;  s >= 1; s--) {  //SPACES
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }



    return 0;
}





// for star print sirf j ke place par star symbol de do
#include <iostream>
using namespace std;


int main() {
    int n = 7;

    //case1: upperHalf
    for(int i=1; i <= n; i = i+2) {
        //spaces
        for(int s = 1; s <= (n-i)/2; s++) {
            cout << " ";
        }
        for(int j=1; j <= i; j++) {  //digits
            cout << "*";
        }
        cout << endl; 
    }


    //case2: for lowerInvertedShape
    for(int i = n; i >= 1; i = i - 2) {
        for(int s = (n-i)/2;  s >= 1; s--) {  //SPACES
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }



    return 0;
}



#include <iostream>
using namespace std;

int main() {
    int n = 7;

    // upper half
    for(int i = 1; i <= n; i += 2) {
        for(int s = 1; s <= (n - i) / 2; s++) {
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // lower half (start from n-2 to avoid repeating middle line)
    for(int i = n - 2; i >= 1; i -= 2) {
        for(int s = 1; s <= (n - i) / 2; s++) {
            cout << " ";
        }
        for(int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}




//by shardha di

int main() {
    int n = 4;

    //1st pyramid
    for(int i = 1; i <= n; i++) {
        for(int j=1; j <= n-i; j++) {  //SPACES
            cout << " ";
        }
        for(int j=1; j <= 2*i - 1; j++) {  //STARS
            cout << "*"; 
        }
        cout << endl;
    }


    //2nd pyramid
    for(int i=n; i >= 1; i--) {
        //spaces
        for(int j=1; j <= n-i; j++) {
            cout << " ";
        }
        //stars
        for(int j=1; j <= 2*i - 1; j++) {
            cout << "*";
        }
        cout << endl;
    }


    return 0;
}


//git commit -m "feat(sigmaApnaCollege): completely draw the Diamond star pattern (ch8)"