

/*   https://www.hackerrank.com/contests/codequest-iitp/challenges/equality-in-a-array

Given an array of integers, determine the minimum number of elements to delete to leave only elements of equal value.

Example


Delete the  elements  and  leaving . If both twos plus either the  or the  are deleted, it takes  deletions to leave either  or . The minimum number of deletions is .

Function Description

Complete the equalizeArray function in the editor below.

equalizeArray has the following parameter(s):

int arr[n]: an array of integers
Returns

int: the minimum number of deletions required
Input Format

The first line contains an integer , the number of elements in .
The next line contains  space-separated integers .



*/






int equalizeArray(vector<int> arr) {
    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    int max_freq = 0;
    for (auto& entry : freq) {
        if (entry.second > max_freq) {
            max_freq = entry.second;
        }
    }

    return arr.size() - max_freq;
}
