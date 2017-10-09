class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length()!=t.length())
        return false;
      int a[26];
      memset(a,0,sizeof(a));
      for(int i=0;i<s.size();i++)
      {
        a[s[i]-'0']++;
      }
      for(int i=0;i<t.size();i++)
      {
        a[t[i]-'0']--;
        if(a[t[i]-'0']<0)
          return false;
      }
      return true;
    }
};
