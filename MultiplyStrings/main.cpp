#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution {
public:
	string add(string result,string input,int order)
	{
		string output = "";
		if (result.length() == 0)
			return input;
		output = result.substr(result.size() - order, order);
		int c, d=0;
		int j = 0;
		for (int i = 0; i < input.size(); i++)
		{
			j = (result.size() - 1 - i - order);
			if ( j>= 0)
				c = input[input.size() - 1 - i] - '0' + result[result.size() - 1 - i - order] - '0'+d;
			else
				c = input[input.size() - 1 - i]-'0'+d;
			d = c / 10;
			c = c % 10;
			output = (char)(c + '0') + output;
		}
		if (d > 0)
		{
			output = (char)(d + '0') + output;
		}
		return output;
	}
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";
		int a, b, c,d, i, j;
		string result = "";
		string tmp;
		int start = 0;
		for (i = num1.length() - 1; i >= 0; i--)
		{
			tmp = "";
			d = 0;
			for (j = num2.length() - 1; j >= 0; j--)
			{
				c = (num1[i] - '0') *(num2[j] - '0')+d;
				d = c / 10;
				c %= 10;
				tmp = (char)(c + '0') + tmp;
			}
			if (d > 0)
			{
				tmp = (char)(d+'0') + tmp;
			}
			result = add(result, tmp, start);
			start++;
		}
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
		cout << s.multiply(a, b) << endl;
	}
	return 0;
}