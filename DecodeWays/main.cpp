#include<iostream>
#include<string>
using namespace std;
class Solution {
private:
	int a[10000];
public:
	int numDecodings(string s) {
		if (s.empty()||s[0]=='0')
			return 0;
		a[0] = 1;
		a[1] = 1;
		for (int i = 2; i <= s.length(); i++)
		{
			a[i] = 0;
			if (s[i - 1] != '0'){
				a[i] = a[i - 1];
				if (s[i - 2] - '0' == 1 || (s[i - 2] - '0' == 2 && s[i - 1] - '0' <= 6))
				{
					a[i] += a[i - 2];
				}
			}
			else
			{
				if (s[i - 2] - '0' == 1 || (s[i - 2] - '0' == 2 && s[i - 1] - '0' <= 6))
				{
					a[i] += a[i - 2];
				}
				else
				{
					return 0;
				}
			}
		}
		return a[s.length()];
	}
};
int main()
{

	return 0;
}