#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
	void recursive(vector<vector<int>> &result, vector<int>nums, vector<int>flag, vector<int>item, int count)
	{
		if (count == nums.size())
		{
			result.push_back(item);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (flag[i] == 1)
			{
				if (i>0 && nums[i] == nums[i - 1]&&flag[i-1]==1)
					continue;
				flag[i] = -1;
				item.push_back(nums[i]);
				count++;
				recursive(result, nums, flag, item, count);
				flag[i] = 1;
				item.pop_back();
				count--;
			}
		}
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() == 0)
			return result;
		sort(nums.begin(), nums.end());
		vector<int> flag;
		for (int i = 0; i < nums.size(); i++)
		{
			flag.push_back(1);
		}
		vector<int> item;
		recursive(result, nums, flag, item, 0);
		return result;
	}
};
int main()
{
	Solution s;
	int n, val;
	vector<int>nums;
	vector<vector<int>> result;
	while (true)
	{
		cin >> n;
		nums.clear();
		while (n--)
		{
			cin >> val;
			nums.push_back(val);
		}
		result = s.permuteUnique(nums);
		for (int i = 0; i < result.size(); i++){
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}