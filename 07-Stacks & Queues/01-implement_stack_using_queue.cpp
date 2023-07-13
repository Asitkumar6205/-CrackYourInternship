class MyStack {
public:
    MyStack() {}
    queue<int> q;
    void push(int x) {
        int s = q.size();
        q.push(x);
        while(s--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int ans = top();
        q.pop();
        return ans;
    }
    
    int top() {
        return q.front(); 
    }
    
    bool empty() {
        return q.empty();
    }
};