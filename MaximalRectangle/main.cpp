#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
private:
	int lagerestRect(vector<int> height, int maxArea)
	{
		if (height.size() == 0)
			return maxArea;
		stack<int> index;
		height.push_back(0);
		//lagerest rectangle in histogram
		for (int i = 0; i < height.size(); i++)
		{
			if (index.empty() || height[index.top()] < height[i])
				index.push(i);
			else
			{
				int h = height[index.top()];
				index.pop();
				maxArea = max(maxArea, h*(index.empty() ? i : i - index.top() - 1));
				i--;
			}
		}
		return maxArea;
	}
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		if (n == 0)
			return 0;
		vector<vector<int>> heights;
		vector<int> itemHeight;
		for (int i = 0; i < n; i++)
		{
			if (matrix[0][i] == '1')
				itemHeight.push_back(1);
			else
				itemHeight.push_back(0);
		}
		heights.push_back(itemHeight);
		for (int i = 1; i < m; i++)
		{
			itemHeight.clear();
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '1')
				{
					itemHeight.push_back(heights[i - 1][j]+1);
				}
				else
				{
					itemHeight.push_back(0);
				}
			}
			heights.push_back(itemHeight);
		}
		//get all
		int max = 0;
		for (int i = 0; i < heights.size(); i++)
		{
			max = lagerestRect(heights[i], max);
		}
		return max;
	}
};
// 4 5  1 0 1 0 0 1 0 1 1 1 1 1 1 1 1 1 0 0 1 0 
int main()
{
	Solution s;
	vector<vector<char>> matrix;
	char a;
	int m, n;
	while (true)
	{
		matrix.clear();
		cin >> m >> n;
		for (int i = 0; i < m; i++)
		{
			vector<char>item;
			for (int j = 0; j < n; j++)
			{
				cin >> a;
				item.push_back(a);
			}
			matrix.push_back(item);
		}
		cout << s.maximalRectangle(matrix) << endl;
	}
	return 0;
}