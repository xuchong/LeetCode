#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int max = INT_MIN;
		int left = 0;
		int start = 0;
		while (start < nums.size())
		{
			left += nums[start];
			if (left>max)
			{
				max = left;
			}
			if (left < 0)
			{
				left = 0;
			}
			start++;
		}
		return max;
	}
};
//9 -2 1 -3 4 -1 2 1 -5 4
int main()
{
	Solution s;
	vector<int> nums;
	int n, val;
	while (true)
	{
		cin >> n;
		nums.clear();
		while (n--)
		{
			cin >> val;
			nums.push_back(val);
		}
		cout << s.maxSubArray(nums) << endl;
	}
	return 0;
}