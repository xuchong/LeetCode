#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
set<string> dp[1000][1000];
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)
			return true;
		int n = s1.length();
		int i, j;
		int shift = 0;
		set<string> leftitem,rightitem;
		int  left, right;
		string tmp;
		for (i = 0; i < n ; i++)
		{
			dp[i][i].insert(tmp+(s1[i]));
		}
		for (shift=1; shift < n; shift++){
			for (i = 0; i < n - shift; i++)
			{
				for (int k = i; k < i + shift; k++){
					leftitem = dp[i][k];
					rightitem = dp[k + 1][i + shift];
					left = leftitem.size();
					right = rightitem.size();
					for (set<string>::iterator s = leftitem.begin(); s != leftitem.end(); s++)
					{
						for (set<string>::iterator t = rightitem.begin(); t != rightitem.end(); t++)
						{
							if (s2.find(*s + *t) !=string::npos)
							{
								dp[i][i + shift].insert(*s + *t);
							}
							else if (s2.find(*t + *s) != string::npos)
							{
								dp[i][i + shift].insert(*t + *s);
							}
						}
					}
				}
			}
		}
		if (dp[0][n - 1].find(s2) != dp[0][n - 1].end())
			return true;
		return false;
	}
};
int main()
{
	Solution s;
	string s1, s2;
	while (true)
	{
		cin >> s1 >> s2;
		cout << s.isScramble(s1, s2) << endl;
	}
	return 0;
}