



/*

29th Sep 2025 (Monday - 7th Puja Navratri)

qno 75   https://leetcode.com/problems/sort-colors/description/






*/






#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        // Brute force approach -- apply any sortingAlgo here we use BubbleSort TC=O(n^2)
        for (int i = 0; i < n - 1; ++i) {
            // Add a flag to check if any swaps were made
            bool swapped = false;

            for (int j = 0; j < n - i - 1; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }

            // Optimization: break if the array is already sorted
            if (!swapped) break;
        }
    }
};














class Solution {
public:
    void sortColors(vector<int>& A) {
        int n = A.size();
        
        //solution by DNF (Dutch National Flag) algo
        int mid = 0, high = n-1, low = 0;

        while(mid <= high) {
            if(A[mid] == 0) {   //1st case
                swap(A[low], A[mid]);
                mid++; low++;

            } else if(A[mid] == 1) {  //2nd case
                mid++;
            } else {  //3rd case
                swap(A[high], A[mid]);
                high--;
            }

        }
    }
};

// solution using single loop (while) -- time complx = O(n), space = O(1)  Dutch National Flag algo

/*

Facts to know:
why their name is Dutuch National Flag algo , named on coutry name

| Topic          | Detail                                          |
| -------------- | ----------------------------------------------- |
| Algorithm Name | Dutch National Flag Algorithm                   |
| Named After    | 🇳🇱 The Netherlands (Dutch flag: R-W-B)        |
| Inventor       | Edsger W. Dijkstra (a Dutch computer scientist) |
| Sorting Goal   | Group and order 3 types of elements             |
| Used In        | Leetcode 75: Sort Colors                        |


Is both name Ques in Ankit Mind: Dutch and Netherland is same

| Term        | Meaning                                                 |
| ----------- | ------------------------------------------------------- |
| Netherlands | The **country name**                                    |
| Dutch       | The **language/people/adjective** form                  |
| Holland     | A **region** in the Netherlands (North & South Holland) |



*/