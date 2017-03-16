#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int sum = 0;
		if (m == 1)
		{
			for (int i = 0; i < n; i++)
			{
				sum += grid[0][i];
			}
			return sum;
		}
		if (n == 1)
		{
			for (int i = 0; i < m; i++)
			{
				sum += grid[i][0];
			}
			return sum;
		}
		//modify
		vector<vector<int>> matrix;
		for (int i = 0; i < m; i++)
		{
			vector<int> item(n, 0);
			matrix.push_back(item);
		}
		matrix[0][0] = grid[0][0];
		for (int i = 1; i < n; i++)
		{
			matrix[0][i] = grid[0][i] + matrix[0][i-1];
		}
		for (int i = 1; i < m; i++)
		{
			matrix[i][0] = grid[i][0] + matrix[i-1][0];
		}
		//after initial
		int h = 1;
		int min;
		while (h < m&&h < n)
		{
			for (int i = h; i < n; i++)
			{
				min = matrix[h - 1][i];
				if (min>matrix[h][i - 1])
					min = matrix[h][i - 1];
				matrix[h][i] = min + grid[h][i];
			}
			for (int i = h; i < m; i++)
			{
				min = matrix[i - 1][h];
				if (min>matrix[i][h - 1])
					min = matrix[i][h - 1];
				matrix[i][h] = min + grid[i][h];
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
		// waiting ?
	}
	return 0;
}