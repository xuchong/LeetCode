#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
private:
	void recursive(vector<vector<int>>&result, vector<int> item, unordered_map<int, int> keys, vector<int> nums, int n,int countOfCurrent)
	{
		if (n > nums.size())
		{
			result.push_back(item);
			return;
		}
		if (n > 1 && nums[n - 1] == nums[n - 2])
			countOfCurrent++;
		else
			countOfCurrent = 1;
		//no add
		recursive(result, item, keys, nums, n + 1, countOfCurrent);
		//add
		keys[nums[n - 1]]++;
		if (countOfCurrent == keys[nums[n - 1]])
		{
			item.push_back(nums[n - 1]);
			recursive(result, item, keys, nums, n + 1, countOfCurrent);
		}
	}
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() == 0)
			return result;
		vector<int> item;
		unordered_map<int, int> keys;
		sort(nums.begin(), nums.end());
		recursive(result, item, keys, nums, 1, 1);
		return result;
	}
};
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
		s.subsetsWithDup(nums);
	}
	return 0;
}