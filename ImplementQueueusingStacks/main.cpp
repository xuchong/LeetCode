class MyQueue {
private:
  vector<int> stack,stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
      stack.clear();
      stack2.clear();
    }

    /** Push element x to the back of queue. */
    void push(int x) {
      while(!stack2.empty())
      {
        stack.push_back(stack2.back());
        stack2.pop_back();
      }
      stack.push_back(x);
      while(!stack.empty())
      {
        stack2.push_back(stack.back());
        stack.pop_back();
      }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      int n=stack2.back();
      stack2.pop_back();
      return n;
    }

    /** Get the front element. */
    int peek() {
      return stack2.back();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
      return stack2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
