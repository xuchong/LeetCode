/***********************************************************************
 @Author: xuchong
 @Created Time : 一  9/30 00:08:52 2019
 @File Name: main.cpp
 @Description:
 ***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> f(1690);
        f[0] = 1;
        // n < 1690
        int i=0, j=0, k=0;
        int ii, jj, kk;
        int a;
        for(a = 1; a<n ; a++)
        {
            ii = f[i] * 2;
            jj = f[j] * 3;
            kk = f[k] * 5;
            if(ii < jj and ii < kk) {
                f[a] = f[i] * 2;
                i++;
            }
            else if (jj < ii and jj < kk) {
                f[a] = f[j] * 3;
                j++;
            }
            else if(kk < ii and kk < jj){
                f[a] = f[k] * 5;
                k++;
            }else if(ii == jj and ii < kk){
                f[a] = f[i] * 2;
                i++;
                j++;
            }else if(ii == kk and ii < jj)
            {
                f[a] = f[i] * 2;
                i++;
                k++;
            }else if(jj == kk and jj < ii)
            {
                f[a] = f[j] * 3;
                j++;
                k++;
            }else
            {
                f[a] = f[j] * 3;
                i++;
                j++;
                k++;
            }
        }
        return f[n-1];
    }
};

int main()
{
    Solution ss = Solution();
    int i;
    for(i=1;i<20;i++)
        cout<<ss.nthUglyNumber(i)<<endl;
    return 0;
}

/*
 * 2 3 5
 * f()
 *
 * 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
 *
 * 2 0 1 0 0 2 1 1 2
 * 3 0 0 1 0 0 1 0 1
 * 5 0 0 0 1 0 0 1 0
 */