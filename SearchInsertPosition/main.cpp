#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int result = 0;
		if (nums.size() == 0)
			return result;
		int low = 0, middle, high = nums.size() - 1;
		while (low < high)
		{
			middle = (low + high) / 2;
			if (nums[middle]>target)
				high = middle - 1;
			else if (nums[middle] < target)
				low = middle + 1;
			else
				return middle;
		}
		if (nums[low] < target)
			low++;
		return low;
	}
};
int main()
{
	Solution s;
	vector<int>nums;
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
		cin >> val;
		cout << s.searchInsert(nums, val) << endl;
	}
}