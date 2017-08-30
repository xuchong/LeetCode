class Solution {
public:
    bool isIsomorphic(string s, string t) {
      unordered_map<char,char> dicts,dictt;
      if(s.empty())
        return true;
      for(int i=0;i<s.length();i++)
      {
        if(dicts.find(s[i])==dicts.end()&&dictt.find(t[i])==dictt.end())
        {
          dicts[s[i]]=t[i];
          dictt[t[i]]=s[i];
        }else if(dicts.find(s[i])!=dicts.end()&&dictt.find(t[i])!=dictt.end())
        {
          if(dicts[s[i]]==t[i]&&dictt[t[i]]==s[i])
          {
            continue;
          }else
          {
            return false;
          }
        }else
        {
          return false;
        }
      }
      return true;
    }
};
