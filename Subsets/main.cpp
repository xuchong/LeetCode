#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
	void recursive(vector<vector<int>>& result, vector<int> item, vector<int> nums, int current)
	{
		if (current == nums.size())
		{
			result.push_back(item);
			return;
		}
		recursive(result, item, nums, current + 1);
		item.push_back(nums[current]);
		recursive(result, item, nums, current + 1);
	}
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> item;
		recursive(result, item, nums, 0);
		return result;
	}
};
int main()
{

	return 0;
}