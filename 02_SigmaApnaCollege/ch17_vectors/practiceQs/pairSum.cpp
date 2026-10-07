

/*

Pair Sum: find if any pair in sorted vector has target sum

approach1: bruteFore iterate to each and make possible pairs as per req -- tc=O(n^2), sc=O(1)

approach2: optimized using twoPointer approach with linear time = O(n), sc=O(1)

*/


#include <iostream>
#include <vector>
using namespace std;


vector<int> pairSum(vector<int> arr, int targ) {
    int st = 0, end = arr.size()-1;
    int currSum = 0;
    vector<int> ans;

    while(st < end) {
        currSum = arr[st] + arr[end];

        if(currSum == targ) {  //case1
            ans.push_back(st);
            ans.push_back(end);
            return ans;

        } else if(currSum > targ) {  //case2
            end--;
        } else {  //case3
            st++;
        }
    }
    
    return ans;
}


int main() {
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = pairSum(vec, target);
    cout << ans[0] << "," << ans[1] << endl;

    return 0;
}



//approach1
vector<int> pairSum(vector<int> arr, int targ) {
    vector<int> ans;

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {

            if(arr[i] + arr[j] == targ) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = pairSum(vec, target);

    if(!ans.empty()) {
        cout << ans[0] << "," << ans[1] << endl;
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}