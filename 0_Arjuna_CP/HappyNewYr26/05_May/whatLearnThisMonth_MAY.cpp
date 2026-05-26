

/*

23rd May 2026 (Saturday)


1.1 bubbleSort dryRun
1.2 #include <cctype>  //for islower, isupper function
1.3 

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
        //bruteForce approach- check arr sortable or not if yes return true else false
        
    }
};




//1.2 src: 

#include <cctype>  //for islower, isupper function
class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        bool lower[26] = {false};
        bool upper[26] = {false};

        for(char c : word) {
            if(islower(c)) {  //using C++ STL funct islower
                lower[c - 'a'] = true;  //markLower
            } else if(isupper(c)) {
                upper[c - 'A'] = true;
            }
        }


        //nowCountSpecialChar
        int count = 0;
        for(int i=0; i<26; ++i) {
            if(lower[i] && upper[i]) {
                count++;
            }
        }

        return count;
    }
};



//1.3 