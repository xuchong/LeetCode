#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
		{
			return;
		}
		//order of limits: rows , cols, 3x3 cells
		vector<unordered_map<char, int>> _3x3cells;
		vector<unordered_map<char, int>> rows;
		vector<unordered_map<char, int>> cols;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				unordered_map<char, int> item;
				for (int k = 0; k < 3;k++)
					for (int l = 0; l < 3; l++){
						if (board[i * 3 + k][j * 3 + l] != '.')
						{
							item[board[i * 3 + k][j * 3 + l]] = 1;// value 1 has used.
						}
					}
				_3x3cells.push_back(item);
			}
		}
		for (int i = 0; i < 9; i++)
		{
			unordered_map<char, int> item;
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
					item[board[i][j]] = 1;// value 1 has used.
			}
			rows.push_back(item);
		}
		for (int i = 0; i < 9; i++)
		{
			unordered_map<char, int> item;
			for (int j = 0; j < 9; j++)
			{
				if (board[j][i] != '.')
					item[board[j][i]] = 1;// value 1 has used.
			}
			cols.push_back(item);
		}
		//vector <vector<vector<unordered_map<char, int>>>> index;
		int lastPosition[81][2];
		int count = -1;
		char k = '1';
		int tmp;
		for (int i = 0; i < 9; i++)
		{	
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.')
				{
					while (k <= '9')
					{
						if (_3x3cells[i/3*3  + j / 3][k] == 0&&rows[i][k]==0&&cols[j][k]==0)
						{
							board[i][j] = k;
							break;
						}
						else
							k++;
					}
					if (k <= '9'){
						count++;
						lastPosition[count][0] = i;
						lastPosition[count][1] = j;
						_3x3cells[i/3*3  + j / 3][k] = 1; // 1?2 stands for: k is original val
						rows[i][k] = 1;
						cols[j][k] = 1;
						k = '1';
					}
					else
					{
						i = lastPosition[count][0];
						j = lastPosition[count][1];
						k = board[i][j];
						_3x3cells[i/3*3  + j / 3][k] = 0;
						rows[i][k] = 0;
						cols[j][k] = 0;
						k++;
						board[i][j] = '.';
						j--;
						count--;
					}
				}
			}
		}
	}
};
int main()
{
	Solution s;
	vector<vector<char>> board;
	char val;
	while (true)
	{
		for (int i = 0; i < 9; i++)
		{
			vector<char> item;
			for (int j = 0; j < 9; j++)
			{
				cin >> val;
				item.push_back(val);
			}
			board.push_back(item);
		}
		s.solveSudoku(board);
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
/*
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
*/