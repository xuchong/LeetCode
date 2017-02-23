#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return NULL;
        string start="1";
        char item;
        int count,i,j;
        string result;
        stringstream ss;
        for(i=1;i<n;i++)
        {
            item=start[0];
            count=1;
            j=1;
            result="";
            while(j<start.length())
            {
                if(start[j]==item)
                {
                    count++;
                }else
                {
                    ss.clear();
                    ss.str("");
                    ss<<count;
                    result+=ss.str()+item;
                    item=start[j];
                    count=1;
                }
                j++;
            }
            ss.clear();
            ss.str("");
            ss<<count;
            result+=ss.str()+item;
            start=result;
        }
        return start;
    }
};
int main() {
    Solution s;
    int n;
    while(true)
    {
        cin>>n;
        cout<<s.countAndSay(n)<<endl;
    }
    return 0;
}