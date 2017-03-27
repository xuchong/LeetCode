#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[1000][1000];
class Solution {
private:
	
	//int state[10000][10000];//0 init, 1 word1, 2 word2, 3
public:
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		int i, j;
		for (i = 0; i <= m; i++)
			dp[i][0] = i;
		for (i = 0; i <= n; i++)
			dp[0][i] = i;
		//state[0][0] = 0;
		int minv;
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (word1[i - 1] == word2[j - 1]){
						dp[i][j] =dp[i-1][j - 1] ;
				}
				else{
					minv = min(dp[i][j - 1], dp[i - 1][j]);
					if (minv > dp[i - 1][j - 1])
						minv = dp[i - 1][j - 1];
					dp[i][j] = minv + 1;
				}
			}
		}
		int result = dp[m][n];
		return result;
	}
};
int main()
{
	Solution s;
	string a, b;
	while (true)
	{
		cin >> a >> b;
		cout << s.minDistance(a, b) << endl;
	}
	return 0;
}