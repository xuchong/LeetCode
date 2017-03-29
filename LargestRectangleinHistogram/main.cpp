#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//good idea of stack
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty())
			return 0;
		stack<int> w;
		stack<int> newheight;
		heights.push_back(0);
		int max = 0, area;
		for (int i = 0; i < heights.size(); i++)
		{
			if (w.empty() || heights[i]>newheight.top()){
				w.push(1);
				newheight.push(heights[i]);
			}
			else
			{
				//merge 
				int width = 0;
				while (!w.empty() && heights[i] <= newheight.top())
				{
					width += w.top();
					area = (width)*newheight.top();
					if (area > max)
						max = area;
					w.pop();
					newheight.pop();
				}
				w.push(width+1);
				newheight.push(heights[i]);
			}
		}
		return max;
	}
};
// 6 4 2 0 3 2 5 
int main()
{
	Solution s;
	vector<int>height;
	int val, n;
	while (true)
	{
		cin >> n;
		height.clear();
		while (n--)
		{
			cin >> val;
			height.push_back(val);
		}
		cout << s.largestRectangleArea(height) << endl;
	}
	return 0;
}