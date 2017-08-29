class Solution {
public:
    int rob(vector<int>& nums) {
        int result=0;
        if(nums.empty())
          return result;
        if(nums.size()==1)
          return nums[0];
        int a=nums[0],b=0,tmp;
        for(int i=1;i<nums.size();i++)
        {
          if(nums[i]+b>a)
          {
            tmp=a;
            a=nums[i]+b;
            b=tmp;
          }else
          {
            b=a;
          }
        }
        return a;
    }
};
