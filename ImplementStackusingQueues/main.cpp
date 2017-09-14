class MyStack {
private:
  queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {
      que.clear();
    }

    /** Push element x onto stack. */
    void push(int x) {
      int size=que.size();
      int tmp;
      que.push(x);
      while(size)
      {
        size--;
        tmp=que.front();
        que.pop();
        que.push(tmp);
      }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      int top=que.front();
      que.pop();
      return top;
    }

    /** Get the top element. */
    int top() {
      return que.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
      return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
