#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int length=nums.size();
        if(length==1)
            return 0;
        int count=1;
        int max;
        int start=nums[0];
        for(int i=0;i<length;)
        {
            //max index can reach: nums[i]+i
            if(start+1>=length)
                return count;
            max=-1;
            for(int j=i+1;j<start+1;j++)
            {
                if(nums[j]+j>nums[i]+i&&max<(nums[j]+j))
                {
                    max=nums[j]+j;
                }
            }
            i=start;
            count++;
            start=max;
        }

    }
};
//9 6 9 1 5 6 0 0 5 9
int main() {
    Solution s;
    int n,value;
    vector<int> nums;
    while (true)
    {
        cin>>n;
        nums.clear();
        while(n--)
        {
            cin>>value;
            nums.push_back(value);
        }
        cout<<s.jump(nums)<<endl;
    }
    return 0;
}