#include <iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
/**
 * 递归方法，如果讲究速度，可以牺牲空间，消除重复递归
 */
class Solution {
private:
    /**
     * 左边括号的个数
     * @param n
     * @param left
     * @return
     */
    vector<string> recursive(int n,int left)
    {
        vector<string> result,data;
        if(n==1)
        {
            if(left==1) {
                string item = "()";
                result.push_back(item);
                return result;
            }else
            {
                return result;
            }
        }
        if(left==0)
            return result;
        int j=left;
        while(j<=n) {
            data = recursive(n - 1, j - 1);
            for (int i = 0; i < data.size(); i++) {
                string item = data[i];
                item = item.insert(left-1, "()");
                result.push_back(item);
            }
            j++;
        }
        return result;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result,data;
        if(n<1)
            return result;
        for(int i=1;i<=n;i++)
        {
            data=recursive(n,n-i+1);
            result.insert(result.end(),data.begin(),data.end());
        }
        return result;
    }
};
int main() {
    Solution s;
    int n;
    vector<string> result;
    while(true)
    {
        cin>>n;
        result=s.generateParenthesis(n);
        for(int i=0;i<result.size();i++)
        {
            cout<<result[i]<<endl;
        }

    }
    return 0;
}