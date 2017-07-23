#include<iostream>
#include<cstring>
#include<string>
using namespace std;
class Solution {
private:
    bool isNumberOrChr(char a)
    {
      if((a>='0'&&a<='9')||(a>='a'&&a<='z')||(a>='A'&&a<='Z'))
      {
        return true;
      }
      return false;
    }
    int isNumber(char a)
    {
      if((a>='0'&&a<='9'))
      {
        return a-'0';
      }
      return -1;
    }
    int isChar(char a)
    {
      if((a>='a'&&a<='z'))
      {
        return a-'a';
      }else if(a>='A'&&a<='Z')
      {
        return a-'A';
      }
      return -1;
    }
public:
    bool isPalindrome(string s) {
      if(s.length()==0)
        return true;
      int start,end;
      start=0;
      end=s.length()-1;
      while(start<end)
      {
        if(!isNumberOrChr(s[start]))
        {
          start++;
          continue;
        }
        if(!isNumberOrChr(s[end]))
        {
          end--;
          continue;
        }
        if((isNumber(s[start])!=-1&&isNumber(s[end])!=-1&&isNumber(s[start])==isNumber(s[end]))||(isChar(s[start])!=-1&&isChar(s[end])!=-1&&isChar(s[start])==isChar(s[end])))
        {
          start++;
          end--;
        }else{
          return false;
        }
      }
      return true;
    }
};
int main()
{
  return 0;
}
