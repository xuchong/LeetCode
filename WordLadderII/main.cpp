#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

// 不考虑空间，(BFS + DFS)!!  hardest one!
class Solution {
private:
vector<vector<string> > result;
private:
  void DFS(unordered_map<string,vector<string>>&layers,unordered_map<string,int>& heights,vector<string>item,string start,string end)
  {
    if(start==end)
    {
      item.push_back(end);
      result.push_back(item);
      return;
    }
    if(layers.find(start)==layers.end())
      return;
    item.push_back(start);
    for(int i=0;i<layers[start].size();i++)
    {
      if(heights[layers[start][i]]==heights[start]+1)
        DFS(layers,heights,item,layers[start][i],end);
    }
  }

public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
      if(beginWord.empty())
        return result;
      unordered_set<string> dict(wordList.begin(),wordList.end());
      if(dict.find(endWord)==dict.end())
        return result;
      unordered_map<string,vector<string>> layers;
      unordered_map<string,int> heights;
      queue<string> layer;
      //queue<vector<string> > path;
      layer.push(beginWord);
      heights[beginWord]=0;
      //vector<string> item;
      //item.push_back(beginWord);
      //path.push(item);

      string node,tmp;
      //遍历每一层
      while(!layer.empty())
      {
        node=layer.front();
        layer.pop();
        if(node==endWord)
          break;
        if(layers.find(node)==layers.end())
          layers[node]=vector<string>();
        else
          continue;
        for(int i=0;i<node.length();i++){
          tmp=node;
          for(char j='a';j<='z';j++)
          {
            if(tmp[i]==j)
              continue;
            tmp[i]=j;
            if(dict.find(tmp)!=dict.end()&&layers.find(tmp)==layers.end())
            {
              layer.push(tmp);
              if(heights.find(tmp)==heights.end())
                heights[tmp]=heights[node]+1;
              layers[node].push_back(tmp);
            }
          }
        }
      }
     // for(unordered_map<string,vector<string>>::iterator it=layers.begin();it!=layers.end();it++)
     // {
     //  cout<<"key: "<<it->first<<endl;
     //  for(int i=0;i<it->second.size();i++)
     //  {
     //      cout<<it->second[i]<<" ";
     //  }
     //  cout<<endl;
     // }
      // DFS for path
      vector<string> path;
      DFS(layers,heights,path,beginWord,endWord);
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
