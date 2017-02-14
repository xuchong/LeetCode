#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int start = -1, end = -1;
		vector<int>result;
		if (nums.size() == 0)
		{
			result.push_back(start);
			result.push_back(end);
			return result;
		}
		int low, middle, high;
		if (nums[0] > target)
		{
			result.push_back(start);
			result.push_back(end);
			return result;
		}
		low = 0;
		if (nums[nums.size()-1] < target)
		{
			result.push_back(start);
			result.push_back(end);
			return result;
		}
		high = nums.size() - 1;
		//find start
		while (low <= high){
			middle = (low + high) / 2;
			if (nums[middle]>target)
				high = middle - 1;
			else if (nums[middle] < target)
				low = middle + 1;
			else{
				if (start == -1||middle<start){
					start = middle;
				}
				if (end == -1)
					end = middle;
				high = middle - 1;
			}
		}
		//find end
		if (end == -1)
		{
			result.push_back(start);
			result.push_back(end);
			return result;
		}
		low = end;
		high = nums.size() - 1;
		while (low <= high){
			middle = (low + high) / 2;
			if (nums[middle]>target)
				high = middle - 1;
			else if (nums[middle] < target)
				low = middle + 1;
			else{
				if (middle>end){
					end = middle;
				}
				low = low + 1;
			}
		}
		result.push_back(start);
		result.push_back(end);
		return result;
	}
};
int main()
{
	Solution s;
	vector<int> nums, result;
	int n, val, i;
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
		result = s.searchRange(nums, val);
		for (i = 0; i < result.size(); i++)
			cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}