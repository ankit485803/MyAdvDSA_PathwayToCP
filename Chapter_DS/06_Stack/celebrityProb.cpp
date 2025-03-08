

#include <iostream>
using namespace std;
#include <stack>
#include <vector>



/* The Celebrity Prob

Given 2d arr n*n such that arr[i][j] = 1 means i th person knows j th person, the task is to find the celebrity 

Celebristy is a person who known to all but doesnot know anyone
return the index of celebrity if there is no celebrity return -1

arr = [[0,1,0], [0,0,0], [0,1,0]]



*/


int getCelebrity(vector<vector<int>> arr) {
    int n = arr.size();
    stack<int> s;
    
    // // Push all people into the stack
    for(int i=0; i<n; i++) {   //O(n)
        s.push(1);

    }

     // Eliminate non-celebrities
    while(s.size() > 1) { //O(n)
        int i = s.top();
        s.pop();

        int j = s.top();
        s.pop();

        //eliminating
        if(arr[i][j] == 0) {
            s.push(i);

        } else {
            s.push(j);
        }
    }

    int celeb = s.top();

    for(int i=0; i<n; i++) {
        if((i != celeb) && (arr[i][celeb] == 0)  || arr[celeb][i] == 1) {
            return -1;
        }
    }
    
    return celeb;
}



int main() {

    vector<vector<int>> arr = { {0,1,0},
                                {0, 0, 0},
                                {0, 1, 0}};
    
    int ans = getCelebrity(arr);

    cout << "Celebrity is : " << ans << endl;

    return 0;
}


// TC = O(n), SC = O(n) because we use stack dataStruc

