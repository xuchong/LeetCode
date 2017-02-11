#include <iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int result=0;
        string result_str="0";
        if(divisor==0)
            return INT_MAX;
        if(dividend==INT_MIN&&divisor==-1)
            return INT_MAX;
        if(divisor==1)
            return dividend;
        else if(dividend==-1)
            return -dividend;
        int flag=1;
        long dividenda=dividend,divisorb=divisor;
        if(dividend>=0&&divisor<0)
        {
            flag=-1;
            divisorb=-divisor;
        } else if(dividend<0&&divisor>0)
        {
            flag=-1;
            dividenda=-dividend;
        }
        if(dividenda<0)
            dividenda=-dividenda;
        if(divisorb<0)
            divisorb=-divisorb;

        stringstream ss;
        ss<<dividenda;
        string da=ss.str();
        ss.str("");
        ss<<divisorb;
        string db=ss.str();
        int start=0;
        long newda=0;
        string tmp;
        int count=0;
        int last=0;
        while(start<=da.length())
        {
            if(newda<divisorb&&start<da.length())
            {
                ss.str("");
                ss.clear();
                ss<<newda;
                tmp=ss.str();
                tmp+=da[start];
                ss.str(tmp);
                ss>>newda;
                if(last==1)
                    result_str+="0";
                last=1;
                start++;
            }else if(newda>=divisorb)
            {
                count=0;
                while(newda>=divisorb)
                {
                    newda=newda-divisorb;
                    count++;
                }
                ss.str("");
                ss.clear();
                ss<<count;
                result_str+=ss.str();
                last=0;
            }else
            {
                start++;
                if(last==1)
                    result_str+="0";
            }
        }
        ss.clear();
        ss.str(result_str);
        ss>>result;
        if(flag==-1)
            result=-result;
        return result;
    }
};
int main() {
    Solution s;
    int a,b;
    while(true)
    {
        cin>>a>>b;
        cout<<s.divide(a,b)<<endl;
    }
    return 0;
}