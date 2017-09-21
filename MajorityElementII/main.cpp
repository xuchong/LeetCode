class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> results;
      if(nums.empty())
        return results;
      int a=0,b=1,counta=0,countb=0;
      for(auto num: nums)
      {
        if(a==num)
        {
          counta++;
        }else if(b==num)
        {
          countb++;
        }else if(counta==0)
        {
          a=num;
          counta=1;
        }else if(countb==0)
        {
          b=num;
          countb=1;
        }else
        {
          counta--;
          countb--;
        }
      }
      counta=countb=0;
      for(auto num: nums)
      {
        if(num==a)counta++;
        else if(num==b)countb++;
      }
      if(counta>nums.size()/3)results.push_back(a);
      if(countb>nums.size()/3)results.push_back(b);
      return results;
    }
};
