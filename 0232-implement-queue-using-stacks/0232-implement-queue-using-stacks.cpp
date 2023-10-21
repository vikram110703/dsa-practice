class MyQueue {
    stack<int>input,output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
       while(input.size()>0){
           output.push(input.top());
           input.pop();
       }
        input.push(x);
        while(output.size()>0){
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        int x=input.top();
        input.pop();
        return x;
    }
    
    int peek() {
        return input.top();
    }
    
    bool empty() {
        return true?input.empty():false;
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