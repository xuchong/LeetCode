#include<iostream>
#include<vector>
using namespace std;
#define TL
#ifndef TL
class Solution {
public:
    int maxProduct(vector<int>& nums) {
      if(nums.empty())
        return 0;
      //products[i]: contains nums[i], the max result;
      vector<int> products(nums.size(),1);
      products[0]=nums[0];
      for(int i=1;i<nums.size();i++)
      {
        if(nums[i]==0)
        {
          products[i]=0;
          continue;
        }
        if(products[i-1]==0)
        {
          products[i]=nums[i];
        }else
        {
          products[i]=nums[i]*products[i-1];
        }
      }
      int lastzero=-1;
      int result=nums[0];
      if(nums[0]==0)
      {
        lastzero=0;
      }
      for(int i=1;i<nums.size();i++)
      {
        if(products[i]>result)
          result=products[i];
        if(nums[i]==0)
          lastzero=i;
        for(int j=lastzero+1;j<i;j++)
        {
          if(products[i]/products[j]>result)
          {
            result=products[i]/products[j];
          }
        }
      }
      return result;
    }
};
#elif
class Solution{
public:
  int maxProduct(vector<int>&nums){
    if(nums.empty())
      return 0;
    int result=nums[0];
    int maxproducts=nums[0],minproducts=nums[0];
    int a,b;
    for(int i=1;i<nums.size();i++)
    {
      a=minproducts;
      minproducts=nums[i]<nums[i]*minproducts?nums[i]:nums[i]*minproducts;
      minproducts=minproducts<nums[i]*maxproducts?minproducts:nums[i]*maxproducts;

      maxproducts=nums[i]>nums[i]*maxproducts?nums[i]:nums[i]*maxproducts;
      maxproducts=maxproducts>nums[i]*a?maxproducts:nums[i]*a;
      if(maxproducts>result)
        result=maxproducts;
    }
    return result;
  }
};
#endif
int main(int argc, char const *argv[]) {
  Solution s;
  vector<int>nums;

  return 0;
}
