


/*

30th Sep 2025 (Tuesday - 8th Puja Navaratri Maa Durga)

qno 1518   https://leetcode.com/problems/water-bottles/

what is simulation approach
The simulation approach in programming is when you mimic a real-world process step-by-step in code, updating variables to represent changes in state over time — just like how the situation would play out in real life.

It's often used in problems where:
        There’s a sequence of operations.
        Each step depends on the results of the previous step.
        The problem describes some kind of process, rule, or game.




Ankit Learn:
The logic inside the loop shouldn't return immediately — it ends the function early.
You're using a loop but immediately return inside it, which defeats the purpose of the loop.
return numBottles + exchangable + 1; is not correct for all cases — it's trying to shortcut the answer based on observation, but it won’t work in all inputs.
🧠 Why?
The purpose of the loop is to simulate exchanges, and exchanges depend on the number of empty bottles, not how many you've drunk overall.
why log time
        You’re dividing the number of empty bottles by numExchange each time.
        You're not reducing it by 1 (which would be linear O(N)).
        Instead, it drops faster, similar to:  N → N/3 → N/9 → N/27 → ... → 1   This is a geometric reduction, which leads to a time complexity of
        O(log N) — because the input shrinks exponentially in each iteration.



⏱️ General Rule: How to Identify O(log N) vs O(N)
| Pattern                                                      | Time Complexity |
| ------------------------------------------------------------ | --------------- |
| You reduce the input by **half / third / K-times** each loop | `O(log N)`      |
| You reduce the input by **1 / constant** each loop           | `O(N)`          |
| Nested loops over same input size                            | `O(N^2)`        |







1518. Water Bottles
Easy
Topics

Companies
Hint
There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.
The operation of drinking a full water bottle turns it into an empty bottle.
Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

 

Example 1:
Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.





Example 2:
Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.
 

Constraints:

1 <= numBottles <= 100
2 <= numExchange <= 100


*/











class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // Initialize
        int totalDrunk = numBottles;
        int emptyBottles = numBottles;

        // Solve using Simulation approach
        // TC = O(log numBottles), SC = O(1)
        while (emptyBottles >= numExchange) {
            int newFull = emptyBottles / numExchange;
            totalDrunk += newFull;
            emptyBottles = (emptyBottles % numExchange) + newFull;
        }

        return totalDrunk;
    }
};



/*

qno 1184    https://leetcode.com/problems/distance-between-bus-stops/description/




Which Method to Choose?
Method 1 is simpler and more efficient for this particular problem. because this is circular path and TC=O(n), SC=O(1)
Method 2 would be useful if the problem were more complex (e.g., non-circular paths, multiple paths, etc.) where graph algorithms are more
 appropriate and TC = O(N) = SC






 problem:
A bus has n stops numbered from 0 to n - 1 that form a circle. We know the distance between all pairs of neighboring stops where distance[i] is the distance between the stops number i and (i + 1) % n.
The bus goes along both directions i.e. clockwise and counterclockwise.
Return the shortest distance between the given start and destination stops.




*/



class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        
        int n = distance.size();

        //EdgeCase:  Ensure start is always less than destination for convenience
        if(start > destination) {
            swap(start, destination);
        }


        //calcaute the clockwise distance
        int clockwiseDist = 0;
        for(int i=start; i<destination; i++) {
            clockwiseDist += distance[i];
        }


        //conterclockwiseD  find
        int counterclockwiseD = 0;
        for(int i=destination; i<start + n; i++) {
            counterclockwiseD += distance[i % n];
        }

        return min(clockwiseDist, counterclockwiseD);
    }
};


//TC=O(n), sc=O(1)