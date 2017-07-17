#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> result;
      if(numRows==0)
        return result;
      for(int i=0;i<numRows;i++)
      {
        vector<int>item;
        for(int j=0;j<=i;j++)
        {
          if(j==0||j==i)
          {
            item.push_back(1);
          }
          else{
            item.push_back(result.back()[j-1]+result.back()[j]);
          }
        }
      }
      return result;
    }
};
int main()
{
  return 0;
}
