class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int result=0;
        if(matrix.empty())
          return result;
        int count,m,n;
        for(int i=0;i<matrix.size();i++)
        {
          for(int j=0;j<matrix[0].size();j++)
          {
            //find max square
            if(matrix[i][j]=='1')
            {
              count=1;
              int k=1;
              while(i+k<matrix.size()&&j+k<matrix[0].size())
              {
                for(m=i;m<=i+k;m++)
                {
                  if(matrix[m][j+k]=='0')
                    break;
                }
                if(m<=i+k)
                 break;
                for(n=j;n<=j+k;n++)
                {
                  if(matrix[i+k][n]=='0')
                    break;
                }
                if(n<=j+k)
                 break;
                k++;
                count++;
              }
              if(count>result)
                result=count;
            }
          }
        }
        return result*result;
    }
};
