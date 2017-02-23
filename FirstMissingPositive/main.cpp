#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0)
			return 1;
		int tmp;
		int i;
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i]>nums.size()||nums[i]<=0)
				nums[i] = -1;
			else{
				
				if (nums[i] - 1 == i)
					continue;
				tmp = nums[nums[i] - 1];
				if (tmp == nums[i])
					  
				nums[nums[i] - 1] = nums[i];
				nums[i] = tmp;
				i--;
			}
		}
		for (i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= 0)
				return i + 1;
		}
		return i + 1;
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
		cout << s.firstMissingPositive(nums) << endl;
	}
	return 0;
}