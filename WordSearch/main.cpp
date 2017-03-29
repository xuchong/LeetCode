#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<unordered_map>
using namespace std;
#define TL
#ifndef TL
class Solution {
private:
	bool check(vector<vector<char>> board, vector<vector<char>> _copy, unordered_map<char, vector<vector<int>>> _canbe, vector<vector<int>> _path,string word,int start)
	{
		vector<vector<int>> total;
		vector<int> tmp;
		int i, j;
		int n = board[0].size();
		int m = board.size();
		if (start >= word.length())
			return true;
		//backtracking
		if (start < word.length() && _canbe.find(word[start]) != _canbe.end() && _canbe[word[start]].size() != 0)
		{
			total = _canbe[word[start]];
			for (int ki = 0; ki < total.size(); ki++)
			{
				tmp = total[ki];
				//choose this one
				i = tmp[0];
				j = tmp[1];
				if (_copy[i][j] != '#'){
					vector<vector<char>> copy(_copy);
					unordered_map<char, vector<vector<int>>> canbe;
					vector<vector<int>> path(_path);

					vector<int> point;
					point.push_back(i);
					point.push_back(j);
					path.push_back(point);
					copy[i][j] = '#';
					if (j + 1 < n&&copy[i][j + 1] != '#')
					{
						vector<int> item;
						item.push_back(i);
						item.push_back(j + 1);
						canbe[copy[i][j + 1]].push_back(item);
					}
					if (j - 1 >= 0 && copy[i][j - 1] != '#')
					{
						vector<int> item;
						item.push_back(i);
						item.push_back(j - 1);
						canbe[copy[i][j - 1]].push_back(item);
					}
					if (i + 1 < m&&copy[i + 1][j] != '#')
					{
						vector<int> item;
						item.push_back(i + 1);
						item.push_back(j);
						canbe[copy[i + 1][j]].push_back(item);
					}
					if (i - 1 >= 0 && copy[i - 1][j] != '#')
					{
						vector<int> item;
						item.push_back(i - 1);
						item.push_back(j);
						canbe[copy[i - 1][j]].push_back(item);
					}
					if (check(board, copy, canbe, path, word, start + 1))
					{
						return true;
					}
				}
			}

		}
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		if (m == 0&&word.length()!=0)
			return false;
		int n = board[0].size();
		if (n == 0 && word.length() != 0)
			return false;
		if (word.length() == 0)
			return true;
		vector<vector<int>> path;
		unordered_map<char, vector<vector<int>>> canbe;
		int i, j;
		int start;
		vector<int> tmp;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				
				//start 
				if (board[i][j] == word[0])
				{
					vector<vector<char>> copy(board);

					vector<int> point;
					point.push_back(i);
					point.push_back(j);
					path.push_back(point);
					copy[i][j] = '#';
					if (j + 1 < n&&copy[i][j + 1] != '#')
					{
							vector<int> item;
							item.push_back(i);
							item.push_back(j+1);
							canbe[copy[i][j + 1]].push_back(item);
					}
					if (j - 1 >=0&&copy[i][j - 1] != '#')
					{
							vector<int> item;
							item.push_back(i);
							item.push_back(j - 1);
							canbe[copy[i][j - 1]].push_back(item);
					}
					if (i + 1 < m&&copy[i+1][j] != '#')
					{
						vector<int> item;
						item.push_back(i+1);
						item.push_back(j );
						canbe[copy[i+1][j]].push_back(item);
					}
					if (i-1 >= 0 && copy[i-1][j ] != '#')
					{
						vector<int> item;
						item.push_back(i - 1);
						item.push_back(j);
						canbe[copy[i - 1][j]].push_back(item);
					}
					start = 1;
					if (check(board, copy, canbe, path, word, start))
						return true;
				}
			}
		}
		return false;
	}
};
#else
class Solution
{
private:
	bool DFS(vector<vector<char>> board, string word,int i,int j,int k)
	{
		int m = board.size();
		int n = board[0].size();
		if (i >= m || j >= n || i<0 || j<0 || board[i][j] == '#' || board[i][j] !=word[k])
			return false;
		if (k == word.length() - 1)
			return true;
		board[i][j] = '#';
		if (DFS(board, word, i - 1, j, k + 1) || DFS(board, word, i + 1, j, k + 1)
			|| DFS(board, word, i, j - 1, k + 1) || DFS(board, word, i, j + 1, k + 1))
			return true;
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		if (m == 0 && word.length() != 0)
			return false;
		int n = board[0].size();
		if (n == 0 && word.length() != 0)
			return false;
		if (word.length() == 0)
			return true;
		int i, j;
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				//start 
				if (board[i][j] == word[0])
				{
					if (DFS(board, word, i, j, 0))
						return true;
				}
			}
		}
		return false;
	}
};
#endif
// 3 4 A B C E S F C S A D E E ABCCED
//1 5 A B C E G BCGAE 

int main()
{
	Solution s;
	vector<vector<char>> board;
	string word;
	char value;
	int m, n;
	while (true)
	{
		cin >> m >> n;
		board.clear();
		for (int i = 0; i < m; i++)
		{
			vector<char> item;
			for (int j = 0; j < n; j++)
			{
				cin >> value;
				item.push_back(value);
			}
			board.push_back(item);
		}
		cin >> word;
		cout << s.exist(board, word) << endl;
	}
	return 0;
}