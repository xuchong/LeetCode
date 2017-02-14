#include<iostream>
#include<vector>
using namespace std;
class Solution {

public:
	int search(vector<int>& nums, int target) {
		int result = -1;
		if (nums.size() == 0)
			return result;
		int low, middle, high;
		low = 0;
		high = nums.size() - 1;
		int i=0;
		//biggest
		while (i < nums.size() - 1 && nums[i] < nums[i + 1])
		{
			i++;
		}
		if (nums[0] < target)
		{
			low = 0;
			if (target>nums[i])
				return result;
			else if (target == nums[i])
				return i;
			else
				high = i;
		}
		else if (nums[0] > target)
		{
			low = i + 1;
			if (low >= nums.size())
				return result;
			high = nums.size() - 1;
			if (nums[high] == target)
				return high;
		}
		else{
			return 0;
		}
		middle = (low + high) / 2;
		while (low < high)
		{
			middle = (low + high) / 2;
			if (target > nums[middle])
			{
				low = middle+1;
			}
			else if (target < nums[middle])
				high = middle-1;
			else
				return middle;
		}
		if (nums[low] != target&&nums[high] != target)
			return -1;
		else
			return low;
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
		cin >> val;
		cout << s.search(nums, val) << endl;
	}
	return 0;
}