#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
class Solution {
private:
bool isPalindrome(string& s,int start,int end)
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
int getNumberByRecursive(string& s,int dp[][1000] ,int start,int end)
{
  if(dp[start][end])
  {
    return 0;
  }
  int cut=INT_MAX;
  int tmp;
  for(int i=start;i<end;i++)
  {
    if(dp[start][i])
    {
      tmp=getNumberByRecursive(s,dp,i+1,end);

      if(tmp==0)
      {
        cut=tmp+1;
        return cut;
      }else
      {
        cut=min(cut,tmp+1);
      }
    }
  }
  return cut;
}
public:
    int minCut(string s) {
        if(s.empty())
          return 0;
        int dp[1000][1000]={0};
        for(int i=0;i<s.length();i++)
        {
          for(int j=i;j<s.length();j++)
          {
            dp[i][j]=isPalindrome(s,i,j);
          }
        }
        return getNumberByRecursive(s,dp,0,s.length()-1);

    }
};
/*
apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp
*/
int main()
{
  Solution s;
  string str="apjesgpsxoeiokmqmfgvjslcjukbqxpsobyhjpbgdfruqdkeiszrlmtwgfxyfostpqczidfljwfbbrflkgdvtytbgqalguewnhvvmcgxboycffopmtmhtfizxkmeftcucxpobxmelmjtuzigsxnncxpaibgpuijwhankxbplpyejxmrrjgeoevqozwdtgospohznkoyzocjlracchjqnggbfeebmuvbicbvmpuleywrpzwsihivnrwtxcukwplgtobhgxukwrdlszfaiqxwjvrgxnsveedxseeyeykarqnjrtlaliyudpacctzizcftjlunlgnfwcqqxcqikocqffsjyurzwysfjmswvhbrmshjuzsgpwyubtfbnwajuvrfhlccvfwhxfqthkcwhatktymgxostjlztwdxritygbrbibdgkezvzajizxasjnrcjwzdfvdnwwqeyumkamhzoqhnqjfzwzbixclcxqrtniznemxeahfozp";
  cout<<s.minCut(str)<<endl;
  return 0;
}
