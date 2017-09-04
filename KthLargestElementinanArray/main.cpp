#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// default: make_heap is max-heap
bool compare(int a,int b)
{
  return a>b;
}
void show(vector<int> topK)
{
  cout<<"show:"<<endl;
  for(int i=0;i<topK.size();i++)
  {
    cout<<topK[i]<<endl;
  }
}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      vector<int> topK;
      topK.insert(topK.end(),nums.begin(),nums.begin()+k);
      make_heap(topK.begin(),topK.end(),compare);

      for(int i=k;i<nums.size();i++)
      {
        if(nums[i]>topK.front())
        {

          pop_heap(topK.begin(),topK.end(),compare);

          topK.back()=nums[i];
          push_heap(topK.begin(),topK.end(),compare);
          
        }
      }
      return 0;
    }
};
  // 5 3 2 1 4 6 3
int main()
{
  Solution s;
  int k;
  int n;
  cin>>n;
  vector<int>nums(n);
  for(int i=0;i<n;i++)
    cin>>nums[i];
  cin>>k;
  s.findKthLargest(nums,k);
  return 0;
}
