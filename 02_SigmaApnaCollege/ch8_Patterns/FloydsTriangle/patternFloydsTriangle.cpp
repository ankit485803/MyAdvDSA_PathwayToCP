

/*

21st April 2026 (Tuesday) similar to 02_SigmaApnaCollege\ch8_Patterns\pyramid\charPyramid.cpp

print the pattern Floyd's Triangle

 vvvery imp yaha pe int num = 1; ko outside of nestedLoop define kar skate hai because nums is going to increase irrespective of i, j values
 so we defined int num = 1;

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15

git commit -m "feat(sigmaApnaCollege): start solving Floyd's Triangle pattern and updates imp points in invertedRotatedHalfPyramid (ch8)"


int num = (n * (n + 1)) / 2; // best practice instead of hardcoding because Total numbers in Floyd’s Triangle = sum of first n natural numbers
for reverse the Floyd's Triangle


*/


#include <iostream>
using namespace std;

int main() {
    int n = 5;  //given 
    int num = 1; //we defined yahi points Ankit ko click nahi kiye tha

    for(int i=1; i <= n; i++) {  //outerLoop no of rows
        for(int j = 1; j <= i; j++) {  //kya print karna hai aur kab tak innerLoop
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    return 0;
}




/*

now this

14 13 12 11
10 9 8 7
6 5 4
3 2 
1


*/


#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int num = 15;

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << num << " ";
            num--;
        }
        cout << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int num = (n * (n + 1)) / 2; // best practice instead of hardcoding because Total numbers in Floyd’s Triangle = sum of first n natural numbers

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << num << " ";
            num--;
        }
        cout << endl;
    }

    return 0;
}



//git commit -m "feat(sigmaApnaCollege): done Floyd's Triangle pattern and learn TotalNumb in Floyd’s Triangle = sum of first n naturalNo  (ch8)"