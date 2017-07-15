#include<iostream>
#include<unorder_map>
#include<vector>
#include<algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int numDistinct(string s, string t) {
      int dp[20000][50]={0};
      // target in s string
      // unorder_map<int,vector<int>> index;
      // for(int i=0;i<t.length();i++)
      // {
      //   if(index.find(t[i])==index.end())
      //   {
      //     vector<int> item;
      //     index[t[i]]=item;
      //   }
      // }
      // //build index
      // for(int i=0;i<s.length();i++)
      // {
      //   if(index.find(s[i])!=index.end())
      //   {
      //     index[s[i]].push_back(i);
      //   }
      // }
      //init dp
      for(int i=0;i<s.length();i++)
      {
        if(s[i]==t[0])
          dp[i+1][1]=dp[i][1]+1;
        else
          dp[i+1][1]=dp[i][1];
      }
      for(int j=1;j<t.length();j++)
        for(int i=j;i<s.length();i++)
        {
          //build dp[i+1][j+1]
          dp[i+1][j+1]=dp[i][j+1];
          if(s[i]==t[j])
          {
            dp[i+1][j+1]+=dp[i][j];
          }
        }
      return dp[s.length()][t.length()];
    }
};
int main()
{
  return 0;
}
