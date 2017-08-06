#include<iostream>
#include<cstring>
#include<string>
#include<unordered_set>
using namespace std;
#define TL
#ifndef TL
class Solution {
private:
  bool recursive(string&s,unordered_set<string>&dict)
  {
    if(dict.find(s)!=dict.end())
      return true;
    string tmp;
    for(int i=1;i<s.length();i++)
    {
      tmp=s.substr(0,i);
      if(dict.find(tmp)!=dict.end())
      {
        if(recursive(s.substr(i,s.length()-i),dict))
          return true;
      }
    }
    return false;
  }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> dict(wordDict.begin(),wordDict.end());
      return recursive(s,dict);
    }
};
#elif
class Solution{
public:
  bool wordBreak(string s,vector<string>& wordDict)
  {
    
  }
};
#endif
int main()
{
  return 0;
}
