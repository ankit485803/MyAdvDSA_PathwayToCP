/*
Flowchart & Pseudocode to calculate the AREA of a rectangle.
Input : length & width (sides)
Output : length*width (area)

*/

#include <iostream>
using namespace std;

int rectArea(int L, int B) {
    if (L < 0 || B < 0) {
        cout << "Negative length and breadth are not possible" << endl;
        return 0;   // stop execution if invalid
    }

    return L * B;   // return actual area
}



int main() {
    int L, B;

    cout << "Enter length L: ";
    cin >> L;
    cout << "Enter width breadth B: ";
    cin >> B;

    int area = rectArea(L, B);

    if (area > 0)
        cout << "Area of rectangle = " << area << endl;

    return 0;
}