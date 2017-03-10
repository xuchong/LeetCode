#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        int flag=1;
        if(n<0)
            flag=-1;
        long new_n=long(n)*flag;
        double part=1;
        while(new_n>1)
        {
            if(new_n%2==0)
            {
                new_n/=2;
                x*=x;
            }else
            {
                new_n/=2;
                part*=x;
                x*=x;
            }
        }
        x*=part;
        if(flag==-1)
            x=1/x;
        return x;
    }
};
int main() {
    Solution s;
    double x;
    int n;
    while (true)
    {
        cin>>x>>n;
        cout<<s.myPow(x,n)<<endl;
    }
    return 0;
}