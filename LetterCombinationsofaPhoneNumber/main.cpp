#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0)
            return result;

        return add(digits);
    }

private:
    vector<string> add(string d)
    {
        vector<string> result;
        vector<string> data;
        if(d.length()==0)
            return result;
        int ccc=d[0]-'2';
        int flag=0;
        if(ccc>5)
            flag=1;
        char a=ccc*3+'a'+flag;
        char b=a+1;
        char c=a+2;
        stringstream ss;
        ss<<a;
        string aa=ss.str();
        ss.str("");
        ss<<b;
        string bb=ss.str();
        ss.str("");
        ss<<c;
        string cc=ss.str();
        data=add(d.substr(1,d.length()-1));
        if(data.size()>0)
            for(int i=0;i<data.size();i++)
            {
                result.push_back(aa+data[i]);
                result.push_back(bb+data[i]);
                result.push_back(cc+data[i]);
                if(ccc==5)
                    result.push_back("s"+data[i]);
                else if(ccc==7)
                {
                    result.push_back("z"+data[i]);
                }
            }
        else
        {
            result.push_back(aa);
            result.push_back(bb);
            result.push_back(cc);
            if(ccc==5)
                result.push_back("s");
            else if(ccc==7)
            {
                result.push_back("z");
            }
        }
        return result;

    }
};
int main() {
    Solution s;
    string ss;
    vector<string> result;
    while (true)
    {
        cin>>ss;
        result=s.letterCombinations(ss);
        for(int i=0;i<result.size();i++)
            cout<<result[i]<<endl;
    }
    return 0;
}