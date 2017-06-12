#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
#define TL_SO
#ifndef TL_SO
//time limited and stack overflow
class Solution {
private:
	bool check(string s1, string s2, string s3, vector<int>&s1_index,int n=-1)
	{
		if (n == s3.length())
			return true;
		//s1 not empty
		if (s1_index.size()<s1.length())
		{
			int start = s1_index.size();
			if (s1[start] == s3[n + 1])
			{
				s1_index.push_back(n + 1);
				n++;
			}
			else if (s2[n +1- start] == s3[n + 1])
			{
				n++;
			}
			else
			{
				//s1 and s2 not fine;  need back
				int flag = 0;
				while (s1_index.size() > 0){
					n = s1_index.back();
					s1_index.pop_back();
					if (s2[n - s1_index.size()] == s3[n])
					{
						n++;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					return false;
				}
			}
		}
		else
		{
			int start = s1_index.size();
			if (s2[n +1 - start] == s3[n + 1])
			{
				n++;
			}
			else
			{
				//s1 and s2 not fine;  need back
				int flag = 0;
				while (s1_index.size() > 0){
					n = s1_index.back();
					s1_index.pop_back();
					if (s2[n - s1_index.size()] == s3[n])
					{
						n++;
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					return false;
				}
			}
		}
		return check(s1, s2, s3, s1_index, n);
	}
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.empty())
			return s2 == s3;
		if (s2.empty())
			return s1 == s3;
		if (s1.length() + s2.length() != s3.length())
			return 0;
		vector<int> s1_index;
		int n = -1;
		return check(s1, s2, s3, s1_index, -1);
	}
};
#else
class Solution{
public:
	bool isInterleave(string s1, string s2, string s3)
	{
		if (s1.empty())
			return s2 == s3;
		if (s2.empty())
			return s1 == s3;
		if (s1.length() + s2.length() != s3.length())
			return 0;
		int dp[100][100] = { 0 };
		// init the dp
		dp[0][0] = 1;
		string tmp;
		for (int i = 1; i <= s1.length(); i++)
		{
			if (s1[i - 1] == s3[i - 1])
			{
				dp[i][0] = 1;
			}
			else{
				break;
			}
			
		}
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s2[j - 1] == s3[j - 1])
				dp[0][j] = 1;
			else
				break;
		}
		for (int i = 1; i <= s1.length(); i++)
		{
			for (int j = 1; j <= s2.length(); j++)
			{
				if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] == 1)
				{
					dp[i][j] = 1;
				}
				if (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1] == 1)
				{
					dp[i][j] = 1;
				}
			}
		}
		if (dp[s1.length()][s2.length()] == 1)
			return true;
		else
			return false;
	}
};
#endif

int main()
{
	Solution s;
	string s1, s2, s3;
	while (true)
	{
		cin >> s1 >> s2 >> s3;
		cout << s.isInterleave(s1, s2, s3) << endl;
	}
	return 0;
}