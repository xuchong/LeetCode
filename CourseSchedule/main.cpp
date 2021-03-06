#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<fstream>
using namespace std;
class Solution {
private:
  unordered_set<int> canbefinished;
  bool isHasCircle(unordered_map<int,vector<int>>&dict,vector<int>& preparations,int num)
  {
    if(dict.find(num)==dict.end()||canbefinished.find(num)!=canbefinished.end())
    {
      canbefinished.insert(num);
      return false;
    }
    if(preparations[num]==1)
      return true;
    preparations[num]=1;
    for(int i=0;i<dict[num].size();i++)
    {
      if(isHasCircle(dict,preparations,dict[num][i]))
        return true;
    }
    canbefinished.insert(num);
	preparations[num] = 0;
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
      vector<int> preparations(numCourses,0);
      vector<int> layer;
      int item;
      for(unordered_map<int,vector<int>>::iterator it=dict.begin();it!=dict.end();it++)
      {
        if(canbefinished.find(it->first)!=canbefinished.end())
        {
          continue;
        }
		if (isHasCircle(dict, preparations, it->first))
           return false;
        /*layer.push_back(it->first);
        while(!layer.empty())
        {
          item=layer.back();
          layer.pop_back();
          if(dict.find(item)==dict.end()||)
        }

        }*/
      }
      return true;
      //no prerequisites

    }
};

int main()
{
	Solution s;
	ifstream in("data");
	int number;
	in >> number;
	vector<pair<int, int>>prerequists;
	int i = 0, x, y;
	while (i < number)
	{
		in >> x >> y;
		i++;
		prerequists.push_back(make_pair(x, y));
	}
	in.close();
	cout << s.canFinish(number, prerequists) << endl;
	return 0;
}
