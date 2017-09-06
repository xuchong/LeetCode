class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bool result=false;
        for(auto it=nums.begin();nums.end()-it>1;it++)
        {
          if(*it==*(it+1))
          {
            result=true;
            break;
          }
        }
        return result;
    }
};
