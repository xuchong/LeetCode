#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
      if(s.empty())
        return;
      //rm space
      int space=0;
      int flag=1;// is have space
      int endindex;
      for(int i=0;i<s.length();i++)
      {
        if(s[i]==' ')
        {
          if(flag)
            space++;
          else{
            flag=true;
            s[i-space]=s[i];
          }
        }else
        {
          flag=false;
          s[i-space]=s[i];
        }
      }
      if(s[s.length()-space-1]==' ')
      {
        s[s.length()-space-1]='\0';
        endindex=s.length()-space-2;
      }else
      {
        s[s.length()-space]='\0';
        endindex=s.length()-space-1;
      }
      //from 0 to endindex,  reverse first
      int i=0,j=endindex;
      char tmp;
      while(i<j)
      {
        tmp=s[i];
        s[i]=s[j];
        s[j]=tmp;
        i++;
        j--;
      }
      //reverse each word
      int start,end;
      for(int i=0;i<=endindex;i++)
      {
        if(s[i]!=' ')
        {
          start=end=i;
          while(end<=endindex&&s[end]!=' ')
          {
            end++;
          }
          end--;
          i=end;
          while(start<end)
          {
            tmp=s[start];
            s[start]=s[end];
            s[end]=tmp;
            start++;
            end--;
          }
        }
      }
    }
};
int main(int argc,char** argv)
{
  Solution s;
  string input=argv[1];//"  abc  ";//"  fsdafa saf fdsf   f   fd  adf    ";
  s.reverseWords(input);
  cout<<input<<endl;
  return 0;
}
