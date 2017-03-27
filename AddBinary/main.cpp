#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution {
public:
	string addBinary(string a, string b) {
		string ar(a.rbegin(), a.rend());
		string br(b.rbegin(), b.rend());
		string cr;
		int i = 0;
		int d = 0;
		while (i < ar.length() && i < b.length())
		{
			cr += ((ar[i] + br[i] - '0' * 2+d) % 2 +'0');
			d = (ar[i] + br[i] - '0' * 2 + d) / 2;
			i++;
		}
		for (i; i < ar.length(); i++)
		{
			cr += ((ar[i] - '0' + d) % 2 + '0');
			d = (ar[i]  - '0'  + d) / 2;
		}
		for (i; i < br.length(); i++)
		{
			cr += ((br[i] - '0' + d) % 2 + '0');
			d = (br[i] - '0' + d) / 2;
		}
		if (d != 0)
			cr += "1";
		string dr(cr.rbegin(), cr.rend());
		return dr;
	}
};
int main()
{
	string a, b;
	Solution s;
	while (true)
	{
		cin >> a >> b;
		cout << s.addBinary(a, b) << endl;
	}
	return 0;
}