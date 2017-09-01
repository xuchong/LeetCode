#define TL
#ifndef TL
class Solution {
private:
  bool isInclude(vector<vector<char>>&board,vector<vector<char>>&copy,string word,int index,int m,int n)
  {
      if(index>=word.length()||copy[m][n]=='#'||board[m][n]!=word[index])
      {
        return false;
      }
      if(index==word.length()-1)
        return true;
      bool result=false;
      //four
      copy[m][n]='#';
      if(m-1>=0)
      {
        result+=isInclude(board,copy,word,index+1,m-1,n);
      }
      if(m+1<board.size())
      {
        result+=isInclude(board,copy,word,index+1,m+1,n);
      }
      if(n-1>=0)
      {
        result+=isInclude(board,copy,word,index+1,m,n-1);
      }
      if(n+1<board[0].size())
      {
        result+=isInclude(board,copy,word,index+1,m,n+1);
      }
      copy[m][n]=board[m][n];
      return result;
  }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      vector<string> result;
      if(board.empty()||words.empty())
        return result;
      vector<vector<string>> startsWith(26,vector<string>());
      string word;
      for(int i=0;i<words.size();i++)
      {
        word=words[i];
        startsWith[word[0]-'a'].push_back(word);
      }
      unordered_set<string> result_set;
      vector<vector<char>> copy_board(board);
      // traversal the board
      for(int i=0;i<board.size();i++)
      {
        for(int j=0;j<board[0].size();j++)
        {
          if(startsWith[board[i][j]-'a'].size()>0)
          {
            for(auto it=startsWith[board[i][j]-'a'].begin();it!=startsWith[board[i][j]-'a'].end();it++){
              if(result_set.find(*it)==result_set.end())
              {
                if(isInclude(board,copy_board,*it,0,i,j))
                {
                  result_set.insert(*it);
                }
              }
            }
          }
        }
      }
      result.insert(result.end(),result_set.begin(),result_set.end());
      return result;
    }
};
#else
// This is method about tie. why is faster?
struct Trie
{
  string word;
  Trie* next[26];
  Trie():word(""){
    memset(next,NULL,sizeof(next));
  }
};
class Solution {
private:
  unordered_set<string> result_set;
  void recursive(vector<vector<char>>&board,Trie* root,int m,int n)
  {
      Trie* next=root->next[board[m][n]-'a'];
      if(board[m][n]=='#'||next==NULL)
      {
        return ;
      }
      if(next->word!=""){
        result_set.insert(next->word);
      }
      //four
      char tmp=board[m][n];
      board[m][n]='#';
      if(m-1>=0)
      {
        recursive(board,next,m-1,n);
      }
      if(m+1<board.size())
      {
        recursive(board,next,m+1,n);
      }
      if(n-1>=0)
      {
        recursive(board,next,m,n-1);
      }
      if(n+1<board[0].size())
      {
        recursive(board,next,m,n+1);
      }
      board[m][n]=tmp;
  }
void buildTrie(Trie* root,vector<string>& words)
{
  string item;
  int index;
  Trie* p;
  for(int i=0;i<words.size();i++)
  {
    item=words[i];
    index=0;
    p=root;
    while(index<item.length())
    {
      if(p->next[item[index]-'a']==NULL)
      {
        p->next[item[index]-'a']=new Trie();
      }
      p=p->next[item[index]-'a'];
      index++;
    }
    p->word=item;
  }
}
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      vector<string> result;
      if(board.empty()||words.empty())
        return result;
      Trie* root=new Trie();
      buildTrie(root,words);
      for(int i=0;i<board.size();i++)
      {
        for(int j=0;j<board[0].size();j++)
        {
          recursive(board,root,i,j);
        }
      }
      result.insert(result.end(),result_set.begin(),result_set.end());
      return result;
    }
};
#endif
