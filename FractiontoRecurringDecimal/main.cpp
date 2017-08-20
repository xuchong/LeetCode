#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
class Solution {
private:
  bool checkIsCycle(vector<int>&result,int one,int two,int n)
  {
    while(n>0)
    {
      if(result[one]!=result[two])
      {
        return false;
      }
      one++;
      two++;
      n--;
    }
    return true;
  }
public:
    string fractionToDecimal(int numerator, int denominator1) {
        long numberator=numerator;
        long denominator=denominator1;
        if(numberator==0)
          return "0";
        vector<int> result;
        long integer=0;
        long flagPorN=long(numberator)*denominator>0?1:-1;
        numberator=abs(numberator);
        denominator=abs(denominator);

        //integer part
        if(numberator/denominator>0)
        {
          integer=(numberator/denominator);
          numberator=numberator%denominator;
        }
        if(numberator==0)
        {
          integer*=flagPorN;
          stringstream ss;
          ss<<integer;
          return ss.str();
        }
        for(int i=0;i<10000;i++)
        {
          numberator*=10;
          result.push_back(numberator/denominator);
          numberator=numberator%denominator;
          if(numberator==0)
          {
            break;
          }
        }
        if(numberator!=0){
          //fraction part: find cycle
          int startindex=0;
          int one=startindex,two=startindex;
          //one+1  is  k of  cycle length
          while(one==two ||result[one]!=result[two]||!checkIsCycle(result,one,two,one+1>15?one+1:15))
          {
            one++;
            two+=2;
          }
          int newone=startindex;
          while(result[newone]!=result[two]||!checkIsCycle(result,newone,two,one+1>15?one+1:15))
          {
            newone++;
            two++;
          }
          //from index
          int from=newone;
          int lengthOfcircle=0;
          one=from;
          two=from;
          while(one==two ||result[one]!=result[two]||!checkIsCycle(result,one,two,one+1>15?one+1:15))
          {
            one++;
            two+=2;
          }
          lengthOfcircle=two-one;

          stringstream ss;
          string output="";
          if(integer==0)
          {
            if(flagPorN==1)
            {
              output+="0.";
            }else
            {
              output+="-0.";
            }
            ss<<output;
          }else
          {
            integer*=flagPorN;
            ss<<integer;
            //output=ss.str();
            //output+=".";
            ss<<".";
          }
          //append fraction part;
          for(int i=0;i<result.size();i++)
          {
            if(i==from)
              ss<<"(";
            if(i==from+lengthOfcircle)
            {
              ss<<")";
              break;
            }
            ss<<result[i];
          }
          return ss.str();

      }else
      {
        stringstream ss;
        string output="";
        if(integer==0)
        {
          if(flagPorN==1)
          {
            output+="0.";
          }else
          {
            output+="-0.";
          }
          ss<<output;
        }else
        {
          integer*=flagPorN;
          ss<<integer;
          //output=ss.str();
          //output+=".";
          ss<<".";
        }
        //append fraction part;
        for(int i=0;i<result.size();i++)
        {
          ss<<result[i];
        }
        return ss.str();
      }
    }
};
