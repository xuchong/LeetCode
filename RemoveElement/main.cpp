#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length=0;
        int p,i;
        if(nums.size()==0)
            return length;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
                nums[i-length]=nums[i];
            else
            {
                length++;
            }
        }
        for(i=0;i<length;i++)
            nums.pop_back();
        return nums.size();
    }
};
int main() {
    Solution s;
    int n,val,i;
    vector<int>nums;
    while(true)
    {
        cin>>n;
        nums.clear();
        while(n--)
        {
            cin>>i;
            nums.push_back(i);
        }
        cin>>val;
        n=s.removeElement(nums,val);
        for(i=0;i<n;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    return 0;
}