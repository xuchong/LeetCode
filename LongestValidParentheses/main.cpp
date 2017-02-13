#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
//)( ( (((()())()())) ()( ())) (

//Option: 
//use: another stack! thinking thinking
//use DP!!

class Solution {
public:
	int longestValidParentheses(string s) {
		int result = 0;
		if (s.length() == 0)
			return result;
		vector<int> index;
		vector<char> deque;
		int j,flag;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				j = i;
				deque.clear();
				flag = 0;
				while (j < s.length() )
				{
					if (s[j] == '('){
						deque.push_back(s[j]);
					}
					else
					{
						if (deque.size()>0)
						{
							deque.pop_back();
							flag++;
							if (deque.size() == 0)
							{
								j++;
								break;
							}
						}
						else
						{
							break;
						}
					}
					j++;
 				}
				j--;
				if (deque.size() > 0)
				{
					j = i;
					int startLeft = 0;
					while (j<s.length() && s[j] == '(')
					{
						startLeft++;
						j++;
					}
					int k = startLeft-flag;
					if (k>0){
						i += k-1;
						while (k > 0)
						{
							index.push_back(0);
							k--;
						}
					}
					else
					{
						index.push_back(0);
					}
				}
				else
				{
					while (i <= j)
					{
						index.push_back(1);
						i++;
					}
					i--;
				}
			}
			else
			{
				index.push_back(0);
			}
		}
		int count = 0;
		for (int i = 0; i < index.size(); i++)
		{
			if (index[i] == 1)
			{
				count++;
			}
			else
			{
				if (count>result)
					result = count;
				count = 0;
			}
		}
		if (count > result)
			result = count;
		return result;	
	}
};
int main()
{
	Solution s;
	string str;
	while (true)
	{
		cin >> str;
		cout << s.longestValidParentheses(str) << endl;
	}
	return 0;
}
//)( ((((()())()()))()(())) (
//)(((((()())()()))()(()))(
//((((()())()()))()(()))