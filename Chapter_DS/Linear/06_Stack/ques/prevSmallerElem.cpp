

#include <iostream>
#include <vector>
#include <stack>
using namespace std;




vector<int> prevSmallerElement(vector<int> arr) {

    vector<int> ans(arr.size(), 0);
    stack<int> s;


    for(int i=0; i<arr.size(); i++) {
        while(s.size() > 0  &&  s.top()  >= arr[i]) {
            s.pop();
        }

        //two cases exit only
        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }

        s.push(arr[i]);

    }


    return ans;

}





int main() {

    vector<int> arr = {3, 1, 0, 8, 6};

    vector<int> ans = prevSmallerElement(arr);

    //printing ans
    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}


// TC = O(n) = SC
