#include <iostream>
#include<vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length=nums.size();
        if(length==0)
            return 0;
        sort(nums.begin(),nums.end());
        int newtarget;
        int i,j;
        int result;
        int closest=int(pow(2,31)-1);
        for(i=0;i<length;i++)
        {
            int start=i+1;
            int end=length-1;
            newtarget=target-nums[i];
            while(start<end)
            {
                if(nums[start]+nums[end]==newtarget)
                {
                    return target;
                } else if(nums[start]+nums[end]<newtarget)
                {
                    if(closest>(newtarget-nums[start]-nums[end]))
                    {
                        closest=newtarget-nums[start]-nums[end];
                        result=target-closest;
                    }
                    start++;
                }else
                {
                    if(closest>(nums[start]+nums[end]-newtarget))
                    {
                        closest=nums[start]+nums[end]-newtarget;
                        result=target+closest;
                    }
                    end--;
                }
            }
        }
        return  result;
    }
};
int main() {
    Solution s;
    int n,t;
    vector<int> data;
    while (true)
    {
        cin>>n;
        data.clear();
        while(n--)
        {
            cin>>t;
            data.push_back(t);
        }
        cin>>t;
        cout<<s.threeSumClosest(data,t)<<endl;
    }
    return 0;
}