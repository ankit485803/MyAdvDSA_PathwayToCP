
/*

Question 4 : Write a program to calculate the area of a circle.
Input : r (radius)
Output : PI*r*r (area)

*/

#include <iostream>
using namespace std;

int main() {
    double R;  //radius
    const double PI = 3.1415;

    cout << "Enter radius of circle R: ";
    cin >> R;

    double area = PI * R * R;
    cout << "Area of circle = " << area << endl;

    return 0;
}