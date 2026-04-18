

/*

ques 2 https://www.hackerrank.com/contests/code-e-khaas-iitp/challenges/largest-rectangle


Largest Rectangle
Problem
Submissions
Skyline Real Estate Developers is planning to demolish a number of old, unoccupied buildings and construct a shopping mall in their place. Your task is to find the largest solid area in which the mall can be constructed.

There are a number of buildings in a certain two-dimensional landscape. Each building has a height, given by . If you join  adjacent buildings, they will form a solid rectangle of area .

Example

A rectangle of height  and length  can be constructed within the boundaries. The area formed is .

Function Description

Complete the function largestRectangle int the editor below. It should return an integer representing the largest rectangle that can be formed within the bounds of consecutive buildings.

largestRectangle has the following parameter(s):

int h[n]: the building heights
Returns
- long: the area of the largest rectangle that can be formed within the bounds of consecutive buildings

Input Format

The first line contains , the number of buildings.
The second line contains  space-separated integers, each the height of a building.

Constraints

Sample Input

STDIN       Function
-----       --------
5           h[] size n = 5
1 2 3 4 5   h = [1, 2, 3, 4, 5]
Sample Output

9


*/

this is also very simple

my approach: step1: find min h{i] 
step2: calcuate k value, then return arr = hmin * k

long largestRectangle(vector<int> h) {

}



long largestRectangle(vector<int> h) {
    stack<int> st;
    long maxArea = 0;
    int n = h.size();

    for (int i = 0; i <= n; i++) {  //tc=O(n)=sc
        int currHeight = (i == n) ? 0 : h[i];

        while (!st.empty() && currHeight < h[st.top()]) {
            int height = h[st.top()];
            st.pop();

            int width;
            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }

            maxArea = max(maxArea, (long)height * width);
        }

        st.push(i);
    }

    return maxArea;
}





