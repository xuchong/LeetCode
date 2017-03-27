#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0)
			return false;
		int n = matrix[0].size();
		if (n == 0)
			return false;
		int low, high, middle,tmp;
		low = 0;
		high = m - 1;
		while (low <= high)
		{
			middle = (low + high) / 2 ;
			if (matrix[middle][0] < target)
			{
				low = middle + 1;
			}
			else if (matrix[middle][0]>target)
			{
				high = middle -1;
			}
			else
			{
				return true;
			}
		}
		if (high < 0)
			return false;
		//high line
		tmp = high;
		low = 0;
		high = n - 1;
		while (low <= high)
		{
			middle = (low + high) / 2;
			if (matrix[tmp][middle] < target)
			{
				low = middle + 1;
			}
			else if (matrix[tmp][middle]>target)
			{
				high = middle - 1;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};
int main()
{

	return 0;
}
