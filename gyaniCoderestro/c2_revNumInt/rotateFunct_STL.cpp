
/*  rotate(first, middle, last);
first → start of the range
middle → new starting point after rotation
last → end of the range

3rd May 2026 (Sunday)

*/


#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    vector<int> v2 = {1, 2, 3, 4, 5};

    // Rotate left by 2 positions (30 becomes the first element)
    rotate(v.begin(), v.begin() + 2, v.end());

    // Result: 30, 40, 50, 10, 20
    for (int n : v) cout << n << " ";
    cout << "\n"

    //rightRotation 2 position
    rotate(v2.rbegin(), v2.rbegin() + 2, v2.rend());
    for(int n2 : v2) cout << n2 << " ";

    return 0;
}
