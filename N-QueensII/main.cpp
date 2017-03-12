#include<iostream>
#include<vector>
using namespace std;
//backtracking
class Solution {
private:
	bool checkifCan(vector<int>&matrix, int index)
	{
		int i;
		matrix[index]++;
		int n = matrix.size();
		while (matrix[index] < n)
		{
			for (i = 0; i < index; i++)
			{
				if (matrix[i] == matrix[index] || matrix[i] - matrix[index] == i - index || matrix[i] - matrix[index] == index - i)
				{
					break;
				}
			}
			if (i == index)
			{
				return true;
			}
			matrix[index]++;
		}
		matrix[index] = -1;
		return false;
	}
public:
	int totalNQueens(int n) {
		if (n <= 0)
			return 0;
		vector<int>matrix(n, -1);
		int totalcount = 0;
		for (int i = 0; i < n; i++)
		{
			if (!checkifCan(matrix, i))
			{
				if (i == 0)
					break;
				i = i - 2;
			}
			else if (i == n - 1)
			{
				totalcount++;
				i--;
			}
		}
		return totalcount;
	}
};
int main()
{
	Solution s;
	int n;
	while (true)
	{
		cin >> n;
		cout << s.totalNQueens(n) << endl;
	}
	return 0;
}