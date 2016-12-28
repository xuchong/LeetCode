#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        long y=0;
        int _x=x;
        while(x!=0)
        {
            y=y*10+x%10;
            x/=10;
        }
        if(y==_x)
            return 1;
        else
            return 0;
    }
};
int main() {
    Solution s;
    int x;
    while(true)
    {
        cin>>x;
        cout<<s.isPalindrome(x)<<endl;
    }
    return 0;
}