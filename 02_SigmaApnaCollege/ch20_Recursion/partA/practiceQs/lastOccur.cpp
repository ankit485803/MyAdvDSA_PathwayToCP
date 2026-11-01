

/*

WAF to find the last occurrence of targ elem in arr


esmai hm apna idea ko reverse kar denge
*/



#include <iostream>
#include <vector>
using namespace std;

int firstOccur(vector<int> arr, int i, int targ) {
    //basecase work1
    if(i == arr.size()) {
        return -1;
    }

    if(arr[i] == targ) {  //work2: kaam Ankit 
        return i;
    }

    return firstOccur(arr, i+1, targ);  //next index pe jake check karenge esliye i+1  work3: jo innerFun karega
}



int lastOccur(vector<int> arr, int targ, int i) {
    if(i == arr.size()) {
        return -1;
    }
    
    int idxFound = lastOccur(arr, targ, i+1);  

    //agar idx ho karenge
    if(idxFound == -1 && arr[i] == targ) {
        return i;
    }

    return idxFound;
}


int main() {
    vector<int> arr = {1, 2, 3, 3, 4};
    int targ = 3;

    cout << lastOccur(arr, targ, 3) << endl;

    return 0;
}