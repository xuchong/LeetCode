#include<iostream>
#include<vector>
class MinStack {
private:
  vector<int> stacks;
  vector<int> minNum;
public:
    /** initialize your data structure here. */
    MinStack() {
      stacks.clear();
      minNum.clear();
    }

    void push(int x) {
      stacks.push_back(x);
      if(minNum.empty())
      {
        minNum.push_back(x);
      }else
      {
        minNum.push_back(x<minNum.back()?x:minNum.back());
      }
    }

    void pop() {
      stacks.pop_back();
      minNum.pop_back();
    }

    int top() {
      return stacks.back();
    }

    int getMin() {
      return minNum.back();
    }
};
