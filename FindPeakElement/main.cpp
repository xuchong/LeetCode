class Solution {
private:
    int find(vector<int>&nums,int start,int end)
    {
      if(start==end)
      {
        return start;
      }
      if(nums[start]>nums[start+1]&&(start==0||nums[start]>nums[start-1]))
        return start;
      if(nums[end]>nums[end-1]&&(end==nums.size()-1||nums[end]>nums[end+1]))
        return end;
      int middle=(start+end)/2;
      if(nums[middle]>nums[start]&&nums[middle]>nums[end])
      {
        if(nums[middle]<nums[middle+1])
        {
          return find(nums,middle,end);
        }else
        {
          return find(nums,start,middle);
        }
      }else if(nums[middle]<=nums[start])
      {
        return find(nums,start,middle);
      }else{
        return find(nums,middle,end);
      }
    }
public:
    int findPeakElement(vector<int>& nums) {
      if(nums.empty())
        return -1;
      return find(nums,0,nums.size()-1);
    }
};
