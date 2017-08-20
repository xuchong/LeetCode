class Solution {
private:
  void changeToqueue(string s,list<int>& result)
  {
    int number=0;
    for(int i=0;i<s.length();i++)
    {
      if(s[i]=='.')
      {
        result.push_back(number);
        number=0;
      }else
      {
        number=number*10+s[i]-'0';
      }
    }
    result.push_back(number);
  }
public:
    int compareVersion(string version1, string version2) {
        list<int> a,b;
        changeToqueue(version1,a);
        changeToqueue(version2,b);

        //clean back
        while(a.size()>1&&a.back()==0)
        {
          a.pop_back();
        }
        while(b.size()>1&&b.back()==0)
        {
          b.pop_back();
        }

        while(!a.empty()&&!b.empty())
        {
          if(a.front()>b.front())
            return 1;
          else if(a.front()<b.front())
            return -1;
          else
          {
            a.pop_front();
            b.pop_front();
          }
        }
        if(a.empty()&&b.empty())
        {
          return 0;
        }else if(a.empty())
        {
          return -1;
        }else
        {
          return 1;
        }
    }
};
