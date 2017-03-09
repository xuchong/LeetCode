#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() < 2)
			return;
		int a, b, c, d;
		for (int i = 0; i < matrix.size()/2; i++)
		{
			for (int j = i; j < matrix.size()-i-1; j++)
			{
				a = matrix[i][j];
				d = matrix[j][matrix.size() - 1 - i];
				c = matrix[matrix.size() - 1 - i][matrix.size() - 1 - j];
				b = matrix[matrix.size() - 1 - j][i];
				//a->d->c->b->a
				matrix[matrix.size() - 1 - j][i] = c;
				matrix[matrix.size() - 1 - i][matrix.size() - 1 - j] = d;
				matrix[j][matrix.size() - 1 - i] = a;
				matrix[i][j] = b;
			}
		}
		
	}
};
int main()
{
	return 0;
}