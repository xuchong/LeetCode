
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      if(dungeon.empty())
        return 0;
      vector<vector<int>> index(dungeon.size(),vector<int>(dungeon[0].size(),0));
      int m=index.size(),n=index[0].size();
      if(dungeon[m-1][n-1]<0)
        index[m-1][n-1]=-dungeon[m-1][n-1];
      //init
      for(int i=m-2;i>=0;i--)
      {
          index[i][n-1]=index[i+1][n-1]-dungeon[i][n-1];
          if(index[i][n-1]<0)
            index[i][n-1]=0;
      }
      for(int i=n-2;i>=0;i--)
      {
          index[m-1][i]=index[m-1][i+1]-dungeon[m-1][i];
          if(index[m-1][i]<0)
            index[m-1][i]=0;
      }
      int i=2;
      while(m-i>=0&&n-i>=0)
      {
        for(int k=m-i;k>=0;k--)
        {
          index[k][n-i]=index[k+1][n-i]-dungeon[k][n-i];
          if(index[k][n-i]>index[k][n-i+1]-dungeon[k][n-i])
          {
            index[k][n-i]=index[k][n-i+1]-dungeon[k][n-i];
          }
          if(index[k][n-i]<0)
            index[k][n-i]=0;
        }
        for(int k=n-i;k>=0;k--)
        {
          index[m-i][k]=index[m-i][k+1]-dungeon[m-i][k];
          if(index[m-i][k]>index[m-i+1][k]-dungeon[m-i][k])
          {
            index[m-i][k]=index[m-i+1][k]-dungeon[m-i][k];
          }
          if(index[m-i][k]<0)
            index[m-i][k]=0;
        }
        i++;
      }
      return index[0][0]+1;
    }
};
