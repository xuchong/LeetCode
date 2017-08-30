class Solution {
private:
  set<int> canbefinished;
  bool isHasCircle(unordered_map<int,vector<int>>&dict,vector<int>&preparations,int num)
  {
    if(dict.find(num)==dict.end()||canbefinished.find(num)!=canbefinished.end())
    {
      canbefinished.insert(num);
      return false;
    }
    if(preparations[num])
      return true;
    preparations[num]=1;
    for(int i=0;i<dict[num].size();i++)
    {
      if(isHasCircle(dict,preparations,dict[num][i]))
        return true;
    }
    preparations[num]=0;
    canbefinished.insert(num);
    return false;
  }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<int> result;
      if(numCourses==0)
        return result;
      unordered_map<int,vector<int>> dict;
      for(int i=0;i<prerequisites.size();i++)
      {
        if(dict.find(prerequisites[i].first)==dict.end())
        {
          dict[prerequisites[i].first]=new vector<int>();
          dict[prerequisites[i].first].push_back(prerequisites[i].second);
        }else
        {
          dict[prerequisites[i].first].push_back(prerequisites[i].second);
        }
      }
      vector<int> preparations(numCourses,0);
      for(unordered_map<int,vector<int>>::iterator it=dict.begin();it!=dict.end();it++)
      {
        if(canbefinished.find(it->first)!=canbefinished.end())
          continue;
        else
        {
          if(isHasCircle(dict,preparations,it->first))
            return result;
        }
      }
      result.insert(result.end(),canbefinished.begin(),canbefinished.end());
      for(int i=0;i<numCourses;i++)
      {
        if(canbefinished.find(i)==canbefinished.end())
          result.push_back(i);
      }
      return result;
    }
};
