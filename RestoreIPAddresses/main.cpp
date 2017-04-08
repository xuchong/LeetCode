#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
private:
	int convertStr2Int(string str)
	{
		if (str[0] == '0'&&str.length() > 1)
			return 256;
		stringstream ss;
		ss.str(str);
		int r;
		ss >> r;
		return r;
	}
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.length() < 4)
			return result;
		vector<int> fourPosition(3);
		fourPosition[0] = 1;
		fourPosition[1] = 2;
		fourPosition[2] = 3;
		while (fourPosition[0] < 4 && convertStr2Int(s.substr(0, fourPosition[0])) <= 255 )
		{
			if (convertStr2Int(s.substr(fourPosition[0],fourPosition[1]-fourPosition[0])) > 255)
			{
				fourPosition[0] ++;
				fourPosition[1] = fourPosition[0] + 1;
				fourPosition[2] = fourPosition[1] + 1;
				continue;
			}
			if (fourPosition[1] >= s.length())
			{
				fourPosition[0] ++;
				fourPosition[1] = fourPosition[0] + 1;
				continue;
			}
			if (convertStr2Int(s.substr(fourPosition[1], fourPosition[2] - fourPosition[1])) > 255)
			{
				fourPosition[1] ++;
				fourPosition[2] = fourPosition[1] + 1;
				continue;
			}
			if (fourPosition[2] >= s.length())
			{
				fourPosition[1] ++;
				fourPosition[2] = fourPosition[1] + 1;
				continue;
			}
			if (convertStr2Int(s.substr(fourPosition[2], s.length() - fourPosition[2])) > 255)
			{
				fourPosition[2] ++;
				continue;
			}
			// all is ok
			string item = s;
			item.insert(fourPosition[2], ".");
			item = item.insert(fourPosition[1], ".");
			item = item.insert(fourPosition[0], ".");
			result.push_back(item);
			fourPosition[2] ++;
		}
		return result;
	}
};
int main()
{	
	Solution s;
	string input;
	while (true)
	{
		cin >> input;
		s.restoreIpAddresses(input);
	}
	return 0;
}