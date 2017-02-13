#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (s.length() == 0||words.size()==0)
			return result;
		unordered_map<string, int> words_index;
		for (int i = 0; i < words.size(); i++)
		{
			if (words_index.find(words[i]) == words_index.end())
			{
				words_index[words[i]] = 1;
			}
			else
			{
				words_index[words[i]]++;
			}
		}
		int wordlength = words[0].length();
		int strlength = s.length();
		int wordslength = wordlength*words.size();
		int length = strlength - wordslength;
		int j,count;
		string tmp;
		unordered_map<string, int>::iterator index;
		for (int i = 0; i <= length; i++)
		{
			unordered_map<string, int> words_index_bak(words_index);
			j = i;
			count = 0;
			while (j < strlength - wordlength+1&&count<words.size())
			{
				tmp = s.substr(j, wordlength);
				index = words_index_bak.find(tmp);
				if (index != words_index_bak.end() && index->second>0)
				{
					index->second--;
					count++;
				}
				else
				{
					break;
				}
				j += wordlength;
			}
			if (count == words.size())
				result.push_back(i);
		}
		return result;
	}
};
int main()
{
	Solution s;
	string str, tmp;
	vector<string> words;
	vector<int> result;
	int n;
	while (true)
	{
		cin >> str;
		cin >> n;
		words.clear();
		while (n--)
		{
			cin >> tmp;
			words.push_back(tmp);
		}
		result = s.findSubstring(str, words);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " ";
		}
		cout << endl;
	}
	return 0;
}