#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0||nums.size()==1)
            return;
        int i;
        for(i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
                break;
        }
        if(i==0)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        i--;
        // 2 5 4 3 => 3 2 4 5
        // 5 6 4 3 => 6 3 4 5
        int j;
        for(j=nums.size()-1;j>i;j--)
        {
            if(nums[j]>nums[i])
                break;
        }
        int tmp=nums[i];
        nums[i]=nums[j];
        nums[j]=tmp;
        sort(nums.begin()+i+1,nums.end());
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
        s.nextPermutation(nums);
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}