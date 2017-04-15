#include<iostream>

using namespace std;
int a[10000];
class Solution {
public:
	int numTrees(int n) {
		a[0] = 1;
		a[1] = 1;
		int i, j;
		for (i = 2; i <= n; i++)
		{
			a[i] = 0;
			for (j = 0; j < i; j++)
			{
				a[i] += a[j] * a[i - 1 - j];
			}
		}
		return a[n];
	}
};
int main()
{
	Solution s;
	int n;
	while (true)
	{
		cin >> n;
		cout << s.numTrees(n) << endl;
	}
	return 0;
}