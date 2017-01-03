#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int length=height.size();
        int start=0;
        int end=length-1;
        int maxArea=0;
        int i=0;
        while(start!=end)
        {
            if(height[start]<=height[end])
            {
                if(height[start]*(end-start)>maxArea)
                    maxArea=height[start]*(end-start);
                i=start;
                while(height[start]>=height[i]&&i<end)
                {
                    i++;
                }
                start=i;
            }
            else
            {
                if(height[end]*(end-start)>maxArea)
                    maxArea=height[end]*(end-start);
                i=end;
                while(height[end]>=height[i]&&i>start)
                {
                    i--;
                }
                end=i;
            }
        }
        return  maxArea;
    }
};
int main() {
    Solution s;
    int n,a;
    vector<int> data;
    while (true)
    {
        data.clear();
        cin>>n;
        while(n--)
        {
            cin>>a;
            data.push_back(a);
        }
        cout<<s.maxArea(data)<<endl;
    }
    return 0;
}