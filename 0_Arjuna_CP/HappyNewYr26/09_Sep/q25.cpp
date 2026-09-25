
//25th Sep 2026 (Friday)

Approach : (Recursion - Story To Code - Assigning Responsibility to each method)
// T.C : O(n) for parsing/traversal, but the real cost is building the result sets —
//       O(W * L * log(W)) where W = number of resulting words, L = max word length.
//       W and L can grow exponentially with n in the worst case (e.g. many {x,y} pairs
//       concatenated back to back), bounded here since n <= 60.
// S.C : O(n) for recursion stack depth (bounded by '{' nesting depth)
//       + O(W * L) to store the intermediate/final sets of words.
class Solution {
public:
    string s;
    int n;
    int idx = 0;

    set<string> getUnit() {
        set<string> result;

        if(s[idx] == '{') {
            idx++;
            result = performUnion();
        } else { //alphabet
            result = {string(1, s[idx])};
        }

        idx++;
        return result;
    }

    set<string> performConcat() {
        set<string> result = {""}; //ordered set

        while(idx < n && (s[idx] == '{' || isalpha(s[idx]))) {
            set<string> temp = getUnit();

            set<string> concatResult;
            for(const string& left : result) {
                for(const string& right : temp) {
                    concatResult.insert(left+right);
                }
            }

            result = concatResult;
        }

        return result;
    }

    set<string> performUnion() {
        set<string> result;

        while(true) {
            set<string> temp = performConcat();
            result.insert(begin(temp), end(temp));

            if(idx < n && s[idx] == ',') 
                idx++;
            else 
                break;
        }
        return result;
    }

    vector<string> braceExpansionII(string expression) {
        n = expression.length();
        s = expression;
        idx = 0;

        set<string> st = performUnion();
        vector<string> result(begin(st), end(st));

        return result;
    }
};