struct Tree{
  bool isStr;
  Tree* next[26];
  Tree():isStr(false){
    memset(next,NULL,sizeof(next));
  }
};
class Trie {
private:
  Tree* root;
public:
    /** Initialize your data structure here. */
    Trie() {
      root=new Tree();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      Tree* node=root;
      int i=0;
      while(i<word.length())
      {
        if(node->next[word[i]-'a']==NULL)
        {
          node->next[word[i]-'a']=new Tree();
        }
        node=node->next[word[i]-'a'];
        i++;
      }
      if(node!=NULL)
      {
        node->isStr=true;
      }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      Tree* node=root;
      int i=0;
      while(i<word.length())
      {
        if(node->next[word[i]-'a']==NULL)
        {
          return false;
        }
        node=node->next[word[i]-'a'];
        i++;
      }
      if(node!=NULL&&node->isStr)
        return true;
      else
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      Tree* node=root;
      int i=0;
      while(i<prefix.length())
      {
        if(node->next[prefix[i]-'a']==NULL)
        {
          return false;
        }
        node=node->next[prefix[i]-'a'];
        i++;
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
