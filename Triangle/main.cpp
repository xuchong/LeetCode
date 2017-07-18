#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
      int sum=0;
      if(triangle.size()==0)
        return sum;
      int n=triangle.size();
      vector<int> item(n);
      item[0]=triangle[0][0];
      for(int i=1;i<triangle.size();i++){
        item[i]=triangle[i][0]+item[i-1];
      }
      item[0]=item[n-1];
      sum=triangle[0][0];
      int last,pre;
      for(int i=1;i<triangle.size();i++)
      {
        for(int j=i+1;j<n;j++)
        {
          pre=item[j];
          if(j==i+1){
              item[j]=min(item[j-1],triangle[j-1][i]+sum)+triangle[j][i];
          }
          else{
              item[j]=min(item[j-1],last)+triangle[j][i];
          }
          last=pre;
        }
        item[i]=item[n-1];
        sum+=triangle[i][i];
      }

      for(int i=0;i<n-1;i++)
      {
        if(item[i]<sum)
          sum=item[i];
      }
      return sum;
    }
};
int main()
{
  return 0;
}
