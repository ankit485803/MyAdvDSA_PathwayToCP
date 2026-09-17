
git commit -m "feat(sigmaApnaCollege): start newChapter and restructure files (ch15_introTo2dArr)" 

/*

16th Sep 2026 (Wednesday)


*/

#include <iostream>
using namespace std;

int main() {
    int students[3][3] = { {100, 100, 100},   //yah second wala 3 as parameter dena mandatory hai 
                            {85, 74, 89},
                            {63, 72, 65}};

    cout << students[1][1] << endl;  //ans at index (1, 1)
    return 0;
}
