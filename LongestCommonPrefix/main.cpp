#include <iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        int flag=1;
        if(strs.size()==0)
            return  result;
        int i,j=0;
        while(flag&&j<strs[0].length())
        {
            for(i=1;i<strs.size();i++)
            {
                if(strs[i].length()>j&&strs[0][j]==strs[i][j])
                    continue;
                else
                {
                    flag=0;
                    j--;
                    break;
                }
            }
            j++;
        }
        return strs[0].substr(0,j);
    }
};
int main() {
    Solution s;
    vector<string> data;
    int n;
    string ss;
    while(true)
    {
        cin>>n;
        data.clear();
        while(n--)
        {
            cin>>ss;
            data.push_back(ss);
        }
        cout<<s.longestCommonPrefix(data)<<endl;
    }
    return 0;
}