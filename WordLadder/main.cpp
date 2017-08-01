#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      if(beginWord==endWord)
        return 1;
      unordered_set<string> dict(wordList.begin(),wordList.end()),layers;
      if(dict.find(endWord)==dict.end())
        return 0;
      queue<string> layer,newlayer;
      layer.push(beginWord);
      layers.insert(beginWord);
      int result=1;
      string item,tmp;
      while(!layer.empty())
      {
        //each layer
        queue<string>().swap(newlayer);
        while(!layer.empty())
        {
          item=layer.front();
          layer.pop();
          for(int i=0;i<item.length();i++)
          {
            tmp=item;
            for(char ch='a';ch<='z';ch++)
            {
              if(tmp[i]==ch)
                continue;
              tmp[i]=ch;
              if(tmp==endWord)
              {
                result++;
                return result;
              }
              if(dict.find(tmp)!=dict.end()&&layers.find(tmp)==layers.end())
              {
                newlayer.push(tmp);
                layers.insert(tmp);
              }
            }
          }
        }
        result++;
        layer.swap(newlayer);
      }
      return 0;
    }
};
int main()
{
  return 0;
}
