#include <climits>
class MinStack {
public:
    MinStack() {
        
    }
    
    stack<int> st;
    stack<int> min_st;
    int min_val=INT_MAX;
   
    void push(int val) {//T=O(1);space=O(1)
        st.push(val);
        if(min_st.empty()){
            min_st.push(val);
        }else{
            min_st.push(min(val,min_st.top()));
        }
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
