#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int>result;
		if (digits.size() == 0)
			return result;
		int d = 0;
		int n = digits.size();
		digits[n - 1] += 1;
		for (int i = n-1; i >= 0; i--)
		{
			digits[i] += d;
			d = (digits[i]) / 10;
			if (d == 0)
				break;
			digits[i] %= 10;
		}
		if (d == 0)
			return digits;
		else
		{
			result.push_back(d);
			for (int i = 1; i <= n; i++)
				result.push_back(digits[i - 1]);
			return result;
		}
	}
};
enum Valuse{a,b=5,c,d=3,e};
enum Valuse va = Valuse::a;
enum Valuse vb = Valuse::b;
enum Valuse vc = Valuse::c;
enum Valuse vd = Valuse::d;
enum Valuse ve = Valuse::e;
int main()
{
	Solution s;
	int n, val;
	vector<int>digits,result;
	while (true)
	{
		cin >> n;
		digits.clear();
		while (n--)
		{
			cin >> val;
			digits.push_back(val);
		}
		result = s.plusOne(digits);
		for (int i = 0; i < result.size(); i++)
			cout << result[i];
		cout << endl;
	}
	return 0;
}