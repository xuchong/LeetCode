#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
	void makebuild(vector<vector<int>>&result, int h,int& index)
	{
		if (result.size() - 2 * h == 1)
		{
			result[h][h] = result.size()*result.size();
			index++;
			return;
		}
		int n = result.size();
		//one
		for (int i = h; i < n-h; i++)
		{
			result[h][i] = index;
			index++;
		}
		//two
		for (int i = h+1; i < n - h; i++)
		{
			result[i][n-h-1] = index;
			index++;
		}
		//three
		for (int i = n-h-2; i >= h; i--)
		{
			result[n-h-1][i] = index;
			index++;
		}
		//four
		for (int i = n-h-2; i > h; i--)
		{
			result[i][h] = index;
			index++;
		}
	}
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>result;
		if (n == 0)
			return result;
		for (int i = 0; i < n; i++)
		{
			vector<int> item(n, 0);
			result.push_back(item);
		}
		int index = 1;
		for (int i = 0; i < (n + 1) / 2; i++)
		{
			makebuild(result, i, index);
		}
		return result;
	}
};
int main()
{
	Solution s;
	int n;
	vector<vector<int>> matrix;
	while (true)
	{
		cin >> n;
		matrix = s.generateMatrix(n);
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix.size(); j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}