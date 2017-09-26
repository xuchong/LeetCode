class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int first=INT_MIN;
      deque<int> indexs;
      int index;
      for(int i=0;i<k;i++)
      {
        if(nums[i]>=first){
          first=nums[i];
          index=i;
        }
      }
      indexs.push_back(index);
      for(int i=index+1;i<k;i++)
      {
        if(nums[i]<nums[indexs.back()]){
          indexs.push_back(i);
        }else
        {
          indexs.pop_back();
          i--;
        }
      }
      vector<int> result;
      result.push_back(first);
      for(int i=k;i<nums.size();i++)
      {
        //when k is enough
        if(!indexes.empty()&&i-indexes.front()>=k)
        {
          indexs.pop_front();
        }
        if(indexes.empty()||nums[i]<nums[indexs.back()]){
          indexs.push_back(i);
        }else
        {
          indexs.pop_back();
          i--;
          continue;
        }
        result.push_back(nums[indexs.front()]);
      }
      return result;
    }
};
