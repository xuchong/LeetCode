class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())
          return 0;
        int m=0,n=0,m_index=-1,n_index=0;
        int result=INT_MAX;
        for( n_index;n_index<nums.size();n_index++)
        {
          n+=nums[n_index];
          if(n-m>=s)
          {
            while(n-m>=s)
            {
              //cout<<"n-m"<<n-m<<endl;
              if(result>n_index-m_index)
              {
                result=n_index-m_index;
                cout<<result<<endl;
              }
              m_index++;
              m+=nums[m_index];
            }
          }
        }
        if(n<s)
            result=0;
        return result;
    }
};
