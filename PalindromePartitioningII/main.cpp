#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include
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
// int getNumberByRecursive(string& s,int dp[][1000] ,int start,int end)
// {
//   if(dp[start][end])
//   {
//     return 0;
//   }
//   int cut=INT_MAX;
//   int tmp;
//   for(int i=start;i<end;i++)
//   {
//     if(dp[start][i])
//     {
//       tmp=getNumberByRecursive(s,dp,i+1,end);
//
//       if(tmp==0)
//       {
//         cut=tmp+1;
//         return cut;
//       }else
//       {
//         cut=min(cut,tmp+1);
//       }
//     }
//   }
//   return cut;
// }
public:
    int minCut(string s) {
        if(s.empty())
          return 0;
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        for(int i=0;i<s.length();i++)
        {
            dp[i][i]=1;
        }
        //return getNumberByRecursive(s,dp,0,s.length()-1);
        int cuts[s.length()];
        //from 0 to N == cuts[N] how many
        cuts[0]=0;
        // for(int i=1;i<s.length();i++)
        // {
        //   if(isPalindrome(s,0,i))
        //   {
        //     cuts[i]=0;
        //     continue;
        //   }
        //   cuts[i]=cuts[i-1]+1;
        //   for(int j=1;j<i;j++)
        //   {
        //     if(s[j]==s[i]&&isPalindrome(s,j,i)&&(cuts[j-1]+1)<cuts[i])
        //     {
        //       cuts[i]=cuts[j-1]+1;
        //     }
        //   }
        //
        // }

        for(int i=1;i<s.length();i++)
        {
          cuts[i]=cuts[i-1]+1;
          for(int j=0;j<i;j++)
          {
            if(dp[j+1][i-1]&&s[i]==s[j])
            {
              dp[j][i]=1;
              if(j==0)
                cuts[i]=0;
              else
                cuts[i]=min(cuts[i],cuts[j-1]+1);
            }
          }
        }
        return cuts[s.length()-1];
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
