class Solution {
private:
  unordered_set<int> canbefinished;
  bool isHasCircle(unordered_map<int,vector<int>>&dict,unordered_set<int> preparations,int num)
  {
    if(dict.find(num)==dict.end()||canbefinished.find(num)!=canbefinished.end())
    {
      canbefinished.insert(num);
      return false;
    }
    if(preparations.find(num)!=preparations.end())
      return true;
    preparations.insert(num);
    for(int i=0;i<dict[num].size();i++)
    {
      if(isHasCircle(dict,preparations,dict[num][i]))
        return true;
    }
    canbefinished.insert(num);
    return false;
  }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      unordered_map<int,vector<int>> dict;
      if(prerequisites.empty()||numCourses==0)
        return true;
      for(int i=0;i<prerequisites.size();i++)
      {
        if(dict.find(prerequisites[i].first)==dict.end())
        {
          dict[prerequisites[i].first]=vector<int>();
          dict[prerequisites[i].first].push_back(prerequisites[i].second);
        }else
        {
          dict[prerequisites[i].first].push_back(prerequisites[i].second);
        }
      }
      //find circle
      unordered_set<int> preparations;
      vector<int> layer;
      int item;
      for(unordered_map<int,vector<int>>::iterator it=dict.begin();it!=dict.end();it++)
      {
        if(canbefinished.find(it->first)!=canbefinished.end())
        {
          continue;
        }
        // if(isHasCircle(dict,preparations,it->first))
        //   return false;
        layer.push_back(it->first);
        while(!layer.empty())
        {
          item=layer.back();
          layer.pop_back();
          
        }
      }
      return true;
      //no prerequisites

    }
};
