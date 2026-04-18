

/*


https://www.hackerrank.com/contests/code-e-khaas-iitp/challenges/poisonous-plants


Poisonous Plants
Problem
Submissions
There are a number of plants in a garden. Each of the plants has been treated with some amount of pesticide. After each day, if any plant has more pesticide than the plant on its left, being weaker than the left one, it dies.

You are given the initial values of the pesticide in each of the plants. Determine the number of days after which no plant dies, i.e. the time after which there is no plant with more pesticide content than the plant to its left.

Example

 // pesticide levels

Use a -indexed array. On day , plants  and  die leaving . On day , plant  in  dies leaving . There is no plant with a higher concentration of pesticide than the one to its left, so plants stop dying after day .

Function Description
Complete the function poisonousPlants in the editor below.

poisonousPlants has the following parameter(s):

int p[n]: the pesticide levels in each plant
Returns
- int: the number of days until plants no longer die from pesticide

Input Format

The first line contains an integer , the size of the array .
The next line contains  space-separated integers .

Constraints

Sample Input

7
6 5 8 4 7 10 9
Sample Output

2
Explanation

Initially all plants are alive.

Plants = {(6,1), (5,2), (8,3), (4,4), (7,5), (10,6), (9,7)}

Plants[k] = (i,j) => jth plant has pesticide amount = i.

After the 1st day, 4 plants remain as plants 3, 5, and 6 die.

Plants = {(6,1), (5,2), (4,4), (9,7)}

After the 2nd day, 3 plants survive as plant 7 dies.

Plants = {(6,1), (5,2), (4,4)}

Plants stop dying after the 2nd day.


*/


int poisonousPlants(vector<int> p) {  //tc=O(n)=sc usingGreedy
    stack<pair<int, int>> st; // {pesticide, days}  
    int maxDays = 0;

    for (int x : p) {
        int days = 0;

        // Remove all stronger/equal left plants
        while (!st.empty() && x <= st.top().first) {
            days = max(days, st.top().second);
            st.pop();
        }

        if (st.empty()) {
            days = 0;
        } else {
            days += 1;
        }

        maxDays = max(maxDays, days);
        st.push({x, days});
    }

    return maxDays;
}