/***********************************************************************
 @Author: xuchong
 @Created Time : 五 10/11 01:30:28 2019
 @File Name: main.cpp
 @Description:
 ***********************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //linear
    int hIndex_(vector<int>& citations) {
        int i=0;
        for(i=citations.size() - 1;i>=0; i--)
        {
            if(citations[i] < citations.size() - i)
                break;
        }
        return citations.size() - i - 1;
    }
    int hIndex(vector<int>& citations) {
        // find first element that citations.size() - i > citations[i]
        int start=0, end = citations.size() - 1;
        int mid = 0;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if(citations[mid] < citations.size() - mid) {
                // mid too small
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return citations.size() - end - 1;
    }
};


int main()
{
    Solution s=Solution();
    vector<int>input={0,1,3,5,6};
    cout<<s.hIndex(input)<<endl;
    return 0;
}