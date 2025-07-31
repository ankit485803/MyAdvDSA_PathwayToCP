


// qno 225  https://leetcode.com/problems/implement-stack-using-queues/


class MyStack {
    public:
        queue<int> q1;
        queue<int> q2;
    
        MyStack() {
            
        }
        
        void push(int x) {  //O(n)
            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            
            q1.push(x);
    
            while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
    
            }
        }
        
        int pop() {
            int ans = q1.front();
            q1.pop();
            return ans;
    
        }
        
        int top() {
            return q1.front();
        }
        
        bool empty() {
            return q1.empty();
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */



     // qno 235  https://leetcode.com/problems/implement-queue-using-stacks/


     class MyQueue {
        public:
            stack<int> s1;
            stack<int> s2;
        
            MyQueue() {
                
            }
            
            void push(int x) {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
        
                }
        
                s1.push(x);
        
                while(!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            
            int pop() {
                int ans = s1.top();
                s1.pop();
                return ans;
        
            }
            
            int peek() {
                return s1.top();
            }
            
            bool empty() {
                return s1.empty();
            }
        };
        
        /**
         * Your MyQueue object will be instantiated and called as such:
         * MyQueue* obj = new MyQueue();
         * obj->push(x);
         * int param_2 = obj->pop();
         * int param_3 = obj->peek();
         * bool param_4 = obj->empty();
         */
