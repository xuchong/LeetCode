#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.length() == 0)
			return 0;
		int result = 0;
		int i;
		for ( i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] != ' ')
				break;
		}
		if (i == -1)
			return 0;
		for (i; i >= 0; i--)
		{
			if (s[i] != ' ')
				result++;
			else
				break;
		}
		return result;
	}
};
int main()
{
	Solution s;
	string str;
	while (true)
	{
		cin >> str;
		cout << s.lengthOfLastWord(str) << endl;
	}
	return 0;
}