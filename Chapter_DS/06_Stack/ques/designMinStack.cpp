

// qno 155   https://leetcode.com/problems/min-stack/



class MinStack {  // Tc = o(1), SC = O(2*n)
    public:
        stack<pair<int, int>> s;   //val, minVal
        MinStack() {
            
        }
        
        void push(int val) {
            if(s.empty()) {
                s.push({val, val});
            } else {
                int minVal = min(val, s.top().second);
                s.push({val, minVal});
            }
            
        }
        
        void pop() {
            s.pop();
            
        }
        
        int top() {
            return s.top().first;
        }
        
        int getMin() {
            return s.top().second;
        }
};
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */




     //  method2: SC=O(n), TC  = O(2*n)

