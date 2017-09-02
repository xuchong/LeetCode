class Solution {
public:
    int rob(vector<int>& nums) {
        int a0,a1,tmp;
        if(nums.empty())
          return 0;
        a0=0;
        a1=nums[0];
        // bool isIncludeFirst=false;
        // if(nums.size()==2)
        // {
        //   return max(nums[0],nums[1]);
        // }
        // if(num.size()>2)
        // {
        //   if(a[2]+a[0]>a[1])
        // }
        for(int i=1;i<nums.size()-1;i++)
        {
          if(nums[i]+a0>a1)
          {
            tmp=a1;
            a1=a0+nums[i];
            a0=tmp;
          }else
          {
            a0=a1;
          }
        }
        int result=max(a0,a1);
        if(nums.size()<2)
          return result;
        a0=0;
        a1=nums[1];
        for(int i=2;i<nums.size();i++)
        {
          if(nums[i]+a0>a1)
          {
            tmp=a1;
            a1=a0+nums[i];
            a0=tmp;
          }else
          {
            a0=a1;
          }
        }
        result=max(result,max(a0,a1));
        return result;
    }
};
