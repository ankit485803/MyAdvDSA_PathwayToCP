//17th May 2026 (Sunday)


#include <iostream>
using namespace std;

int main() {
    int X = 42; // Any arbitrary integer

    // Property 1: Self-Inverse (X ^ X = 0)
    int selfInverse = X ^ X;
    cout << X << " ^ " << X << " = " << selfInverse << endl;

    // Property 2: Identity (0 ^ X = X)
    int identity = 0 ^ X;
    cout << "0 ^ " << X << " = " << identity << endl;

    // Property 3: Commutative & Associative
    // Order doesn't matter; matching pairs cancel to 0
    int complexExpression = 5 ^ X ^ 5; 
    cout << "5 ^ " << X << " ^ 5 = " << complexExpression << endl;

    return 0;
}
