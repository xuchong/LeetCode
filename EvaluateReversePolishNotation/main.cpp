#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<sstream>
class Solution {
private:
  bool isNumer(string s)
  {
     if((s.length()==1&&s[0]>='0'&&s[0]<='9')||s.length()>1)
     {
       return true;
     }
     return false;
  }
  int strTonumber(string s)
  {
    stringstream ss(s);
    int a;
    ss>>a;
    return a;
  }
public:
    int evalRPN(vector<string>& tokens) {
      if(tokens.empty())
        return 0;
      vector<int> que;
      int result=0,a,b;
      for(int i=0;i<tokens.size();i++)
      {
        if(isNumer(tokens[i]))
        {
          que.push_back(strTonumber(tokens[i]));
        }else
        {
          a=que.back();
          que.pop_back();
          b=que.back();
          que.pop_back();
          switch (tokens[i][0]) {
            case '+':
              result=a+b;
              break;
            case '-':
              result=b-a;
              break;
            case '*':
              result=b*a;
              break;
            case '/':
              result=b/a;
              break;
          }
          que.push_back(result);
        }
      }
      return que[0];
    }
};
