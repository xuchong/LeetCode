#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int length=0;
        //int y=x;
        long long xx=0;
        if(x==0)
            return x;
        while(x%10==0)
            x/=10;
        while(x!=0)
        {
            xx=xx*10+x%10;
            x/=10;
        }
        if(xx>pow(2,31)-1||xx<1-pow(2,31))
            return 0;
        return xx;
    }
};
int main() {
    Solution s;
    int i;
    int x=-2147483648;
    cout<<x<<endl;
    long long y=-9147483649;
    cout<<y<<endl;
    while(true)
    {
        cin>>i;
        cout<<s.reverse(i)<<endl;
    }
    return 0;
}