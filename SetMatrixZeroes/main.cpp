#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		set<int> rows, cols;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					rows.insert(i);
					cols.insert(j);
				}
			}
		}
		set<int>::iterator it;
		for (it = rows.begin(); it != rows.end();it++)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[*it][j] = 0;
			}
		}
		for (it = cols.begin(); it != cols.end(); it++)
		{
			for (int j = 0; j < m; j++)
			{
				matrix[j][*it] = 0;
			}
		}
	}
};
int main()
{
	set<int> a;
	a.insert(2);
	a.insert(2);
	return 0;
}