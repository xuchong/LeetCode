/***********************************************************************
 @Author: xuchong
 @Created Time : 四 10/10 00:26:32 2019
 @File Name: main.cpp
 @Description:
 ***********************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void qsort(vector<int>& citations, int s, int e)
    {
        if(s<e)
        {
            int i=s, j=e, k=s;
            int t= citations[k];
            while(i<j) {
                while (j > i && citations[j] >= t)
                    j--;
                citations[i] = citations[j];
                while (i < j && citations[i] <= t)
                    i++;
                citations[j] = citations[i];
            }
            citations[i] = t;
            qsort(citations, s, i);
            qsort(citations, i+1, e);
        }
    }
public:
    int hIndex(vector<int>& citations) {
        int result = 0;
        this->qsort(citations, 0, citations.size()-1);
        int i;
        for(i=citations.size()-1; i>=0;i--)
        {
            if(citations[i]<result + 1)
                break;
            result += 1;
        }
        return result;
    }
};

int main(){
    Solution s = Solution();
    vector<int>input={3,0,6,1,5};
    cout<<s.hIndex(input)<<endl;
    return 0;
}
/*
 * [10]   1
 * [0] 0
 * [1] 1
 *
 *
 * [3,0,6,1,5]
 *
 * 0,1,3,5,6
 */
