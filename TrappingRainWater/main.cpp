#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() == 0)
			return 0;
		int i, j, max=-1;
		int leftmax, rightmax;
		int leftCount=0,middleCount=0, rightCount=0;
		for (i = 0; i < height.size(); i++)
		{
			if (height[i]>max){
				max = height[i];
				rightmax=leftmax = i;
			}
			else if (height[i] == max)
			{
				rightmax = i;
			}
		}
		max = height[0];
		j = 0;
		for (i = 1; i <= leftmax; i++)
		{
			if (height[i] >= max)
			{
				leftCount += max*(i - j-1);
				max = height[i];
				j = i;
			}
			else
			{
				leftCount -= height[i];
			}

		}
		max = height[leftmax];
		middleCount = ((rightmax - leftmax - 1)<0 ? 0 : (rightmax - leftmax - 1))*max;
		for (i = leftmax+1; i < rightmax; i++)
		{
			middleCount -= height[i];
		}
		max = height[height.size()-1];
		j = height.size() - 1;
		for (i = height.size() - 2; i >= rightmax; i--)
		{
			if (height[i] >= max)
			{
				leftCount += max*(j - i - 1);
				max = height[i];
				j = i;
			}
			else
			{
				rightCount -= height[i];
			}

		}
		return leftCount + middleCount + rightCount;
	}
};
//12 0 1 0 2 1 0 1 3 2 1 2 1
int main()
{
	Solution s;
	vector<int> nums;
	int val, n;
	while (true)
	{
		cin >> n;
		nums.clear();
		while (n--)
		{
			cin >> val;
			nums.push_back(val);
		}
		cout << s.trap(nums) << endl;
	}
	return 0;
}