#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
	void sort(vector<int>& nums, int  begin, int end)
	{
		if (begin >= end)
			return;
		int key = nums[begin];
		int low = begin, high = end;
		while (low < high)
		{
			while (low < high&&nums[high] >= key)
			{
				high--;
			}
			nums[low] = nums[high];
			while (low < high&&nums[low] <= key)
			{
				low++;
			}
			nums[high] = nums[low];
		}
		nums[low] = key;
		sort(nums, begin, low - 1);
		sort(nums, low + 1, end);
	}
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() == 0)
			return;
		sort(nums, 0, nums.size() - 1);
	}
};
int main()
{

	return 0;
}