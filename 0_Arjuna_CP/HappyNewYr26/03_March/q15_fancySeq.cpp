


/*

15th March 2026 (Sunday)


qno 1622  https://leetcode.com/problems/fancy-sequence/description/?envType=daily-question&envId=2026-03-15


conceptUsed: Fermant Little Theorem, Power ko find out ke liye BinaryExponentation karte hai, and modulo property

a/b % N jisko hm a*b^-1 %M = a*b power M-2 % M

C:\Users\sanja\Desktop\GitProj\MyAdvDSA_PathwayToCP\0_Arjuna_CP\HappyNewYr26\03_March\Fermant Little Theorem and Property of Modulo_DocScanner 15 Mar 2026 09-12.jpg.jpeg


1622. Fancy Sequence
Hard
Topics

Companies
Hint
Write an API that generates fancy sequences using the append, addAll, and multAll operations.

Implement the Fancy class:

Fancy() Initializes the object with an empty sequence.
void append(val) Appends an integer val to the end of the sequence.
void addAll(inc) Increments all existing values in the sequence by an integer inc.
void multAll(m) Multiplies all existing values in the sequence by an integer m.
int getIndex(idx) Gets the current value at index idx (0-indexed) of the sequence modulo 109 + 7. If the index is greater or equal than the length of the sequence, return -1.
 

Example 1:

Input
["Fancy", "append", "addAll", "append", "multAll", "getIndex", "addAll", "append", "multAll", "getIndex", "getIndex", "getIndex"]
[[], [2], [3], [7], [2], [0], [3], [10], [2], [0], [1], [2]]
Output
[null, null, null, null, null, 10, null, null, null, 26, 34, 20]

Explanation
Fancy fancy = new Fancy();
fancy.append(2);   // fancy sequence: [2]
fancy.addAll(3);   // fancy sequence: [2+3] -> [5]
fancy.append(7);   // fancy sequence: [5, 7]
fancy.multAll(2);  // fancy sequence: [5*2, 7*2] -> [10, 14]
fancy.getIndex(0); // return 10
fancy.addAll(3);   // fancy sequence: [10+3, 14+3] -> [13, 17]
fancy.append(10);  // fancy sequence: [13, 17, 10]
fancy.multAll(2);  // fancy sequence: [13*2, 17*2, 10*2] -> [26, 34, 20]
fancy.getIndex(0); // return 26
fancy.getIndex(1); // return 34
fancy.getIndex(2); // return 20
 

Constraints:

1 <= val, inc, m <= 100
0 <= idx <= 105
At most 105 calls total will be made to append, addAll, multAll, and getIndex.
 
Discover more
Application programming interface
Seen this question in a real interview before?
1/5
Yes
No
Accepted
21,158/92.5K
Acceptance Rate
22.9%
Topics
Principal
Math
Design
Segment Tree
Biweekly Contest 37


*/


class Fancy {
public:
    Fancy() {
        
    }
    
    void append(int val) {
        
    }
    
    void addAll(int inc) {
        
    }
    
    void multAll(int m) {
        
    }
    
    int getIndex(int idx) {
        
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */





 

//Approach - Simple maths + Binary Exponentiation and Fermat's Little Theorem
//T.C : O(log(M)) for Binary Exponentiation power(mult, M-2)
//S.C : O(1)
class Fancy {
public:
    typedef long long ll;

    ll M = 1e9+7;

    vector<ll> seq;
    ll add = 0;
    ll mult = 1;

    //Binary Exponentiation for Fermat's Little Theorem -> power(mult, M-2);
    long long power(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half   = power(a, b/2);
        long long result = (half * half) % M;

        if(b%2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    Fancy() {
        
    }
    
    void append(int val) {
        long long x = ((val - add) % M + M) * power(mult, M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % M;
    }
    
    void multAll(int m) {
        mult = (mult * m) % M;
        add  = (add * m) % M;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())
            return -1;

        return (seq[idx]*mult + add) % M;
    }
};