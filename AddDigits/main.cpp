/***********************************************************************
 @Author: xuchong
 @Created Time : 四  9/26 01:19:31 2019
 @File Name: main.cpp
 @Description:
 ***********************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int result = num;
        if(num >= 10)
        {
            result = num % 9;
            if (result == 0)
                result = 9;
        }
        return result;
    }
};

int main()
{
    Solution so = Solution();
    cout<<so.addDigits(10)<<endl;
    return 0;
}

/*
 *
 *
 *  12: 1+2
 *  1234: 1+2+3+4 = 1
 *  12345: 15 = 6
 *  1234567899999999 =
 *  abcd:   1<=(a+b+c+d)<=36
 *
 *  1 1
 *  2 2
 *  9 9
 *  10 1
 *  11 2
 *  12 3
 *  ...
 *  18 9
 *  19 1
 *  20 2
 *  21 3
 *  ...
 *  27 9
 *  28 1
 *  29 2
 *  30 3
 *  31 4
 *  32 5
 *  33 6
 *  34 7
 *  35 8
 *  36 9
 *  37 1
 *  38 2
 *  39 3
 *  ...
 *
 *  ---
 *  80 8
 *  ...
 *  87 6
 *  88 7
 *  89 8
 *
 *  90 9
 *  99 9
 *  ------
 *  100 1   === 10
 *  101 2
 *
 *
 *
 * f(10) = f(1)
 *
 * f(100) = f(10)
 * f(110) = f(20)
 * ..
 * f(189) = f(99)
 *
 * f(190) =  (N-1)%9
 */

