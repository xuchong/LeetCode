#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(),nums.end());
        vector<int> nums1(nums);
        //3 zeros
        int count=0;
        int i=0;
        vector<int>::iterator it;
        for(it=nums1.begin();it!=nums1.end();)
        {
            if(*it==0)
            {
                count++;
                it=nums1.erase(it);
            } else
            {
                it++;
            }
        }
        if(count>=3)
        {
            vector<int> item;
            item.push_back(0);
            item.push_back(0);
            item.push_back(0);
            result.push_back(item);
        }
        //1zeros
        if(count>0)
        for(i;i<nums1.size()&&nums1[i]<0;i++)
        {
            if(i<nums1.size()-1&&nums1[i]==nums1[i+1])
            {
                continue;
            }
            for(int j=nums1.size()-1;j>=0&&nums1[j]>0;j--)
            {
                if(nums1[i]==-nums1[j])
                {
                    vector<int> item;
                    item.push_back(nums1[i]);
                    item.push_back(0);
                    item.push_back(nums1[j]);
                    result.push_back(item);
                    break;
                }
            }
        }
        //no zero
        for(i=0;i<nums1.size()&&nums1[i]<0;i++)
        {
            if(i>=1&&nums1[i]==nums1[i-1])
                continue;
            int start=i+1;
            int end=nums1.size()-1;
            int target=-nums1[i];
            while(start<end)
            {

                if(nums1[start]+nums1[end]==target)
                {
                    vector<int> item;
                    item.push_back(nums1[i]);
                    item.push_back(nums1[start]);
                    item.push_back(nums1[end]);
                    result.push_back(item);
                    start++;
                    while(start<end&&nums1[start]==nums1[start-1])
                        start++;
                }else if(nums1[start]+nums1[end]<target)
                {
                    start++;
                }else
                {
                    end--;
                }
            }
        }

        return result;
    }
};
int main() {
    Solution s;
    int n;
    int i,j;
    vector<int> data;
    vector<vector<int>> result;
    while(true)
    {
        cin>>n;
        data.clear();
        while(n--)
        {
            cin>>i;
            data.push_back(i);
        }
        result=s.threeSum(data);
        for(i=0;i<result.size();i++)
        {
            data=result[i];
            for(j=0;j<data.size();j++)
            {
                cout<<data[j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}