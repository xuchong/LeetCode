struct Tree{
  bool isStr;
  int h;
  Tree* next[26];
  Tree():isStr(false),h(0){
    memset(next,NULL,sizeof(next));
  }
};
class WordDictionary {
private:
  Tree* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
      root=new Tree();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
      Tree* item=root;
      int i=0;
      while(i<word.length())
      {
        if(item->next[word[i]-'a']==NULL)
        {
          item->next[word[i]-'a']=new Tree();
          item->next[word[i]-'a']->h=item->h+1;
          item=item->next[word[i]-'a'];
        }else
        {
          item=item->next[word[i]-'a'];
        }
        i++;
      }
      item->isStr=true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
      Tree* item;
      vector<Tree*> layer;
      layer.push_back(root);
      while(!layer.empty())
      {
        item=layer.back();
        if(item->h==word.size()&&item->isStr)
          return true;
        else if(item->h>=word.size())
        {
          layer.pop_back();
          continue;
        }
        layer.pop_back();
        if(word[item->h]!='.'){
          if(item->next[word[item->h]-'a']==NULL)
          {
            return false;
          }else
          {
            item=item->next[word[item->h]-'a'];
            layer.push_back(item);
          }
        }else
        {
          for(int i=0;i<26;i++)
          {
            if(item->next[i]!=NULL)
            {
              layer.push_back(item->next[i]);
            }
          }
        }
      }
      return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
