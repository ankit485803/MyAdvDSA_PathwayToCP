

/*

2nd Oct 2026 (Monday)

Tiling Prob: count total ways to to tile a floor (2*n) with tiles (2*1)

approach1: using recursion

approach2: optimized using DP -- will read in upcoming chap


recursionRelationFun: f(n) =  f(n-1) + f(n-2);  //vertical + Horizontal


*/

#include <iostream>
#include <string>
using namespace std;


int tilingProb(int n) {  //2*n
    //baseCase
    if(n == 0 || n == 1) {
        return 1;
    }

    //vertical
    int ans1 = tilingProb(n-1);  //2*n-1

    //horizontal
    int ans2 = tilingProb(n-2);  //2*n-2

    return ans1 + ans2;
}


int main() {
    int n = 3;

    cout << "no of ways to fill tiles in floorBoard = " << tilingProb(n) << endl;

    return 0;
}


//makeFunc shorter
int tilingProblem(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }

    return tilingProblem(n-1) + tilingProblem(n-2);
}