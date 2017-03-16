#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        int start,max,i,end;
        max=nums[0];
        start=0;
        for(i=0;i<nums.size();i++)
        {
            if(max>=nums.size()-1)
                return true;
            end=max;
            for(start=i+1;start<=end;start++)
            {
                if(start+nums[start]>max)
                    max=start+nums[start];
            }
            if(end==max)
                return false;
            i=end-1;
        }
    }
};
int main() {
    Solution s;
    vector<int> nums;
    int n,val;
    while(true)
    {
        cin>>n;
        nums.clear();
        while(n--)
        {
            cin>>val;
            nums.push_back(val);
        }
        cout<<s.canJump(nums)<<endl;
    }
    return 0;
}