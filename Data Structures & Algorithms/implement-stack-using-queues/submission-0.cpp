class MyStack {
public:
    queue<int>q1,q2,temp;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        temp=q1;
        q1=q2;
        q2=temp;
    }
    
    int pop() {
        int val=q2.front();
        q2.pop();
        return val;
    }
    
    int top() {
        int val=q2.front();
        return val;
    }
    
    bool empty() {
        if(q2.empty())
        return true;
        return false;
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