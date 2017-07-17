#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> result(rowIndex+1,1);
      int last,l;
      for(int i=1;i<=rowIndex;i++)
      {
        last=result[i];
        result[i]=1;
        for(int j=i+1;j<=rowIndex;j++)
        {
          l=result[j];
          result[j]=last+result[j-1];
          last=l;
        }
        result[i]=result[rowIndex];
      }
      return result;
    }
};
int main()
{
  vector<int> test(5);
  cout<<test.size()<<endl;
  return 0;
}
          //            1
          //           1 1
          //          1 2 1
          //         1 3 3 1
          //        1 4 6 4 1
          //      1 5 10 10 5 1
          //     1 6 15 20 15 6 1
          //
          // 1 row-1 (row-1)*row/2
          //
          // Fi,j=Fi-1,j-1+Fi-1,j
          // 1 1 1 1
          // 1 1 2 3
          //      1 3 2 3
          // 1 3 1 3
          //      1 3 3 3
          // 1 3 3 1
