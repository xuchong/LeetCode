/***********************************************************************
 @Author: xuchong
 @Created Time : 二 10/ 8 00:07:23 2019
 @File Name: main.cpp
 @Description:
 ***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxN = 0, minN= 0x7fffffff;
        int i;
        long long int sum = 0, t=0;
        for(i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(maxN<nums[i])
                maxN = nums[i];
            if(minN>nums[i])
                minN = nums[i];
        }
        t = (maxN + 1) * maxN / 2;
        if(minN!=0)
            return 0;
        if(t==sum)
            return maxN + 1;
        else
            return t - sum;
    }
};

int main()
{
    int a = 0x7fffffff + 1;
    cout<<a<<endl;
    Solution s = Solution();
    //vector<int> input={3,0,1};
    vector<int> input = {9,6,4,2,3,5,7,0,1};
    cout<<s.missingNumber(input)<<endl;
    return 0;
}
