


#include <iostream>
#include <stack>
#include <vector>
using namespace std;


/* 

SPAN = matlab max no of consecutive days from today 
prices <= today's price


prevHigh: immediate greate value for any day
span = i - prevHigh


*/

int main() {
    // Stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // Solution
    vector<int> ans(price.size()); // Initialize ans with the same size as price
    stack<int> s;

    for (int i = 0; i < price.size(); i++) {
        // Pop from stack while the current price is greater than the price at the stack's top index
        while (!s.empty() && price[s.top()] <= price[i]) {
            s.pop();
        }




        // If the stack is empty, it means the price is greater than all previous prices
        if (s.empty()) {
            ans[i] = i + 1; // All previous days are smaller, so span is i+1
        } else {
            // Otherwise, the span is the difference between the current day and the last higher price day
            ans[i] = i - s.top(); // i - prevHigh
        }
        s.push(i);
    }



    // Print the ans value (span for each day)
    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;



    
    return 0;
}
