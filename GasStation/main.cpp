#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
void recursive(vector<vector<int>>& index,vector<int>&gas,vector<int>&cost,int n)
{

}
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      if(gas.empty())
        return -1;
      //index[i][2] :record index i, getIndex j ,left gas
      vector<vector<int>>index(gas.size(),vector<int>());
      int n=gas.size();
      int sum=0;
      int i,t;
      for(i=n-1;i>=0;i--)
      {
        //process each index i
        sum=0;
        for(int j=0;j<n;j++)
        {
          t=(i+j)%n;
          if(!index[t].empty())
          {
            j=(index[t][0]+n-i)%n;
            sum+=index[t][1];
            t=index[t][0];
            if(sum>=cost[t])
            {
              sum-=cost[t];
            }else
            {
              index[i].push_back(t);
              index[i].push_back(sum);
              break;
            }
            continue;
          }
          sum+=gas[t];
          if(sum>=cost[t])
            sum-=cost[t];
          else{
            index[i].push_back(t);
            index[i].push_back(sum);
            break;
          }
        }
        if(index[i].size()==0)
        {
          return i;
        }
      }
      return -1;
    }
};
int main()
{
  return 0;
}
