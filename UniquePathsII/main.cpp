#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (m == 1)
		{
			for (int i = 0; i < n; i++)
			{
				if (obstacleGrid[0][i] == 1)
					return 0;
			}
			return 1;
		}
		if (n == 1)
		{
			for (int i = 0; i < m; i++)
			{
				if (obstacleGrid[i][0] == 1)
					return 0;
			}
			return 1;
		}
		vector<vector<int>> matrix;
		for (int i = 0; i < m; i++)
		{
			vector<int> item(n, 0);
			matrix.push_back(item);
		}
		for (int i = 0; i < n; i++)
		{
			if (obstacleGrid[0][i] == 1)
				break;
			matrix[0][i] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			if (obstacleGrid[i][0] == 1)
				break;
			matrix[i][0] = 1;
		}
		//after initial
		int h = 1;
		while (h < m&&h < n)
		{
			for (int i = h; i < n; i++)
			{
				if (obstacleGrid[h][i] == 1)
					continue;
				matrix[h][i] = matrix[h - 1][i] + matrix[h][i - 1];
			}
			for (int i = h; i < m; i++)
			{
				if (obstacleGrid[i][h] == 1)
					continue;
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
		// waiting ?
	}
	return 0;
}