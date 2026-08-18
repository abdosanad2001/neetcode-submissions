class MyStack {
public:
//complexity: T=O(n);space=O(n)
    MyStack() {
        
    }
    queue<int> q1;//space=O(n)
    queue<int> q2;//space=O(n)
    void push(int x) {//T=O(n);space=O(1)
        q2.push(x);
        while(!q1.empty()){
            int temp=q1.front();
            q2.push(temp);
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int t=q1.front();
        q1.pop();
        return t;
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