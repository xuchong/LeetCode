#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      if(prices.size()==0)
        return 0;
      int result=0;
      int buy,sell;
      buy=prices[0];
      for(int i=1;i<prices.size();i++)
      {
        if(prices[i]>buy)
        {
          result+=prices[i]-buy;
          buy=prices[i];
        }else if(prices[i]<buy){
          buy=prices[i];
        }
      }
      return result;
    }
};
int main()
{
  return 0;
}
