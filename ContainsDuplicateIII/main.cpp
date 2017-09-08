#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
bool compare(int a,int b)
{
  return a<b;
}
#define WA

#ifndef WA
// WA again!...   wahahah
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size()<2||t<0||k<=0)
          return false;
        priority_queue<int> maxHeap;
        priority_queue<int,vector<int>,greater<int> > minHeap;
        unordered_set<int> sets;
        if(k>=nums.size())
          k=nums.size()-1;
        maxHeap.push(nums[0]);
        minHeap.push(nums[0]);
        sets.insert(nums[0]);
        for(int i=1;i<=k;i++)
        {
          cout<<maxHeap.top()<<" "<<minHeap.top()<<endl;
          if(abs(maxHeap.top()-nums[i])<=t||abs(minHeap.top()-nums[i])<=t)
            return true;
          maxHeap.push(nums[i]);
          minHeap.push(nums[i]);
          sets.insert(nums[i]);
        }
        cout<<2<<endl;
        for(int i=k+1;i<nums.size();i++)
        {
          sets.erase(nums[i-k-1]);
          while(sets.find(maxHeap.top())==sets.end())
          {
            maxHeap.pop();
          }
          while(sets.find(minHeap.top())==sets.end())
          {
            minHeap.pop();
          }
          if(abs(maxHeap.top()-nums[i])<=t||abs(minHeap.top()-nums[i])<=t)
            return true;
          sets.insert(nums[i]);
          maxHeap.push(nums[i]);
          minHeap.push(nums[i]);
        }
        return false;
    }
};
#elif
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      if(nums.size()<2||t<0||k<=0)
          return false;
      if(k>=nums.size())
        k=nums.size()-1;
      unordered_map<long,long > maps;
      long bucketNum;
      for(int i=0;i<=k;i++)
      {
        bucketNum=(long(nums[i])-INT_MIN)/(long(t)+1);
        //cout<<bucketNum<<endl;
        if(maps.find(bucketNum)!=maps.end())
        {
          return true;
        }else
        {
          maps[bucketNum]=(long(nums[i])-INT_MIN);
          //add new
          if(maps.find(bucketNum-1)!=maps.end())
          {
            if(maps[bucketNum]-maps[bucketNum-1]<=t)
              return true;
          }
          if(maps.find(bucketNum+1)!=maps.end())
          {
            if(maps[bucketNum+1]-maps[bucketNum]<=t)
              return true;
          }
        }
      }
      for(int i=k+1;i<nums.size();i++)
      {
        //remove it
        bucketNum=(long(nums[i-k-1])-INT_MIN)/(long(t)+1);
        if(maps.find(bucketNum)!=maps.end())
        {
          maps.erase(bucketNum);
        }
        bucketNum=(long(nums[i])-INT_MIN)/(long(t)+1);
        if(maps.find(bucketNum)!=maps.end())
        {
          return true;
        }
        else
        {
          maps[bucketNum]=(long(nums[i])-INT_MIN);
          //add new
          if(maps.find(bucketNum-1)!=maps.end())
          {
            if(maps[bucketNum]-maps[bucketNum-1]<=t)
              return true;
          }
          if(maps.find(bucketNum+1)!=maps.end())
          {
            if(maps[bucketNum+1]-maps[bucketNum]<=t)
              return true;
          }
        }
      }
      return false;
    }
};

#endif

int main(int argc, char const *argv[]) {

  return 0;
}
