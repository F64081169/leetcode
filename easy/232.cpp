class MyQueue {
public:
    std::stack<int> stk_in;
    std::stack<int> stk_out;

    MyQueue() {
        
    }
    
    void push(int x) {
        stk_in.push(x);
    }
    
    int pop() {
        if (stk_out.empty()) {
            while (!stk_in.empty()) {
                int x = stk_in.top();
                stk_in.pop();
                stk_out.push(x);
            }
        }
        int x = stk_out.top();
        stk_out.pop();
        return x;
    }
    
    int peek() {
        if (stk_out.empty()) {
            while (!stk_in.empty()) {
                int x = stk_in.top();
                stk_in.pop();
                stk_out.push(x);
            }
        }
        return stk_out.top(); 
    }
    
    bool empty() {
        return stk_in.empty() && stk_out.empty();
    }
};
