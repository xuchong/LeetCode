/***********************************************************************
 @Author: xuchong
 @Created Time : 日  9/29 23:59:59 2019
 @File Name: main.cpp
 @Description:
 ***********************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if(num<=0)
            return false;

        while(num % 2 == 0)
            num = num / 2;
        while(num % 3 == 0)
            num = num / 3;
        while(num % 5 == 0)
            num = num / 5;
        if(num == 1)
            return true;
        return false;
    }
};

int main()
{
    Solution s = Solution();
    cout<<s.isUgly(8)<<endl;
    return 0;
}
