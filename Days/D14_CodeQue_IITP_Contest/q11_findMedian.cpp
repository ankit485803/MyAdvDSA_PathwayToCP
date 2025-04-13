

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
int findMedian(vector<int> arr) {
    // Sort the array
    sort(arr.begin(), arr.end());
    
    // Return the middle element
    int n = arr.size();
    return arr[n / 2]; // since n is odd, this is the correct middle element
}