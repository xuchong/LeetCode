class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      if(prices.size()==0||k<=0)
        return 0;

      //prune
      if(k>=prices.size()/2)
      {
        int result=0;
        for(int i=1;i<prices.size();i++)
        {
          if(prices[i]>prices[i-1])
            result+=prices[i]-prices[i-1];
        }
        return result;
      }
      //dp: smartest part
      int dp[k+1][prices.size()+1]={0};
      int tmp;
      for(int i=1;i<=k;i++)
      {
        tmp=-prices[0];
        for(int j=1;j<prices.size();j++)
        {
          //with prices[j] and without prices[j]....  max of the two
          dp[i][j]=max(dp[i][j-1],tmp+prices[j]);
          //refresh tmp: with or without (means:  max k-1 and lowest prices[])
          tmp=max(tmp,dp[i-1][j-1]-prices[j]);
        }
      }
      return dp[k][prices.size()-1];
    }
};
