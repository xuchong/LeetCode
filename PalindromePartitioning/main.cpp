#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
private:
vector<vector<string>> result;
bool checkIsPalindrome(string s,int start,int end)
{
  while(start<end)
  {
    if(s[start]!=s[end])
      return false;
    start++;
    end--;
  }
  return true;
}
void recursive(string& s,int start,int end,vector<string> item)
{
  if(start==end)
  {
    item.push_back(s.substr(start,1));
    result.push_back(item);
    return;
  }
  for(int i=start;i<=end;i++)
  {
    if(checkIsPalindrome(s,start,i))
    {
      item.push_back(s.substr(start,i-start+1));
      if(i+1<=end)
      {
        recursive(s,i+1,end,item);
        item.pop_back();
      }else
      {
          result.push_back(item);
      }
    }
  }
}
public:
    vector<vector<string>> partition(string s) {
        if(s.empty())
          return result;
        vector<string> item;
        recursive(s,0,s.length()-1,item);
        return result;
    }
};
int main()
{
  return 0;
}
