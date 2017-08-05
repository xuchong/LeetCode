#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//#define stupid
#ifndef stupid
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      for(int i=0;i<nums.size();i=i+3)
      {
        if(i==nums.size()-1||nums[i]!=nums[i+1])
          return nums[i];
      }
    }
};
#elif
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        for(int i=0;i<nums.size();i++)
        {
          ones=ones^nums[i]&~twos;
          twos=twos^nums[i]&~ones;
        }
        return ones;
    }
};
#endif
int main(){
  return 0;
}
