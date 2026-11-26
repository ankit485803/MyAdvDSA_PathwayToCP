

/*

26th Nov 2026 (Thursday - after Chhath Puja)

qno 3360  https://leetcode.com/problems/stone-removal-game/description/?envType=daily-question&envId=2026-11-26

*/

class Solution {
public:
    bool canAliceWin(int n) {  //tc=O(1)=sc using SIMULATION apporach
        int take = 10;
        int steps = 0;

        while(n >= take) {
            n -= take;
            take--;
            steps++;
        }

        return steps % 2 == 1;  //if odd idx Alice win
    }
};



class Solution {
public:
    bool canAliceWin(int n) {  //tc=O(1)=sc using maths quadratic formula
        int k = (21 - sqrt(441 - 8*n)) / 2;

        return k % 2 == 1;  //Alice win
    }
};