#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	void recursive(vector<vector<int>>&result, vector<int> candidates, vector<int> item, int start, int target)
	{
		if (target == 0)
			result.push_back(item);
		else if(target > 0 && start < candidates.size())
		{
			recursive(result, candidates, item, start + 1, target);
			item.push_back(candidates[start]);
			recursive(result, candidates, item, start + 1, target - candidates[start]);
		}
	}
	bool static compare(const vector<int>& a, const vector<int>& b)
	{
		int i = 0;
		while (i < a.size() && i < b.size())
		{
			if (a[i] < b[i])
				return true;
			else if (a[i] == b[i])
				i++;
			else
				return false;
		}
		if (i < a.size() && i == b.size())
			return false;
		else if (i < b.size() && i == a.size())
			return true;
		else
			return false;
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result, result_final;
		if (candidates.size()==0)
			return result;
		sort(candidates.begin(), candidates.end());
		vector<int> item;
		recursive(result, candidates, item, 0, target);
		sort(result.begin(), result.end(), compare);

		if (result.size() > 0){
			item = result[0];
			result_final.push_back(item);
		}
		int j;
		for (int i = 1; i < result.size(); i++)
		{
			if (item.size() == result[i].size())
			{
				for ( j= 0; j < result[i].size(); j++)
				{
					if (item[j] != result[i][j])
						break;
				}
				if (j != result[i].size())
				{
					result_final.push_back(result[i]);
					item = result[i];
				}
			}
			else
			{
				result_final.push_back(result[i]);
				item = result[i];
			}
		}
		return result_final;
	}
};
//7 10 1 2 7 6 1 5 8
int main()
{
	Solution s;
	vector<int> candidates;
	vector<vector<int>> result;
	int n, val;
	while (true)
	{
		cin >> n;
		candidates.clear();
		while (n--)
		{
			cin >> val;
			candidates.push_back(val);
		}
		cin >> val;
		result = s.combinationSum2(candidates, val);
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
	}
}