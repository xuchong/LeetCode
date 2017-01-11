#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int static cmp(const vector<int>& a,const vector<int>&b)
    {
        if(a[0]<b[0])
            return 1;
        else if(a[0]==b[0]&&a[1]<b[1])
            return 1;
        else if(a[0]==b[0]&&a[1]==b[1]&&a[2]<b[2])
            return 1;
        else if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2]&&a[3]<b[3])
            return 1;
        else
            return 0;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if(nums.size()<4)
            return result;
        int i,j;
        //map<int,vector<pair<int,int>>> data;
        //map C++: 红黑树 ,find time: log(N)   ,  Time limit because of Build N^2
        /*unordered_map:list map,find time: N*/
        unordered_map<int,vector<pair<int,int>>> data;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                data[nums[i]+nums[j]].push_back(make_pair(i,j));
            }
        }
        //map<int,vector<pair<int,int>>>::iterator it;
        unordered_map<int,vector<pair<int,int>>>::iterator it;
        for(it=data.begin();it!=data.end();)
        {

            if(data.find(target-it->first)!=data.end()){
                vector<pair<int,int>> start=it->second;
                vector<pair<int,int>> end=data[target-it->first];
                for(i=0;i<start.size();i++)
                    for(j=0;j<end.size();j++)
                    {
                        if(start[i].first!=end[j].first&&start[i].second!=end[j].second
                           &&start[i].second!=end[j].first&&start[i].first!=end[j].second)
                        {
                            vector<int> item;
                            item.push_back(nums[start[i].first]);
                            item.push_back(nums[start[i].second]);
                            item.push_back(nums[end[j].first]);
                            item.push_back(nums[end[j].second]);
                            sort(item.begin(),item.end());
                            result.push_back(item);
                        }
                    }
                it=data.erase(it);
            }else
            {
                it++;
            }

        }
        sort(result.begin(),result.end(),cmp);
        vector<vector<int>>::iterator itr;
        vector<vector<int>> r;
        //dirty code
        if(result.size()>0)
            r.push_back(result[0]);
        for(i=1;i<result.size();i++)
        {
            vector<int> item0=result[i-1];
            vector<int> item=result[i];

            for(j=0;j<item0.size();j++)
            {
                if(item[j]!=item0[j])
                    break;
            }
            if(j!=item0.size())
                r.push_back(item);
        }
        return r;
    }
};
int main() {
    Solution s;
    int target;
    int n;
    int data;
    vector<int> nums;
    vector<vector<int>> result;
    while(true)
    {
        cin>>n;
        nums.clear();
        while(n--)
        {
            cin>>data;
            nums.push_back(data);
        }
        cin>>target;
        result=s.fourSum(nums,target);
        for(int i=0;i<result.size();i++)
        {
            vector<int> item=result[i];
            for(int j=0;j<item.size();j++)
            {
                cout<<item[j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}