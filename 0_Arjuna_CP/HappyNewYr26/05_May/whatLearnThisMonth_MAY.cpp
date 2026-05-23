

/*

23rd May 2026 (Saturday)


1.1 bubbleSort dryRun


*/



//1.1 src:  0_Arjuna_CP\HappyNewYr26\05_May\q23_checkIfArrSortedRotated.cpp
class Solution {
public:
    //helperFunct
    vector<int> bubbleSort(vector<int>& arr) {
        int n = arr.size();

        for(int i=0; i<n; i++) {  //nestedLoop tc=O(n^2)
            for(int j=0; j < n - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        return arr;   //sortedArr
    }

    bool check(vector<int>& nums) {
        //bruteForce appraoch- check arr sortable or not if yes return true else false
        
    }
};




//1.2 src: 

