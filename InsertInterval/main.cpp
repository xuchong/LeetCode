#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Definition for an interval.*/
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool cmp(const Interval& a,const Interval& b)
{
    return a.start<b.start;
}
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        vector<Interval> result;
        if(intervals.size()==0)
            return result;
        sort(intervals.begin(),intervals.end(),cmp);
        Interval last=intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(last.end<intervals[i].start)
            {
                result.push_back(last);
                last=intervals[i];
            }else
            {
                if(intervals[i].end>last.end)
                {
                    last.end=intervals[i].end;
                }
            }
        }
        result.push_back(last);
        return result;
    }
};
int main() {
    Solution s;
    vector<Interval> intervals;
    int n;
    int start,end;
    while(true)
    {
        intervals.clear();
        cin>>n;
        while(n--)
        {
            cin>>start>>end;
            Interval item(start,end);
            intervals.push_back(item);
        }
        intervals=s.merge(intervals);
        for(int i=0;i<intervals.size();i++)
            cout<<"["<<intervals[i].start<<","<<intervals[i].end<<"]"<<" ";
        cout<<endl;
    }
    return 0;
}