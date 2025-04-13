



/*   https://www.hackerrank.com/contests/codequest-iitp/challenges/minimum-absolute-difference-in-an-array

The absolute difference is the positive difference between two values  and , is written  or  and they are equal. If  and , . Given an array of integers, find the minimum absolute difference between any two elements in the array.

Example. 

There are  pairs of numbers:  and . The absolute differences for these pairs are ,  and . The minimum absolute difference is .

Function Description

Complete the minimumAbsoluteDifference function in the editor below. It should return an integer that represents the minimum absolute difference between any pair of elements.

minimumAbsoluteDifference has the following parameter(s):

int arr[n]: an array of integers
Returns

int: the minimum absolute difference found
Input Format

The first line contains a single integer , the size of .
The second line contains  space-separated integers, .

Constraints

Sample Input 0


*/


int minimumAbsoluteDifference(vector<int> arr) {
    sort(arr.begin(), arr.end());

    int min_diff = INT_MAX;

    for (int i = 1; i < arr.size(); i++) {
        int diff = abs(arr[i] - arr[i - 1]);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }

    return min_diff;
}
