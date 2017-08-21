//#define RECURSIVE
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
class BSTIterator {
private:
  vector<TreeNode*> list;
public:
    BSTIterator(TreeNode *root) {
      while(root!=NULL)
      {
        list.push_back(root);
        root=root->left;
      }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      if(list.empty())
        return false;
      else
        return true;
    }

    /** @return the next smallest number */
    int next() {
      TreeNode* result;
      if(list.back()->left==NULL&&list.back()->right==NULL)
      {
        result=list.back();
        list.pop_back();
      }else if(list.back()->left!=NULL&&list.back()->right!=NULL)
      {
        result=list.back();
        list.pop_back();
        TreeNode *tmp=result->right;
        while(tmp!=NULL)
        {
          list.push_back(tmp);
          tmp=tmp->left;
        }
      }else if(list.back()->left!=NULL)
      {
        result=list.back();
        list.pop_back();
      }else
      {
        result=list.back();
        list.pop_back();
        TreeNode *tmp=result->right;
        while(tmp!=NULL)
        {
          list.push_back(tmp);
          tmp=tmp->left;
        }
      }
      return result->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
