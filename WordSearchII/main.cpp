class Solution {
private:
  bool isInclude(vector<vector<char>>&board,vector<vector<char>>&copy,vector<int> word,int m,int n)
  {
      if(copy[m][n]=='#'||word[board[m][n]-'a']==0)
      {
        return false;
      }else
      {
        word[board[m][n]-'a']--;
      }
      bool result=true;
      for(int i=0;i<word.size();i++)
      {
        if(word[i]!=0)
        {
          result=false;
          break;
        }
      }
      if(result)
        return result;
      //four
      copy[m][n]='#';
      if(m-1>=0)
      {
        result+=isInclude(board,copy,word,m-1,n);
      }
      if(m+1<board.size())
      {
        result+=isInclude(board,copy,word,m+1,n);
      }
      if(n-1>=0)
      {
        result+=isInclude(board,copy,word,m,n-1);
      }
      if(n+1<board[0].size())
      {
        result+=isInclude(board,copy,word,m,n+1);
      }
      copy[m][n]=board[m][n];
      return result;
  }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      vector<string> result;
      if(board.empty()||words.empty())
        return result;
      vector<unordered_map<string,vector<int>>> startsWith(26,unordered_map<string,vector<int>>());
      string word;
      for(int i=0;i<words.size();i++)
      {
        word=words[i];
        startsWith[word[0]-'a'][word]=vector<int>(26,0);
        for(int j=0;j<word.length();j++)
        {
          startsWith[word[0]-'a'][word][word[j]-'a']++;
        }
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
              if(result_set.find(it->first)==result_set.end())
              {
                if(isInclude(board,copy_board,it->second,i,j))
                {
                  result_set.insert(it->first);
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
