

/*

1.1 
A range-based for loop (for (int x : something)) works with containers/arrays, not with a single integer.
Since n is an integer, you should repeatedly extract its last digit using % 10 and remove it using / 10.
Also, your current loop has another subtle issue: num /= 10 would only modify the local loop variable, not n.
src: 0_Arjuna_CP\HappyNewYr26\08_Aug\q22_checkDivisibility.cpp


1.2




*/





//1.1 
    int calcaluteDigSum(int n) {  //tc=O(no of digits) = O(logN), sc=O(1)  myFirstAttempt

 correct
 // O(log n) time, O(1) space
    int calculateDigSum(int n) {
        int sum = 0;

        while (n > 0) {
            int lastD = n % 10;
            sum += lastD;
            n /= 10;
        }

        return sum;
    }
    
    

//1.2
