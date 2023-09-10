class MyQueue {
public:
    stack <int> temp1;
    stack <int> temp2;

    MyQueue() {
                
    }
    
    void push(int x) {
        temp1.push(x);
    }
    
    int pop() {
        int temp = peek();
        temp2.pop();
        return temp;
    }
    
    int peek() {
        if(temp2.empty()){
            while(!temp1.empty()){
                temp2.push(temp1.top());
                temp1.pop();
            }
        }
        return temp2.top();
        
    }
    
    bool empty() {
        if (!temp2.empty() || !temp1.empty()) return false;
        return true;
        
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