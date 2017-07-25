#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
vector<vector<string>> result;
bool isDiffOne(string&a ,string& b)
{
  int i=0;
  int count=0;
  while(i<a.length()&&count<2)
  {
    if(a[i]!=b[i])
      count++;
  }
  if(count==1)
    return true;
  return false;
}
void recursive(vector<string>&wordList,string& endWord,vector<string> item)
{
    for(vector<string>::iterator j=wordList.begin();j!=wordList.end();)
    {
      if(isDiffOne(item[item.size()-1],*j))
      {
        if(*j==endWord)
        {
          item.push_back(*j);
          result.push_back(item);
        }else{
          item.push_back(*j);
          j=wordList.erase(j);
          recursive(wordList,endWord,item);
        }
      }else
      {
        j++;
      }
    }
}
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
      if(beginWord.empty())
        return result;
      vector<string>item;
      item.push_back(beginWord);
      recursive(wordList,endWord,item);
      return result;
    }
};
int main()
{
  return 0;
}
