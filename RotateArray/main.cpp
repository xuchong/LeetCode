class Solution {
private:
  void reverse(vector<int>&nums,int start,int end)
  {
    int tmp;
    while(start<end)
    {
      tmp=nums[start];
      nums[start]=nums[end];
      nums[end]=tmp;
      start++;
      end--;
    }
  }
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty())
          return;
        int n=nums.size();
        k=k%n;
        if(k==0)
          return;
        //reverse
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};
