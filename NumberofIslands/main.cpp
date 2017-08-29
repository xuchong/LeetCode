class Solution {
private:
  void change(vector<vector<char>>&grid,int x,int y)
  {
    grid[x][y]=0;
    if(x-1>=0&&grid[x-1][y]=='1')
    {
      change(grid,x-1,y);
    }
    if(x+1<grid.size()&&grid[x+1][y]=='1')
    {
      change(grid,x+1,y);
    }
    if(y-1>=0&&grid[x][y-1]=='1')
    {
      change(grid,x,y-1);
    }
    if(y+1<grid[0].size()&&grid[x][y+1]=='1')
    {
      change(grid,x,y+1);
    }
  }
public:
    int numIslands(vector<vector<char>>& grid) {
      int result=0;
      if(grid.empty())
        return result;
      for(int i=0;i<grid.size();i++)
      {
        for(int j=0;j<grid[0].size();j++)
        {
          if(grid[i][j]=='1')
          {
            result=result+1;
            change(grid,i,j);
          }
        }
      }
      return result;
    }
};
