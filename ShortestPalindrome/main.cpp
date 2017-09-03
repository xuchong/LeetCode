class Solution {
public:
    string shortestPalindrome(string s) {
      if(s.length()<2)
        return s;
      int a=1,b=s[0]==s[1]?1:0;
      int maxIndex=0;
      bool asame=true,bsame=true;
      for(int i=1;i<s.length();i++)
      {
        if(a&&b)
        {
          if(s[i]==s[0])
          {
            a=1;
            b=1;
            asame=bsame=1;
            maxIndex=i;
          }else{
            a=0;
            b=0;
            asame=bsame=0;
          }
        }else if(a&&!b)
        {
            a=0;
            asame=false;
            bsame=false;
            if(s[1]!=s[i])
            {
              b=0;
            }else
            {
              int start=2,end=i-1;
              while(start<end)
              {
                if(s[start]!=s[end])
                {
                  b=0;
                  break;
                }
                start++;
                end--;
              }
              if(start>=end)
              {
                b=1;
              }
            }
        }else if(!a&&b)
        {
          asame=false;
          if(s[0]==s[i])
          {
            a=1;
            maxIndex=i;
            b=0;
            bsame=false;
          }else
          {
            a=0;
            int start=1,end=i;
            if(bsame)
            {
              if(s[start]==s[i])
              {
                b=1;
              }else
              {
                b=0;
                bsame=false;
              }
              continue;
            }
            while(start<end)
            {
              if(s[start]!=s[end])
              {
                b=0;
                break;
              }
              start++;
              end--;
            }
            if(start>=end)
            {
              b=1;
              bsame=true;
            }
          }
        }else{
          a=0;
          int start=1,end=i;
          while(start<end)
          {
            if(s[start]!=s[end])
            {
              b=0;
              break;
            }
            start++;
            end--;
          }
          if(start>=end)
          {
            b=1;
          }
        }
      }
      //
      string result="";
      for(int i=s.length()-1;i>maxIndex;i--)
      {
        result+=s[i];
      }
      result+=s;
      return result;
    }
};
