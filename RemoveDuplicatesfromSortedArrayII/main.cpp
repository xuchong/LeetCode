#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n == 0)
			return n;
		int shift=0;
		int count=1;
		int tmp=nums[0];
		for (int i = 1; i < n; i++)
		{
			if (nums[i] == nums[i - 1])
			{
				count++;
				if (count>2)
				{
					shift++;
				}
			}
			else
			{
				count = 1;
			}
			tmp = nums[i];
			nums[i - shift] = nums[i];
		}
		return (n - shift);
	}
};
// 6 1 1 1 2 2 3
int main()
{
	Solution s;
	vector<int>nums;
	int value;
	int n;
	while (true)
	{
		cin >> n;
		nums.clear();
		while (n--)
		{
			cin >> value;
			nums.push_back(value);
		}
		value = s.removeDuplicates(nums);
		cout << value << endl;
		for (int i = 0; i < value; i++)
		{
			cout << nums[i] << " ";
		}
		cout << endl;
	}
	return 0;
}