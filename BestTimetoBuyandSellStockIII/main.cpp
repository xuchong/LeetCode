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
      vector<int> left,right;
      int buy,sell;
      buy=prices[0];
      left.push_back(result);
      for(int i=1;i<prices.size();i++)
      {
        if(prices[i]>buy&&prices[i]-buy>result)
        {
          result=prices[i]-buy;
          left.push_back(result);
        }else if(prices[i]<buy){
          buy=prices[i];
          left.push_back(result);
        }else{
          left.push_back(result);
        }
      }
      result=0;
      sell=prices[prices.size()-1];
      right.push_back(result);
      for(int i=prices.size()-2;i>=0;i--)
      {
        if(prices[i]<sell&&sell-prices[i]>result)
        {
          result=sell-prices[i];
          right.push_back(result);
        }else if(prices[i]>sell)
        {
          sell=prices[i];
          right.push_back(result);
        }else{
          right.push_back(result);
        }
      }
      //after get left and right.
      result=0;
      for(int i=0;i<prices.size();i++)
      {
        if(left[i]+right[prices.size()-1-i]>result)
          result=left[i]+right[prices.size()-1-i];
      }

      return result;
    }
};
int main()
{
  vector<int> prices(2);
  prices[0]=1;
  prices[1]=2;
  Solution s;
  cout<<s.maxProfit(prices)<<endl;
  return 0;
}
