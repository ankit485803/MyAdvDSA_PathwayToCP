

/* solve agian with dry and run 

 qno 509  https://leetcode.com/problems/fibonacci-number/





*/


// qno 371  https://leetcode.com/problems/sum-of-two-integers/submissions



class Solution {
    public:
        int getSum(int a, int b) {
            while (b != 0) {
                // Calculate sum without carry
                int temp_sum = a ^ b;
                // Calculate carry and shift it left
                int carry = (a & b) << 1;
                // Update a and b for the next iteration
                a = temp_sum;
                b = carry;
            }
            return a;
        }
    };
    
