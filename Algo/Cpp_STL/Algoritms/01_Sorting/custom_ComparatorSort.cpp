
#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>


/*

build our custom comparators for boolean operators, sort on the basis of second values


1


*/


bool myComparator(pair<int, int>  p1, pair<int, int> p2) {

    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;

    //if equal
    if(p1.first < p2.first) return true;
    else return false;
     
}




int main() {

    vector<pair <int, int>> vec3 = {{3, 1}, {2, 1}, {7, 1}, {5, 2}};



    sort(vec3.begin(), vec3.end(), myComparator);  //pass as 3rd argument


    for(auto p : vec3) {
        cout << p.first << " " << p.second << endl;
    }




    return 0;
}