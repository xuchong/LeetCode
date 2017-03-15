#include <iostream>
#include <vector>
#include <string>
#include<cstring>
using namespace std;
#define TL
#ifndef TL
class Solution {
private:
    vector<vector<string>> recursive(int n)
    {
        vector<vector<string>> result;
        if(n==1)
        {
            vector<string> item;
            item.push_back("Q");
            result.push_back(item);
            return result;
        }
        vector<vector<string>> sub=recursive(n-1);
        for(int i=0;i<n;i++)
        {
            vector<vector<string>> copySub(sub);
            for(int j=0;j<copySub.size();j++) {
                //make i th vector
                vector<string> matrix;
                vector<string> submatrix=copySub[j];
                string item(n, '.');
                item[i] = 'Q';
                matrix.push_back(item);
                for(int k=0;k<submatrix.size();k++)
                {
                    matrix.push_back(submatrix[k].insert(i,".").c_str());
                }
                result.push_back(matrix);
            }
        }
        return result;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if(n<=0)
            return result;
        result= recursive(n);
        int x,y,x1,y1;
        int i,j,k;
        for( i=0;i<result.size();i++)
        {
            //one matrix
            for( j=0;j<result[i].size();j++)
            {
                x=j;
                y=result[i][j].find("Q");
                for( k=j+1;k<result[i].size();k++)
                {
                    x1=k;
                    y1=result[i][k].find("Q");
                    if((x1-x)==(y1-y)||(x1-x)==y-y1)
                    {
                        break;
                    }
                }
                if(k!=result[i].size())
                    break;
            }
            if(k!=result[i].size())
            {
                result.erase(result.begin()+i);
                i--;
            }

        }
        return result;
    }
};
#else
//back tracking
class Solution {
private:
	bool checkIfcan(vector<int>& matrix,int index){
		int i;
		int n = matrix.size();
		matrix[index]++;
		while (matrix[index] < n)
		{
			for ( i = 0; i < index; i++)
			{
				// same column or diagonal
				if (matrix[index]==matrix[i]||matrix[i] - matrix[index] == i - index || matrix[i] - matrix[index] == index - i)
				{
					break;
				}
			}
			if (i == index)
			{
				return true;
			}
			matrix[index]++;
		}
		matrix[index] = -1;
		return false;
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		if (n <= 0)
			result;
		vector<int> matrix_int(n,-1);
		for (int i = 0; i < n; i++)
		{
	
			if (!checkIfcan(matrix_int, i))
			{
				if (i == 0)
					break;
				i -= 2;
			}
			// already do
			else if (i == n - 1)
			{
				vector<string> matrix;
				for (int j = 0; j < n; j++)
				{
					string item(n, '.');
					item[matrix_int[j]] = 'Q';
					matrix.push_back(item);
				}
				result.push_back(matrix);

				i--;
			}
		}

		return result;
	}
};
#endif
int main() {
    Solution s;
    vector<vector<string>> result;
    string a;
    int n;
    while(true)
    {
        cin>>n;
        result=s.solveNQueens(n);
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<result[i].size();j++)
            {
                cout<<result[i][j]<<endl;
            }
            cout<<endl;
        }
    }
    return 0;
}