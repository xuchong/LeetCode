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
    unordered_set<string> dict(wordDict.begin(),wordDict.end());
    vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
    if(dict.find(s.substr(0,1))!=dict.end())
      dp[0][0]=true;
    for(int i=1;i<s.length();i++)
    {
      if(dict.find(s.substr(0,i+1))!=dict.end())
      {
        dp[0][i]=true;
        continue;
      }
      //get dp[0][i]
      for(int j=0;j<i;j++)
      {
        if(dp[0][j]&&dict.find(s.substr(j+1,i-j))!=dict.end())
        {
            dp[0][i]=true;
        }
      }
    }
    return dp[0][s.length()-1];
  }
};
#endif
int main()
{
  return 0;
}
