#include<iostream>

//bucket order algorithm： time complexity （N+C）  space： N
class Solution {
public:
    int maximumGap(vector<int>& nums) {
      if(nums.size()<2)
        return 0;
      int maxNum=INT_MIN,minNum=INT_MAX;
      for(int i=0;i<nums.size();i++)
      {
        maxNum=nums[i]>maxNum?nums[i]:maxNum;
        minNum=nums[i]<minNum?nums[i]:minNum;
      }

      int gap=(int)ceil((double)(maxNum-minNum)/(nums.size()-1));
      if(gap==0)
      {
        return 0;
      }
      //分成了  min---->max 共 N 桶
      //桶内：数之间的gap小于最小的 Max Gap，所以Max Gap存在与桶之间
      int N=(maxNum-minNum)/gap+1;
      int buckets[N][2]={0};  //each buckets,  min max
      for(int i=0;i<N;i++)
      {
        buckets[i][0]=INT_MAX;
        buckets[i][1]=INT_MIN;
      }
      //determine each number belongs to which buckets
      int index;
      for(int i=0;i<nums.size();i++)
      {
        index=(nums[i]-minNum)/gap;
        if(buckets[index][0]>nums[i])
          buckets[index][0]=nums[i];
        if(buckets[index][1]<nums[i])
          buckets[index][1]=nums[i];
      }
      int result=0,lastone=-1;
      for(int i=0;i<N;i++)
      {
        if(buckets[i][0]<=buckets[i][1])
        {
          if(lastone!=-1)
          {
            result=buckets[i][0]-lastone>result?buckets[i][0]-lastone:result;
          }
          lastone=buckets[i][1];
        }
      }
      return result;
    }
};
