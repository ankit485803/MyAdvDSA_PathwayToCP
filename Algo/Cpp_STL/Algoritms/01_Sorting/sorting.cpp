

#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>



/* normally sorting in ascending order

syntax:  sort(start, end);

sort(arr,  arr+n);


sort(arr, arr+n, greater<int> () );   //to pass comparator if aapko  reverse order (descending) mai sort

sort(v.begin(),  v.end() );




*/


int main() {

    int arr[5] = {3, 5, 1, 8, 2};
    vector<int> vec = {3, 5, 1, 8, 2};

    //if vec of pair
    vector<pair <int, int>> vec3 = {{3, 1}, {2, 1}, {7, 1}, {5, 2}};



    sort(arr, arr + 5);
    //sort(vec.begin(), vec.end());

    sort(vec.begin(), vec.end(), greater<int>() );  //in descending order

    sort(vec3.begin(), vec3.end() );



    for(int val : vec) {
        cout << val << " ";
    }
    cout << endl;


    //printing  vec3 - which is pair of vec
    for(auto p : vec3) {
        cout << p.first << " " << p.second << endl;
    }




    return 0;
}