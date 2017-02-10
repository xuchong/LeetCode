#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length=0;
        if(nums.size()==0)
            return  length;
        int i,j,p=nums[0];
        length++;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]==p)
                continue;
            else
            {
                p=nums[i];
                nums[length]=p;
                length++;
            }
        }
        for(int i=0;i<nums.size()-length;i++)
            nums.pop_back();
        return length;
    }
};
int main() {
    Solution s;
    vector<int> nums;
    int n,val;
    while (true)
    {
        cin>>n;
        nums.clear();
        while(n--)
        {
            cin>>val;
            nums.push_back(val);
        }
        n=s.removeDuplicates(nums);
        cout<<n<<" "<<nums.size()<<endl;
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        cout<<endl;
    }
    return 0;
}