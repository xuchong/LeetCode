class Solution {
private:
  //return 0 equal,-1 smaller,1 bigger
  int compare(int a,int b)
  {
    if(a==b)
      return 0;
    stringstream ss;
    string aa;
    ss<<a;
    aa=ss.str();
    ss.clear();
    ss.str("");
    ss<<b;
    string bb=ss.str();
    int i=0;
    while(i<aa.length()&&i<bb.length())
    {
      if(aa[i]>bb[i])
      {
        return 1;
      }else if(aa[i]<bb[i])
      {
        return -1;
      }
      i++;
    }
    if(i<aa.length())
    {
      string newstr=aa.substr(i,aa.length()-i);
      newstr+=bb;
      //aa before
      i=0;
      while(i<newstr.length())
      {
        if(newstr[i]>aa[i])
        {
          return 1;
        }else if(newstr[i]<aa[i])
        {
          return -1;
        }
        i++;
      }
      return 0;
    }
    if(i<bb.length())
    {
      string newstr=bb.substr(i,bb.length()-i);
      newstr+=aa;
      //bb before
      i=0;
      while(i<newstr.length())
      {
        if(newstr[i]>bb[i])
        {
          return -1;
        }else if(newstr[i]<bb[i])
        {
          return 1;
        }
        i++;
      }
      return 0;
    }
  }
public:
    string largestNumber(vector<int>& nums) {
      vector<list<int>> dict(10,list<int>());
      int start;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]==0)
        {
          dict[0].push_back(0);
        }else
        {
          start=(int)log(nums[i])/log(10);
          start=nums[i]/(int)(pow(10,start));
          //insert nums[i]
          list<int>::iterator j;
          for(j=dict[start].begin();j!=dict[start].end();j++)
          {
            if(compare(nums[i],*j)>=0)
            {
              dict[start].insert(j,nums[i]);
            }
          }
          if(j==dict[start].end())
          {
            dict[start].push_back(nums[i]);
          }
        }
      }
      //merge
      stringstream ss;
      string result;
      for(int i=dict.size()-1;i>=0;i--)
      {
        for(list<int>iterator:: it=dict[i].begin();it!=dict[i].end();it++)
        {
          ss<<*it;
        }
      }
      result=ss.str();
      return result;
    }
};
