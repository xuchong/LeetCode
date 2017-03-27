#include<iostream>
#include<string>
#include<cstring>
#include<deque>
#include<unordered_map>
using namespace std;
//int flag[30];
class Solution {
public:
	string minWindow(string s, string t) {
		//memset(flag, 0, sizeof(flag));
		int start;
		int total = 0;
		int i = 0;
		int a, b, min=INT_MAX;
		deque<int> index;
		unordered_map<int,int> tF;
		unordered_map<int, int> tF_b;
		for (int i = 0; i < t.length(); i++){
			tF.insert(make_pair<int, int>((int)t[i], 0));
			tF_b[t[i]]++;
		}
		while (i < s.length()&&total!=t.length())
		{
			if (tF.find(s[i])!=tF.end())
			{
				if (tF[s[i]] < tF_b[s[i]])
					total++;
				tF[s[i]]++;
				index.push_back(i);
			}
			i++;
		}
		if (total == t.length())
		{
			while (tF[s[index.front()]]>tF_b[s[index.front()]])
			{
				tF[s[index.front()]]--;
				index.pop_front();
			}
			if (min > (i - index.front()))
			{
				min = i - index.front();
				a = index.front();
				b = i;
			}
			while (i < s.length())
			{
				if (tF.find(s[i]) != tF.end())
				{
					index.push_back(i);
					tF[s[i]]++;
					while (tF[s[index.front()]]>tF_b[s[index.front()]])
					{
						tF[s[index.front()]]--;
						index.pop_front();
					}
					if (min > (i - index.front()+1))
					{
						min = i - index.front()+1;
						a = index.front();
						b = i+1;
					}
				}
				i++;
			}
			return s.substr(a, b - a);
		}
		else
		{
			return "";
		}
	}
};
int main()
{
	Solution ss;
	string s, t;
	while (true)
	{
		cin >> s >> t;
		cout << ss.minWindow(s, t) << endl;
	}
	return 0;
}