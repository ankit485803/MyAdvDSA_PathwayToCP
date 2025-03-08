

// https://www.hackerrank.com/contests/algorage-iitp/challenges/swap-nodes-algo



/*

Problem: Swap Nodes in a Binary Tree
You are given a binary tree with n nodes, where each node has a left child, a right child, or both. Each node is numbered from 1 to n. The tree is rooted at node 1.

You need to perform a series of swap operations on the tree. In each operation, you swap the left and right children of nodes at depths that are multiples of a given integer k. After each swap operation, you must return the in-order traversal of the tree.

In-order Traversal
The in-order traversal visits the nodes in the following order:

Traverse the left subtree.
Visit the root node.
Traverse the right subtree.
Depth of a Node
The root node has a depth of 1.
If the depth of the parent node is d, the depth of its child will be d+1.
Swap Operation
For each query k, swap the children of all nodes that are at a depth which is a multiple of k. After each swap, print the in-order traversal of the tree.

Input:
The first line contains an integer n, the number of nodes in the tree.
The next n lines each contain two integers a and b, where a is the left child and b is the right child of node i. If a or b is -1, it means that child doesn't exist.
The next line contains an integer t, the number of swap queries.
The next t lines each contain an integer k, which is the depth multiple for the swap operation.
Output:
For each query k, print the in-order traversal of the tree after performing the swap operation.

Constraints:
1 ≤ n ≤ 100
1 ≤ t ≤ 10
1 ≤ k ≤ n
If a node has a non-null child, the child's index will always be greater than the parent's index.



*/




#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
