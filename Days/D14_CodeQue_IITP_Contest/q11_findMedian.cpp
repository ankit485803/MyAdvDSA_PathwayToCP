

/*  https://www.hackerrank.com/contests/codequest-iitp/challenges/find-the-median




Find the Median
Problem
Submissions
The median of a list of numbers is essentially its middle element after sorting. The same number of elements occur after it as before. Given a list of numbers with an odd number of elements, find the median?

Example

The sorted array . The middle element and the median is .

Function Description

Complete the findMedian function in the editor below.

findMedian has the following parameter(s):

int arr[n]: an unsorted array of integers
Returns

int: the median of the array
Input Format

The first line contains the integer , the size of .
The second line contains  space-separated integers 

*/

















// Function to find the median of the array
int findMedian(vector<int> arr) {  //O(n)
    // Sort the array
    sort(arr.begin(), arr.end());
    
    // Return the middle element
    int n = arr.size();
    return arr[n / 2]; // since n is odd, this is the correct middle element
}




/*
✨ Optional Optimization (if n is very large and you only want the median):
If just the median is needed and not full sorting, you can use nth_element() for average O(n) performance:
*/


int findMedian(vector<int> arr) {
    int mid = arr.size() / 2;
    nth_element(arr.begin(), arr.begin() + mid, arr.end());
    return arr[mid];
}



//for both
double findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();

    if (n % 2 != 0) {
        // Odd size: return the middle element
        return arr[n / 2];
    } else {
        // Even size: return average of two middle elements
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
}
