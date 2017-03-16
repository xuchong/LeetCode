#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<sstream>
using namespace std;
class Solution {
private:
	//return first number
	int getIndex(vector<int>& index, int& k,int n)
	{
		int i = 1;
		int t = 1;
		if (n == 1)
		{
			t = 0;
			for (i = 0; i < index.size(); i++)
			{
				if (index[i] == 1)
				{
					t++;
				}
				if (t == k)
				{
					index[i] = -1;
					return (i+1);
				}
			}
		}
		for ( i = 1; i < n; i++)
		{
			t *= i;
		}
		int result = (k+t-1)/ t;
		int count = 0;
		for (i = 0; i < index.size(); i++)
		{
			if (index[i] == 1)
				count++;
			if (count == result)
			{
				index[i] = -1;
				k = k - (result-1)* t ;
				return (i+1);
			}
		}
		return result;
	}
public:
	string getPermutation(int n, int k) {
		vector<int> index(n, 1);
		string result;
		stringstream ss;
		int a;
		for (int i = n; i > 0; i--)
		{
			a=getIndex(index, k, i);
			ss.str("");
			ss << a;
			result.append(ss.str());
		}
		return result;
	}
};
int main()
{
	Solution s;
	int n, k;
	while (true)
	{
		cin >> n >> k;
		cout << s.getPermutation(n, k) << endl;
	}
	return 0;
}