#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
      if(ratings.empty())
        return 0;
      int start=0,end=0;
      int result=0;
      if(ratings.size()==1)
         return 1;
      vector<int> index(ratings.size(),1);
      for(int i=0;i<ratings.size()-1;i++)
      {
        //from index: i
        start=i;
        end=start+1;
        if(ratings[start]<ratings[end])
        {
          while(ratings[end]>ratings[end-1]&&end<ratings.size())
          {
            end++;
          }
          index[end-1]=end-start;
          //sum from start ... end-2
          result+=(end-start)*(end-start-1)/2;
          if(end>=ratings.size())
            result+=index[end-1];
          i=end-2;
        }else if(ratings[start]>ratings[end])
        {
          while(ratings[end]<ratings[end-1]&&end<ratings.size())
          {
            end++;
          }
          if(index[start]<end-start)
          {
            index[start]=end-start;
          }
          //sum from start ... end-2
          result+=(2+end-start-1)*(end-start-2)/2+index[start];
          if(end>=ratings.size())
          {
            result+=1;
          }
          i=end-2;
        }else
        {
          while(ratings[end]==ratings[end-1]&&end<ratings.size())
          {
            end++;
          }
          //sum from start ... end-2
          result+=index[start]+(end-start-2);
          if(end>=ratings.size())
          {
            result+=1;
          }
          i=end-2;
        }
      }
      return result;
    }
};
int main()
{
  return 0;
}
