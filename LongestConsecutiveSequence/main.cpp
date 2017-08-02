#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_map<int,int> index;
      int result=0;
      if(nums.empty())
        return result;
      for(int i=0;i<nums.size();i++)
      {
        if(index.find(nums[i])==index.end())
        {
          //right
          if(index.find(nums[i]+1)!=index.end())
          {
            index[nums[i]]=index[nums[i]+1];
            index[index[nums[i]+1]]=nums[i];
          }else
          {
            index[nums[i]]=nums[i];
          }
          //left
          if(index.find(nums[i]-1)!=index.end())
          {
            index[index[nums[i]-1]]=index[nums[i]];
            index[index[nums[i]]]=index[nums[i]-1];
          }
        }
      }
      for(unordered_map<int,int>::iterator it=index.begin();it!=index.end();it++)
      {
        result=max(result,abs(it->first-it->second));
      }
      return result+1;
    }
};
int main()
{
  return 0;
}
