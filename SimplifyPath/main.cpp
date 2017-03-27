#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
	string simplifyPath(string path) {
		vector<char> stack;
		for (int i = 0; i < path.length(); i++)
		{
			if (path[i] == '/')
			{
				if (stack.size() == 0)
					stack.push_back(path[i]);
				else
				{
					if (stack[stack.size() - 1] == '/')
					{
						continue;
					}
					else if (stack[stack.size() - 1] == '.')
					{
						if (stack[stack.size() - 2] == '/'){
							stack.pop_back();
						}
						else
						{
							stack.push_back(path[i]);
						}
					}
					else
					{
						stack.push_back(path[i]);
					}
				}
			}
			else if (path[i] == '.')
			{
				if ((int)(stack.size()) - 2 >= 0 && stack[stack.size() - 2] == '/'&&stack[stack.size() - 1] == '.'&&((i + 1<path.length()&&path[i+1]=='/')||(i + 1==path.length())))
				{
					stack.pop_back();
					if ((int)(stack.size()) != 1){
						stack.pop_back();
						while (stack[stack.size() - 1] != '/')
						{
							stack.pop_back();
						}
					}
						
				}
				else
				{
					stack.push_back(path[i]);
				}
			}
			else{
				stack.push_back(path[i]);
			}
		}
		if (stack.size() > 1 && stack[stack.size() - 1] == '/')
			stack.pop_back();
		if (stack.size() > 1 && stack[stack.size() - 1] == '.'&&stack[stack.size() - 2] == '/')
		{
			if (stack.size() > 2){
				stack.pop_back();
				stack.pop_back();
			}
			else
			{
				stack.pop_back();
			}
		}
		string result;
		for (int i = 0; i < stack.size(); i++)
			result += stack[i];
		return result;
	}
};
int main()
{
	string path;
	Solution s;
	while (true)
	{
		cin >> path;
		cout << s.simplifyPath(path) << endl;
	}
	return 0;
}