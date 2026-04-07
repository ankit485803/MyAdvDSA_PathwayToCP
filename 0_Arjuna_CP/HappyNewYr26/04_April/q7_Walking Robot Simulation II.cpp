

/*


7th April 2026 (Tuesday)

qno 2069  https://leetcode.com/problems/walking-robot-simulation-ii/?envType=daily-question&envId=2026-04-07

2069. Walking Robot Simulation II
Medium
Topics

Companies
Hint
A width x height grid is on an XY-plane with the bottom-left cell at (0, 0) and the top-right cell at (width - 1, height - 1). The grid is aligned with the four cardinal directions ("North", "East", "South", and "West"). A robot is initially at cell (0, 0) facing direction "East".

The robot can be instructed to move for a specific number of steps. For each step, it does the following.

Attempts to move forward one cell in the direction it is facing.
If the cell the robot is moving to is out of bounds, the robot instead turns 90 degrees counterclockwise and retries the step.
After the robot finishes moving the number of steps required, it stops and awaits the next instruction.

Implement the Robot class:

Robot(int width, int height) Initializes the width x height grid with the robot at (0, 0) facing "East".
void step(int num) Instructs the robot to move forward num steps.
int[] getPos() Returns the current cell the robot is at, as an array of length 2, [x, y].
String getDir() Returns the current direction of the robot, "North", "East", "South", or "West".
 

Example 1:


Input
["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"]
[[6, 3], [2], [2], [], [], [2], [1], [4], [], []]
Output
[null, null, null, [4, 0], "East", null, null, null, [1, 2], "West"]

Explanation
Robot robot = new Robot(6, 3); // Initialize the grid and the robot at (0, 0) facing East.
robot.step(2);  // It moves two steps East to (2, 0), and faces East.
robot.step(2);  // It moves two steps East to (4, 0), and faces East.
robot.getPos(); // return [4, 0]
robot.getDir(); // return "East"
robot.step(2);  // It moves one step East to (5, 0), and faces East.
                // Moving the next step East would be out of bounds, so it turns and faces North.
                // Then, it moves one step North to (5, 1), and faces North.
robot.step(1);  // It moves one step North to (5, 2), and faces North (not West).
robot.step(4);  // Moving the next step North would be out of bounds, so it turns and faces West.
                // Then, it moves four steps West to (1, 2), and faces West.
robot.getPos(); // return [1, 2]
robot.getDir(); // return "West"

 

Constraints:

2 <= width, height <= 100
1 <= num <= 105
At most 104 calls in total will be made to step, getPos, and getDir.
 

Seen this question in a real interview before?
1/5
Yes
No
Accepted
30,277/92.8K
Acceptance Rate
32.6%
Topics
Senior
Design
Simulation
Biweekly Contest 65


*/


// Approach (Simulation)
//T.C. : O(width+height) for Constructor, O(1) for other methods
//S.C. : O(width+height)
class Robot {
public:
    int idx = 0;
    bool moved = false;
    vector<vector<int>> pos; //store all perimter/boundary cell positions
    //O(width + height)
    //S.C : (width + height)
    Robot(int width, int height) {
        //Bottom Row (left to right) -> East(0);
        for (int x = 0; x < width; x++) {
            pos.push_back({x, 0, 0});
        }

        //Right Col (bottom to top) -> North(1);
        for (int y = 1; y < height; y++) {
            pos.push_back({width - 1, y, 1});
        }

        // Top row (right to left) -> West(2)
        for (int x = width - 2; x >= 0; x--) {
            pos.push_back({x, height - 1, 2});
        }

        // Left column (top to bottom) -> South(3)
        for (int y = height - 2; y > 0; y--) {
            pos.push_back({0, y, 3});
        }

        //pos = {{0, 0, 0}, ....}
        pos[0][2] = 3; //Make it South for handkling corner case when it comes to (0,0) after moving

    }
    
    void step(int num) {
        moved = true;
        idx = (idx + num) % pos.size();
    }
    
    vector<int> getPos() {
        return {pos[idx][0], pos[idx][1]};
    }
    
    string getDir() {
        if(!moved)
            return "East";
        
        int d = pos[idx][2];
        if(d == 0) return "East";
        else if(d == 1) return "North";
        else if(d == 2) return "West";
        return "South";
    }
};



class Robot {
public:
    Robot(int width, int height) {
        
    }
    
    void step(int num) {
        
    }
    
    vector<int> getPos() {
        
    }
    
    string getDir() {
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */