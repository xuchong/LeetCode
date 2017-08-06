#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define ML
#ifndef
class Solution {
private:
  vector<vector<string>> result;
  void help(int from,int to,string append)
  {
    for(int i=0;i<result[from].size();i++)
    {
      result[to].push_back(result[from][i]+" "+append);
    }
  }
  void recursive(unordered_set<string>&dict,vector<bool>&dp,string s,int index)
  {
    if(index==s.length())
    {
      return;
    }
    string tmp;
    for(int i=0;i<index;i++)
    {
      tmp=s.substr(i+1,index-i);
      if(dp[i]&&dict.find(tmp)!=dict.end())
      {
        dp[index]=true;
        help(i,index,tmp);
      }
    }
    tmp=s.substr(0,index+1);
    if(dict.find(tmp)!=dict.end())
    {
      dp[index]=true;
      result[index].push_back(tmp);
    }
    recursive(dict,dp,s,index+1);
  }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> output;
        result=vector<vector<string>>(s.length(),vector<string>());
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool>dp(s.length(),false);
        recursive(dict,dp,s,0);
        return result[s.length()-1];
    }
};
#elif
class Solution{
private:
  unordered_map<string,vector<string>> index;
  bool recursive(string&s,unordered_set<string>&dict,vector<string>&result)
  {
    bool output=false;
    if(dict.find(s)!=dict.end())
    {
      output=true;
      result.push_back(s);
    }
    string tmp;
    for(int i=1;i<s.length();i++)
    {
      tmp=s.substr(0,i);
      if(dict.find(tmp)!=dict.end())
      {
        vector<string> item;
        string left=s.substr(i,s.length()-i);
        if(index.count(left)){
          item=index[left];
          if(item.size()>0)
          {
            output=true;
          }
          for(int j=0;j<item.size();j++)
          {
            result.push_back(tmp+" "+item[j]);
          }
        }
        else if(recursive(left,dict,item)){
          output=true;
          for(int j=0;j<item.size();j++)
          {
            result.push_back(tmp+" "+item[j]);
          }
        }
      }
    }
    index[s]=result;
    return output;
  }
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(),wordDict.end());
    vector<string>result;
    recursive(s,dict,result);
    return result;
  }
};
#endif
int main()
{
  return 0;
}
