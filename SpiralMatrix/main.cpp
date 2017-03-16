#include <iostream>
#include<vector>
using namespace std;
class Solution {
private:
    //h start from 0
    void append(vector<vector<int>>matrix,vector<int>&result,int h)
    {
        int rows=matrix.size();
        int cols=matrix[0].size();
        if(rows-2*h==1)
        {
            for(int i=h;i<cols-h;i++)
            {
                result.push_back(matrix[h][i]);
            }
            return;
        }
        if(cols-2*h==1)
        {
            for(int i=h;i<rows-h;i++)
            {
                result.push_back(matrix[i][h]);
            }
            return;
        }
        // one
        for(int i=h;i<cols-h;i++)
        {
            result.push_back(matrix[h][i]);
        }
        //two
        for(int i=h+1;i<rows-h;i++)
        {
            result.push_back(matrix[i][cols-h-1]);
        }
        //three
        for(int i=cols-h-2;i>=h;i--)
        {
            result.push_back(matrix[rows-h-1][i]);
        }
        //four
        for(int i=rows-h-2;i>h;i--)
        {
            result.push_back(matrix[i][h]);
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0)
            return result;
        int min=matrix.size();
        if(matrix[0].size()<min)
            min=matrix[0].size();
        for(int h=0;h<(1+min)/2;h++)
            append(matrix,result,h);
        return result;
    }
};
int main() {
    Solution s;
    vector<vector<int>> matrix;
    vector<int>result;
    int m,n,val;
    while(true)
    {
        cin>>m>>n;
        matrix.clear();
        for(int i=0;i<m;i++)
        {
            vector<int> item;
            for(int j=0;j<n;j++)
            {
                cin>>val;
                item.push_back(val);
            }
            matrix.push_back(item);
        }
        result=s.spiralOrder(matrix);
        for(int i=0;i<result.size();i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}