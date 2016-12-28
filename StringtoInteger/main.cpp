#include <iostream>
#include<string>
#include<cstring>
#include <cmath>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        long max=pow(2,31)-1;
        long min=pow(2,31);
        if(str.length()==0)
            return  0;
        long long result=0;
        int i=0;
        while(str[i]==' '&&i<str.length())
        {
            i++;
        }
        if(i>=str.length())
            return 0;
        int flag=1;
        if(str[i]=='+') {
            flag = 1;
            i++;
        }
        else if(str[i]=='-') {
            flag = -1;
            i++;
        }
        else if(str[i]<'0'||str[i]>'9')
            return 0;
        for(i;i<str.length();i++)
        {
            if(str[i]<'0'||str[i]>'9')
                break;
            result=result*10+str[i]-'0';
            if(flag==1&&result>max)
                return  max;
            if(flag==-1&&result>min)
                return min;
        }
        return result*flag;
    }
};
int main() {
    string i;
    Solution s;
    while(true)
    {
        cin>>i;
        cout<<s.myAtoi(i)<<endl;
    }
    return 0;
}