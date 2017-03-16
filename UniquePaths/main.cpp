#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePaths(int m, int n) {
		if (n==1||m == 1)
			return 1;
		vector<vector<int>> matrix;
		for (int i = 0; i < m; i++)
		{
			vector<int> item(n, 0);
			matrix.push_back(item);
		}
		for (int i = 0; i < n; i++)
		{
			matrix[0][i] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			matrix[i][0] = 1;
		}
		//after initial
		int h = 1;
		while (h < m&&h < n)
		{
			for (int i = h; i < n; i++)
			{
				matrix[h][i] = matrix[h - 1][i] + matrix[h][i - 1];
			}
			for (int i = h; i < m; i++)
			{
				matrix[i][h] = matrix[i - 1][h] + matrix[i][h - 1];
			}
			h++;
		}
		return matrix[m - 1][n - 1];
	}
};
int main()
{
	Solution s;
	int m, n;
	while (true)
	{
		cin >> m >> n;
		cout << s.uniquePaths(m, n) << endl;
	}
	return 0;
}