#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
      if(nums.empty())
        return 0;
      int n=nums.size();
      int left,right,middle;
      left=0;
      right=n-1;
      int value=nums[right];
      //find one < value
      while(left<right)
      {
        middle=(left+right)/2;
        if(nums[middle]>value)
        {
          left=middle+1;
        }else
        {
          value=nums[middle];
          right=middle;
        }
      }
      return value;
    }
};
