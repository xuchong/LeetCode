#include <iostream>
#include<cstring>
#include<string>
#include <vector>
#include <map>
using namespace std;
class Solution {
private:
    map<char,int> list;
public:
    int romanToInt(string s) {

        int result=0;
        vector<int> data;
        data.clear();
        int tmp;
        int t;
        int i;
        list.clear();
        list['I']=1;
        list['V']=5;
        list['X']=10;
        list['L']=50;
        list['C']=100;
        list['D']=500;
        list['M']=1000;
        for(i=0;i<s.length();i++)
        {
            data.push_back(list[s[i]]);
        }
        tmp=0;
        for(i=data.size()-1;i>=0;i--)
        {
            t=data[i];
            if(tmp<=t)
            {
                result+=t;
                tmp=t;
            }else
            {
                result-=t;
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    string input;
    while (true)
    {
        cin>>input;
        cout<<s.romanToInt(input)<<endl;
    }
    return 0;
}