#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
	bool backTracking( string s, string p,int sindex,int pindex)
	{
		int i;
		if (sindex == s.length())
		{
			if (pindex == p.length())
				return true;
			else
			{
				while (p[pindex] == '*'&&pindex < p.length())
					pindex++;
				if (pindex == p.length())
					return true;
				else
					return false;
			}
		}
		if (pindex == p.length() && sindex != s.length())
			return false;

		
		if (p[pindex] == '?')
		{
			//index[pindex] = sindex;
			return backTracking(s, p, sindex + 1, pindex + 1);
		}
		else if (p[pindex] == '*')
		{
			i = 0;
			i+=backTracking(s, p, sindex, pindex+1);
			for (sindex = sindex+1; sindex <= s.length(); sindex++)
			{
				if (i > 0)
					break;
				i+=backTracking( s, p, sindex, pindex);
				i+=backTracking(s, p, sindex, pindex + 1);
			}
			return i;
		}
		else
		{
			if (s[sindex] == p[pindex])
			{
				return backTracking( s, p, sindex+1, pindex + 1);
			}
			else
			return false;
		}

	}
	bool isMatch(string s, string p) {
		int i;
		vector<int> index2s;
		if (s.empty())
		{
			if (p.empty())
				return true;
			else{
				i = 0;
				while (p[i] == '*'&&i<p.length())
				{
					i++;
				}
				if (i == p.length())
					return true;
				else
					return false;
			}	
		}
		if (p.empty()&&!s.empty())
		{
			return false;
		}
		//s , p string not empty then:  consider this condition ,*****
		i = 1;
		int count = 0;
		while (i < p.length())
		{
			if (p[i] == p[i - 1] && p[i] == '*')
				count++;
			else
				p[i - count] = p[i];
			i++;
		}
		p = p.substr(0, p.length() - count);
		return backTracking(s,p,0,0);
	}
};
int main()
{
	Solution ss;
	string s = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab", p = "***bba**a*bbba**aab**b";
	while (true)
	{
		cout << ss.isMatch(s, p) << endl;
		cin >> s;
		cin >> p;
	}
	return 0;
}