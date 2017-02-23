#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 4 2 3 6 7 7
class Solution {
private:
	void recursive(vector<vector<int>>&result, vector<int>candidates, vector<int> item, int start, int target)
	{
		if (target == 0)
		{
			result.push_back(item);
			return;
		}
		else if (target > 0&&start<candidates.size())
		{
			recursive(result, candidates, item, start + 1, target);
			for (int i = 1; target - i*candidates[start] >= 0; i++)
			{
				item.push_back(candidates[start]);
				recursive(result, candidates, item, start + 1, target - i*candidates[start]);
			}
		}
	}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size()==0)
            return result;
        sort(candidates.begin(),candidates.end());
        vector<int> item;
		recursive(result, candidates, item, 0, target); 
		return result;
    }
};
int main() {
	Solution s;
	vector<int>candidates;
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
		result = s.combinationSum(candidates, val);
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