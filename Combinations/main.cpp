#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
	void recursive(vector<vector<int>>&result,vector<int> item,int n,int k,int count,int current)
	{
		if (count == k)
		{
			result.push_back(item);
			return;
		}
		if (current > n)
			return;
		//not enough
		if (count + n - current + 1 < k)
			return;
		recursive(result, item, n, k, count, current + 1);
		item.push_back(current);
		recursive(result, item, n, k, count+1, current + 1);
	}
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> item;
		recursive(result, item, n, k, 0, 1);
		return result;
	}
};
int main()
{
	Solution s;
	int n, k;
	while (true)
	{
		cin >> n >> k;
		s.combine(n, k);
	}
	return 0;
}