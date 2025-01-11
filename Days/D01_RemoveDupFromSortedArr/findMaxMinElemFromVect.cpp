

// Q. How to find the maximum element from the given vector ?
// Ans: using *max_element() function

// https://www.geeksforgeeks.org/how-to-find-the-maximum-element-of-a-vector-using-stl-in-c/


// C++ program to find the max
// of Array using *max_element() in STL

//mini element  https://www.geeksforgeeks.org/how-to-find-the-minimum-and-maximum-element-of-a-vector-using-stl-in-c/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Get the vector
	vector<int> a = { 1, -45, 54, 71, 76, 12 };

	// Print the vector
	cout << "Vector: ";

	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;

	// Find the max element
	cout << "\nMax Element = " << *max_element(a.begin(), a.end());
    
    //mini element
    cout << "\nMin Element = " << *min_element(a.begin(), a.end());


	return 0;
}




//printing length of Vector:  myVect.size()

// printing leng of arr: 
// size of array; https://www.w3schools.com/cpp/cpp_arrays_size.asp  not of vectors
// int getArrayLength = sizeof(myNumbers) / sizeof(myNumbers[0]);

// int getVectLeng = myVect.size()