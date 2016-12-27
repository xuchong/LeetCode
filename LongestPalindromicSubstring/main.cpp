#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#define Type DP

#ifdef Type
class Solution {
private:
    int d[1000][1000];
public:
	string longestPalindrome(string s) {
		int length=s.length();
        int i,j;
        for( i=0;i<length;i++)
        {
            for( j=0;j<length;j++)
            {
                d[i][j]=s[i]==s[j]?1:0;
            }
        }
        //次对角线，连续以主对角线对称，最长串即是
        int max=0;
        int count=0;
        int startindex=0;
        int base=length-1;
        for( i=length;i>0;i--) {
            //up
            count = 0;
            for ( j = 0; j < (1 + i) / 2; j++) {
                if (d[i / 2 + j][(i - 1) / 2 - j] == 1) {
                    count++;
                } else
                    break;
            }
            if(i%2==0)
                count*=2;
            else
                count=count*2-1;
            if (max < count) {
                max = count;
                startindex = (i - 1) / 2 - j + 1;
            }
            //down
            count =0;
            for ( j = 0; j < (1 + i) / 2; j++) {
                if (d[base-((i - 1) / 2 - j)][base-(i / 2 + j)] == 1) {
                    count++;
                } else
                    break;
            }
            if(i%2==0)
                count*=2;
            else
                count=count*2-1;
            if (max < count) {
                max = count;
                startindex = base-(i/2+j)+1;
            }
        }
        return s.substr(startindex,max);

	}
};

#endif
int main()
{
	string a;
    Solution s;
	while (true)
	{
		cin >> a;
        cout<<s.longestPalindrome(a)<<endl;
		
	}
}