

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>



/*


q3. Pyramid shape 

15th May 2026 (Friday)
already done Ankit in details ok by bad ki ISRO-IIRS Dehradun mai nahi practice kar sakte DSA and revised nahi kar sake the 
sorry for that

src: D:\GitProj\MyAdvDSA_PathwayToCP\02_SigmaApnaCollege\ch8_Patterns\pyramid\fullPyramidCentered.cpp


*/



vector<string> pyramid(int n) {
    
    for(int i=0; i<n; i=i+2) {
        cout << "*" <<  "\n";
        cout << endl;
    }

}







int main() {
    int n;
    cout << "Enter the value of n:";
    cin >> n;

    //print Pyramid 
    pyramid(n);

    return 0;
}