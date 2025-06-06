

// concept -- BackTracking
// https://www.geeksforgeeks.org/problems/power-set4302/1?utm_source=inf&utm_medium=inf%252Fcampaign%2B&utm_campaign=codein10_powerset_YT





//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	
	    void helper(string s, string tempAns, int index, vector<string>& ans) {
        if (index == s.size()) {
            if (!tempAns.empty()) ans.push_back(tempAns); // Store only non-empty subsets
            return;
        }

        // TAKE the current character
        helper(s, tempAns + s[index], index + 1, ans);

        // NOT TAKE the current character
        helper(s, tempAns, index + 1, ans);
    }
	    
	    
	    
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    helper(s, "", 0, ans);
		    sort(ans.begin(), ans.end()); // Sort lexicographically
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends