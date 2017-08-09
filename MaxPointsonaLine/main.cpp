#include<iostream>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct Point{
  int x;
  int y;
  Point():x(0),y(0){}
  Point(int a,int b):x(a),y(b){}
}
class Solution {
private:
    int measure(int x, int y)
    {
        int z = y;
        while(x%y!=0)
        {
            z = x%y;
            x = y;
            y = z;
        }
        return z;
    }
public:
    int maxPoints(vector<Point>& points) {
      if(points.size()<=1)
        return points.size();
      unordered_map<int,unordered_map<int,unordered_map<int,unordered_set<int>>>> dict;// y=k*x+b.  k=k1/k2,key=key1,key2=vector[0], b=vector[1]. number=vector[2]; we presume: key1 positive.
      int divisor,key1,key2,b,flag=1;
      int count=0;
      unordered_map<int,vector<int>> specialone;// key2=0
      for(int i=0;i<points.size();i++)
      {
        for(int j=i+1;j<points.size();j++)
        {
          key1=(points[j].y-points[i].y);
          key2=(points[j].x-points[i].x);
          if(key2==0)
          {
            if(specialone.find(points[i].x)==specialone.end()){
                specialone[points[i].x].push_back(i);
                specialone[points[i].x].push_back(2);
              }
            else{
                if(i==specialone[points[i].x][0])
                  specialone[points[i].x][1]+=1;
              }
            count=specialone[points[i].x][1]>count?specialone[points[i].x][1]:count;
            continue;
          }

          if((key1>=0&&key2>0)||(key1<=0&&key2<0))
          {
            flag=1;
          }else
          {
            flag=-1;
          }
          divisor=measure(abs(key1),abs(key2));
          key1=abs(key1)/divisor;
          key2=abs(key2)/divisor*flag;
          b=points[i].y-points[i].x*key1/key2;
          auto it1=dict.find(key1);
          if(it1!=dict.end())
          {
            auto it2=it1->second.find(key2);
            if(it2!=it1->second.end())
            {
              auto it3=it2->second.find(b);
              if(it3!=it2->second.end())
              {
                //if(it3->second[0]==i||(points[it3->second[0]].x==points[j].x&&points[it3->second[0]].y==points[j].y)||(points[it3->second[0]].x==points[i].x&&points[it3->second[0]].y==points[i].y)){
                auto it4=it3->second.find(j);
                if(it4==it3->second.end()){
                  it3->second.insert(j);
                  count=it3->second.size()>count?it3->second.size():count;
                }
                it4=it3->second.find(i);
                if(it4==it3->second.end()){
                  it3->second.insert(i);
                  count=it3->second.size()>count?it3->second.size():count;
                }
              }
              else
              {
                it2->second[b].insert(i);
                it2->second[b].insert(j);
                count=2>count?2:count;
              }
            }else
            {
              //it1->second[key2]=unordered_map<int,int>();
              it1->second[key2][b].insert(i);
              it1->second[key2][b].insert(j);
              count=2>count?2:count;
            }
          }else
          {
            // dict[key1]=unordered_map<int,unordered_map<int,int>>();
            // dict[key1][key2]={b,1};
            dict[key1][key2][b].insert(i);
            dict[key1][key2][b].insert(j);
            count=2>count?2:count;
          }
        }
      }
      return count;
    }
};
