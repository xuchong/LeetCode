#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int _min;
      if(prices.size()==0)
        return 0;
      _min=prices[0];
      int result=0;
      for(int i=1;i<prices.size();i++)
      {
        _min=min(_min,prices[i]);
        if(result<prices[i]-_min)
        {
          result=prices[i]-_min;
        }
      }
      return result;
    }
};
int main()
{
  return 0;
}
