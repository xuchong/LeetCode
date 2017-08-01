#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
using namespace std;

// 不考虑空间，BFS
class Solution {
private:
vector<vector<string> > result;
bool isDiffOne(string&a ,string& b)
{
  int i=0;
  int count=0;
  while(i<a.length()&&count<2)
  {
    if(a[i]!=b[i])
      count++;
    i++;
  }
  if(count==1)
    return true;
  return false;
}

public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
      if(beginWord.empty())
        return result;
      queue<string> layer,newlayer;
      queue<vector<string> > path,newpath;
      layer.push(beginWord);
      vector<string> item;
      item.push_back(beginWord);
      path.push(item);

      //clear
      vector<int> index(wordList.size(),0),newindex(wordList.size(),0);

      while(result.empty()&&!layer.empty())
      {
        //遍历每一层
        queue<string>().swap(newlayer);
        queue<vector<string> >().swap(newpath);
        index=newindex;
        while(!layer.empty())
        {
          for(vector<string>::iterator it=wordList.begin();it!=wordList.end();)
          {
            if(index[it-wordList.begin()])
              continue;
            if(isDiffOne(*it,layer.front()))
            {
              newlayer.push(*it);
              newpath.push(path.front());
              newpath.back().push_back(*it);
              if(*it==endWord)
              {
                result.push_back(newpath.back());
              }
              newindex[it-wordList.begin()]=1;
            }
            it++;
          }
          layer.pop();
          path.pop();
        }
        layer.swap(newlayer);
        path.swap(newpath);
      }
      return result;
    }
};
/*
qa
sq
si   go   se   cm   so   ph   mt   db   mb   sb   kr   ln   tm   le   av   sm   ar   ci   ca   br   ti   ba   to   ra   fa   yo   ow   sn   ya   cr   po   fe   ho   ma   re   or   rn   au   ur   rh   sr   tc   lt   lo   as   fr   nb   yb   if   pb   ge   th   pm   rb   sh   co   ga   li   ha   hz   no   bi   di   hi   qa   pi   os   uh   wm   an   me   mo   na   la   st   er   sc   ne   mn   mi   am   ex   pt   io   be   fm   ta   tb   ni   mr   pa   he   lr   sq   ye
*/
int main()
{
  string beginWord,endWord,tmp;
  std::vector<string> wordList;
  ifstream in("data");
  in>>beginWord>>endWord;
  while(!in.eof())
  {
    in>>tmp;
    if(in.peek()==EOF)
    {
      break;
    }
    wordList.push_back(tmp);
  }

  Solution s;
  s.findLadders(beginWord,endWord,wordList);

  return 0;
}
