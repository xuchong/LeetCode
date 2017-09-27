class Solution {
private:
  int getRow(vector<vector<int>>& matrix,int row,int t)
  {
    int start=0,end=matrix[0].size()-1;
    int middle;
    while(start<end)
    {
      middle=(start+end)/2;
      if(matrix[row][middle]<t)
      {
        start=middle+1;
      }else if(matrix[row][middle]>t)
      {
        end=middle-1;
      }else
      {
        return middle;
      }
    }
    if(matrix[row][start]>t)
      start--;
    return start;
  }
  int getCol(vector<vector<int>>& matrix,int col,int t)
  {
    int start=0,end=matrix.size()-1;
    int middle;
    while(start<end)
    {
      middle=(start+end)/2;
      if(matrix[middle][col]<t)
      {
        start=middle+1;
      }else if(matrix[middle][col]>t)
      {
        end=middle-1;
      }else
      {
        return middle;
      }
    }
    if(matrix[start][col]<t)
      start++;
    return start;
  }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

      if(matrix.empty()||matrix.size()==0||matrix[0].size()==0)
        return false;

      int row=0,col=0;
      do {
        col=getRow(matrix,row,target);
        if(col<0||col>=matrix[0].size())
          return false;
        if(matrix[row][col]==target)
          return true;
        row=getCol(matrix,col,target);
        if(row<0||row>=matrix.size())
          return false;
        if(matrix[row][col]==target)
          return true;
      } while(true);
      return false;
    }
};
