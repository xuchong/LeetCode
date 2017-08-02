#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// DFS recursive stack over flow : so change to space! BFS
struct myPoint{
  int x;
  int y;
  myPoint(int _x,int _y):x(_x),y(_y){}
};
class Solution {
private:
  bool recursive(vector<vector<char>>& flags,int m,int n,vector<int>& region)
  {
    bool isRegion=true;
    if(m==0||m==flags.size()-1||n==0||n==flags[0].size()-1)
      isRegion=false;

    flags[m][n]='X';
    region.push_back(m);
    region.push_back(n);
    //four direction
    if(m-1>=0)
    {
      if(flags[m-1][n]=='O')
      {
        if(!recursive(flags,m-1,n,region))
          isRegion=false;
      }
    }
    if(m+1<flags.size())
    {
      if(flags[m+1][n]=='O')
      {
        if(!recursive(flags,m+1,n,region))
          isRegion=false;
      }
    }
    if(n-1>=0)
    {
      if(flags[m][n-1]=='O')
      {
        if(!recursive(flags,m,n-1,region))
          isRegion=false;
      }
    }
    if(n+1<flags[0].size())
    {
      if(flags[m][n+1]=='O')
      {
        if(!recursive(flags,m,n+1,region))
          isRegion=false;
      }
    }
    return isRegion;
  }
public:
  void solve(vector<vector<char>>& board) {
    if(board.empty())
      return;
    vector<vector<char>> flags(board);
    vector<int> region;
    queue<int> layer;
    //myPoint item;
    bool isRegion;
    int m,n;
    for(int i=0;i<flags.size();i++)
    {
      for(int j=0;j<flags[0].size();j++)
      {
        if(flags[i][j]=='O')
        {
          layer.push(i);
          layer.push(j);
          flags[i][j]='X';
          isRegion=true;
          while(!layer.empty())
          {
            m=layer.front();
            layer.pop();
            n=layer.front();
            layer.pop();
            if(m==0||m==flags.size()-1||n==0||n==flags[0].size()-1)
              isRegion=false;
            region.push_back(m);
            region.push_back(n);
            //four direction
            if(m-1>=0)
            {
              if(flags[m-1][n]=='O')
              {
                layer.push(m-1);
                layer.push(n);
                flags[m-1][n]='X';
              }
            }
            if(m+1<flags.size())
            {
              if(flags[m+1][n]=='O')
              {
                layer.push(m+1);
                layer.push(n);
                flags[m+1][n]='X';
              }
            }
            if(n-1>=0)
            {
              if(flags[m][n-1]=='O')
              {
                layer.push(m);
                layer.push(n-1);
                flags[m][n-1]='X';
              }
            }
            if(n+1<flags[0].size())
            {
              if(flags[m][n+1]=='O')
              {
                layer.push(m);
                layer.push(n+1);
                flags[m][n+1]='X';
              }
            }
          }

          if(isRegion)
          {
            for(int k=0;k<region.size();k=k+2)
            {
              board[region[k]][region[k+1]]='X';
            }
          }
          region.clear();
        }
      }
    }
  }
};
int main()
{
  return 0;
}
