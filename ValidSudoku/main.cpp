#include <iostream>
#include<vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool result=false;
        if(board.size()==0||board[0].size()==0)
            return result;
        unordered_map<char,int> index;
        //check rows
        for(int i=0;i<board.size();i++)
        {
            index.clear();
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]!='.')
                {
                    if(index.find(board[i][j])!=index.end())
                    {
                        return result;
                    } else
                    {
                        index[board[i][j]]=1;
                    }
                }
            }
        }
        //check cols
        for(int i=0;i<board[0].size();i++)
        {
            index.clear();
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i]!='.')
                {
                    if(index.find(board[j][i])!=index.end())
                    {
                        return result;
                    } else
                    {
                        index[board[j][i]]=1;
                    }
                }
            }
        }
        //check each 3x3 cells
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                index.clear();
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        if(board[k+i*3][l+j*3]!='.')
                        {
                            if(index.find(board[k+i*3][l+j*3])!=index.end())
                            {
                                return result;
                            } else
                            {
                                index[board[k+i*3][l+j*3]]=1;
                            }
                        }
                    }
                }
            }
        }
        result=true;
        return result;

    }
};
int main() {

    return 0;
}