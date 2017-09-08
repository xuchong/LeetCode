class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty())
          return false;
        int i=0,j=0;
        unordered_set<int> sets;
        if(nums.size()<=k)
        {
          k=nums.size()-1;
        }
        for(j=0;j<=k;j++)
        {
          if(sets.find(nums[j])!=sets.end())
            return true;
          sets.insert(nums[j]);
        }
        for(j;j<nums.size();j++)
        {
          sets.erase(nums[j-k-1]);
          if(sets.find(nums[j])!=sets.end())
            return true;
          sets.insert(nums[j]);
        }
        return false;
    }
};
