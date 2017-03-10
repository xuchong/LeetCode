#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
private:
    string changeOrder(string str)
    {
        sort(str.begin(),str.end());
        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size()==0)
            return result;
        unordered_map<string,vector<string>> map_result;
        string tmp;
        for(int i=0;i<strs.size();i++)
        {
            tmp=changeOrder(strs[i]);
            if(map_result.find(tmp)==map_result.end()) {
                vector<string> s;
                s.push_back(strs[i]);
                map_result[tmp] = s;
            } else
            {
                map_result[tmp].push_back(strs[i]);
            }
        }
        unordered_map<string,vector<string>>::iterator it;
        for(it=map_result.begin();it!=map_result.end();it++)
        {
            result.push_back(it->second);
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<string> strs;
    string value;
    int n;
    vector<vector<string>> result;
    while(true)
    {
        cin>>n;
        strs.clear();
        while(n--)
        {
            cin>>value;
            strs.push_back(value);
        }
        result=s.groupAnagrams(strs);
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<result[i].size();j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}