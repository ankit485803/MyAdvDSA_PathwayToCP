


/*

15th June 2026 (Monday)


1.1 Counting Sort is a non-comparison-based sorting algorithm that operates by counting the occurrences of each unique element 
in an array. It calculates the exact position of each element in the output array using prefix sums, making it highly efficient for sorting integers with a limited range.


1.2  Dangling Pointers
A dangling pointer in C++ is a pointer that points to a memory location that has already been deallocated or freed. 
Dereferencing or accessing a dangling pointer triggers undefined behavior, which can lead to stealthy data corruption, unpredictable program outputs, or immediate segmentation faults and crashes.



*/



// 1.1 src 0_Arjuna_CP\HappyNewYr26\06_June\q21_maxIceCreamBars.cpp
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {  //tc=O(n + maxCost), sc=O(maxCost)
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxCost + 1, 0);

        // Counting sort frequency array
        for (int cost : costs) {
            freq[cost]++;
        }

        int count = 0;

        // Buy cheapest bars first
        for (int cost = 1; cost <= maxCost && coins >= cost; cost++) {
            if (freq[cost] == 0) continue;

            int canBuy = min(freq[cost], coins / cost);

            count += canBuy;
            coins -= canBuy * cost;
        }

        return count;
    }
};


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) { //tc=O(n logN), sc=O(1)
        //step1: sort arr costs using countingSort as per req
        sort(costs.begin(), costs.end());

        int count = 0;   //no of ice creams bars

        //step2: iterate each idx to count
        for(int i=0; i < costs.size(); i++) {
            if(costs[i] <= coins) {
                count++;
                coins = coins - costs[i];   //subtract 
            } else {
                break;
            }
        }

        return count;
    }
};
