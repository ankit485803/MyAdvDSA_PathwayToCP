


/*   🔥🔥 𝐂𝐏 𝐒𝐩𝐞𝐜𝐢𝐚𝐥 | 𝐋𝐞𝐚𝐫𝐧 𝐓𝐢𝐦𝐞 𝐂𝐨𝐦𝐩𝐥𝐞𝐱𝐢𝐭𝐲 𝐎𝐧 𝐂𝐨𝐧𝐬𝐭𝐫𝐚𝐢𝐧𝐭𝐬 🔥🔥

No need to memorial these--just have a look 


Constraints              Minimum Acceptable Time Required       Mathematical Terms
  N <= 15                    O(N!)                                 Factorial
  N <= 30                    O(X^N), Where X is a constant         Exponential  
  N <= 10^2                  O(N^3)                                Cubic
  N <= 10^3                  O(N^2) always, O(N^3) not always      Quadratic, Cubic
  N <= 10^4                  O(N^2)                                Quadratic
  N <= 5 * 10^4              O(NLogN), O(N*sqrt(N))                Linear * Logarithmic, Linear * SquareRoot    
  N <= 10^5                  O(NLogN), O(N*sqrt(N))                Linear * Logarithmic, Linear * SquareRoot
  N <= 10^6                  O(NLogN)                              Linear * Logarithmic
  N <= 10^7                  O(N)                                  Linear
  N <= 10^8                  O(N)                                  Linear
  N <= 10^9                  O(sqrt(N))                            Square Root
  N >= 10^9                  O(LogN) or O(1)                       Logarithmic or Constant 

𝗘𝘅𝗮𝗺𝗽𝗹𝗲: Suppose if the minimum acceptable time is O(N^3) then O(N^2), O(N*sqrtN), O(NLogN), O(N), sqrt(N), O(LogN), O(1) will absolutely work out. So kindly refer to the table from top to bottom for better understanding. 📊




src:  https://leetcode.com/discuss/post/6067881/cp-special-learn-time-complexity-on-cons-n3of/


Nested loop - TC = O(N^2)



Space complexity represents the amount of memory required by an algorithm as input size N grows.

Types of Space Usage
Fixed part: Constants and variables
Variable part: Dynamic memory allocation (e.g., recursion, auxiliary arrays)

eg
 Constant Space (e.g., Swapping two variables)
 O(n) → Linear Space (e.g., Storing an array of size n)

Quadratic Space (e.g., 2D matrix storage)

Examples
Iterative Fibonacci: 
O(1)



Recursive Fibonacci (without memoization): 
O(n) (due to recursion stack)



Merge Sort: 
O(n) (due to auxiliary space for merging)


*/