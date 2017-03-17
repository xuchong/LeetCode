#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		int n = words.size();
		vector<string> result;
		if (n == 0){
			string space(maxWidth, ' ');
			result.push_back(space);
			return result;
		}
		int i;
		int count ;
		int start;
		for (i = 0; i < n; i++)
		{
			//each line
			start = i;
			count = words[i].length();
			while (count < maxWidth){
				i++;
				if (i == n)
					break;
				count += words[i].length()+1;
			}
			if (count == maxWidth)
			{
				string item;
				for (start; start < i; start++)
				{
					item.append(words[start]+ " ");
				}
				item.append(words[start]);
				result.push_back(item);
			}
			else if (count > maxWidth)
			{
				string item;
				int r = maxWidth-(count-words[i].length()-1);//¶àÓàµÄ¿Õ¸ñ
				if (((i - 1) - start) != 0){

					int divide = r / ((i - 1) - start);
					r = r % ((i - 1) - start);
					string space(divide + 1, ' ');
					for (start; start < i - 1; start++)
					{
						item.append(words[start] + space);
						if (r)
						{
							item.append(" ");
							r--;
						}

					}
					item.append(words[start]);
					result.push_back(item);
				}
				else
				{
					string space(r, ' ');
					item.append(words[start] + space);
					result.push_back(item);
				}
				//back one
				i--;
			}
			//last one line
			else
			{
				string item;
				for (start; start < i-1; start++)
				{
					item.append(words[start] + " ");
				}
				string space(maxWidth - count, ' ');
				item.append(words[start]+space);
				result.push_back(item);
			}

		}
		return result;
	}
};
int main()
{
	vector<string> words;
	int max;
	int n;
	string item;
	Solution s;
	while (true)
	{
		cin >> n;
		words.clear();
		while (n--)
		{
			cin >> item;
			words.push_back(item);
		}
		cin >> max;
		words = s.fullJustify(words, max);
		for (int i = 0; i < words.size(); i++)
			cout << words[i] << endl;
	}
	return 0;
}