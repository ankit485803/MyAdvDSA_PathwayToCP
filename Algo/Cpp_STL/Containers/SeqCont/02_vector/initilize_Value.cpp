

#include <iostream>
using namespace std;
#include <vector>


// this initilization concept is useful when we read dyanmic prorg DP --- tabulation DP[][],  memoziation  in advanced DSA

int main() {

    //initlize
    vector<int> myVec = {1, 2, 3, 4, 5};    

    //printing vec
    for(int val : myVec) {
        cout << val << " ";
    }
    cout << endl;



    //same vect repeat 10, 10, 10,  -- size=3 whose each value 10
    // Initialize vec2 with 3 elements, each with a value of 10
    vector<int> vec2(10, 6);

    // Printing vec2
    cout << "Elements in vec2: ";
    for (int val : vec2) {
        cout << val << " "; // Print each element of vec2
    }
    cout << endl;



    //or assign vec3 to vec4
    vector<int> vec3 = {9, 8, 7, 6, 5};

    vector<int> vec4(vec3);  //assign

    cout << "Assign similar value to another vec: " ;
    for(int val : vec4) {
        cout << val << " ";
    }
    cout << endl;



    return 0;
}