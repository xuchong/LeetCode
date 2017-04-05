#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
private:
	vector<int> recursive(int n, int m)
	{
		
		if (m == 1)
		{
			vector<int> result;
			result.push_back(0);
			result.push_back(1);
			return result;
		}
		vector<int> sub = recursive(n, m - 1);
		vector<int> result(sub);
		for (int i = sub.size() - 1; i >= 0;i--)
		{
			sub[i]= pow(2, m-1) + sub[i];
			result.push_back(sub[i]);
		}
		return result;
	}
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		if (n == 0){
			result.push_back(0);
			return result;
		}
		return recursive(n, n);
	}
};
int main()
{
	return 0;
}