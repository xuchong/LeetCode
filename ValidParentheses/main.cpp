#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if(s.length()==0)
            return true;
        vector<char> que;
        que.push_back(s[0]);
        int index=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='['||s[i]=='('||s[i]=='{')
            {
                que.push_back(s[i]);
                index++;
            }else
            {
                if(i>=0)
                {
                    if((s[i]==')'&&que[index]=='(')||(s[i]==']'&&que[index]=='[')||(s[i]=='}'&&que[index]=='{'))
                    {
                        que.pop_back();
                        index--;
                    } else
                    {
                        return false;
                    }
                }else
                {
                    return false;
                }
            }
        }
        if(index>=0)
            return false;
        return true;
    }
};
int main() {
    Solution s;
    string ss;
    while(true)
    {
        cin>>ss;
        cout<<s.isValid(ss)<<endl;
    }
    return 0;
}