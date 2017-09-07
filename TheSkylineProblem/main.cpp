struct Point_{
  int x;
  int h;
  bool isStart;
  Point_(int x,int h,bool isStart):x(x),h(h),isStart(isStart){}
};
bool compare(Point_ a,Point_ b)
{
   if(a.x!=b.x)
    return a.x<b.x;
   else
   {
     if((a.isStart&&b.isStart))
     {
       return a.h>b.h;   //solve same start!!
     }else if(!a.isStart&&!b.isStart)
     {
        return a.h<b.h;  //solve same end!!!
     }else
     {
       return a.isStart;  /// when end index meets start, need to first start,then end. or it will get zero!
     }
   }
};

/*  I'm sorry, it's WA.   wahhhahahah
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> output;
        if(buildings.empty())
          return output;
        vector<Point_> points;
        for(int i=0;i<buildings.size();i++)
        {
          Point_ start(buildings[i][0],buildings[i][2],true);
          Point_ end(buildings[i][1],buildings[i][2],false);
          points.push_back(start);
          points.push_back(end);
        }
        sort(points.begin(),points.end(),compare);
        vector<Point_> result;
        result.push_back(points[0]);
        for(int i=1;i<points.size();i++)
        {
          cout<<points[i].h<<endl;
          if(result.back().isStart)
          {
            if(points[i].isStart)
            {
              if(points[i].h>result.back().h)
              {
                result.push_back(points[i]);
              }
            }else
            {
              if(points[i].h>=result.back().h)
              {
                result.push_back(points[i]);
              }
            }
          }else
          {
            if(points[i].isStart)
            {
              if(points[i].x>result.back().x)
              {
                result.push_back(Point_(result.back().x,0,true));
              }
              result.push_back(points[i]);
            }else
            {
              if(points[i].h>=result.back().h)
              {
                result.pop_back();
                int x=result.back().x;
                result.pop_back();
                result.push_back(Point_(x,points[i].h,true));
                result.push_back(points[i]);
              }else
              {
                result.push_back(Point_(result.back().x,points[i].h,true));
                result.push_back(points[i]);
              }
            }
          }
        }

        // merge and clean result
        output.push_back(make_pair<int,int>(int(result[0].x),int(result[0].h)));
        for(int i=1;i<result.size();i++)
        {
          cout<<result[i].x<<" "<<result[i].h<<endl;
          if(result[i].h!=result[i-1].h)
          {
            if(output.size()>0&&output.back().first()==result[i].x&&output.back().second()>result[i].h)
            {
              output.pop_back();
            }
            output.push_back(make_pair<int,int>(int(result[i].x),int(result[i].h)));
          }
        }
        output.push_back(make_pair<int,int>(int(result.back().x),0));
        return output;
    }
};
*/

// sweap line : from topest to lowest 
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> output;
        if(buildings.empty())
          return output;
        vector<Point_> points;
        for(int i=0;i<buildings.size();i++)
        {
          Point_ start(buildings[i][0],buildings[i][2],true);
          Point_ end(buildings[i][1],buildings[i][2],false);
          points.push_back(start);
          points.push_back(end);
        }
        sort(points.begin(),points.end(),compare);
        // max-heap
        priority_queue<int> height;
        unordered_map<int,int> numsOfeachHeigh;
        height.push(0);
        int pre,cur;
        for(auto it:points)
        {
          pre=height.top();
          if(it.isStart)
          {
            height.push(it.h);
            numsOfeachHeigh[it.h]++;
          }else
          {
            if(numsOfeachHeigh[it.h])
            {
              numsOfeachHeigh[it.h]--;
            }
            while(height.size()>1&&!numsOfeachHeigh[height.top()])
            {
                height.pop();
            }
          }
          cur=height.top();
          if(pre!=cur)
          {
            output.push_back(make_pair<int,int>(int(it.x),int(cur)));
          }
        }
        return output;
      }
};
