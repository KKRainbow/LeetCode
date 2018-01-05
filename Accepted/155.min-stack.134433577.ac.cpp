class MinStack {
public:
    /** initialize your data structure here. */
    // 注意到当什么元素弹出时minValue会变就好做了。可以从原始栈中抽出递减的一个子序列，用单独的栈保存就行了。
    stack<int> origin, decSeq;
    MinStack() {
        decSeq.push(INT_MAX);
    }
    
    void push(int x) {
        origin.push(x);
        if (x <= decSeq.top()) {
            decSeq.push(x);
        }
    }
    
    void pop() {
        int top = origin.top();
        if (top == decSeq.top()) {
            decSeq.pop();
        }
        origin.pop();
    }
    
    int top() {
        return origin.top();
    }
    
    int getMin() {
        return decSeq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */