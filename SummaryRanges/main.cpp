class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      vector<string> result;
      if(nums.empty())
        return result;
      int shift=nums[0];
      int start=0;
      for(int i=1;i<nums.size();i++)
      {
        if(shift+i!=nums[i])
        {
          stringstream ss;
          ss<<nums[start];
          if(i-1>start)
          {
            ss<<"->"<<nums[i-1];

          }
          result.push_back(ss.str());
          start=i;
          shift=nums[i]-i;
        }
      }
      if(start!=nums.size()-1)
      {
        stringstream ss;
        ss<<nums[start];
        ss<<"->"<<nums[nums.size()-1];
        result.push_back(ss.str());
      }else
      {
        stringstream ss;
        ss<<nums[nums.size()-1];
        result.push_back(ss.str());
      }
      return result;
    }
};
