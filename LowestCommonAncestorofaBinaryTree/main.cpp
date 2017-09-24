/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
private:
  bool recursive(TreeNode* root,TreeNode* p,vector<TreeNode*>& result)
  {
    if(root==p)
    {
      result.push_back(root);
      return true;
    }
    if(root==NULL)
    {
      return false;
    }
    result.push_back(root);
    bool r=recursive(root->left,p,result);
    if(!r)
    {
      r=recursive(root->right,p,result);
    }
    if(!r)
    {
      result.pop_back();
    }
    return r;
  }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      vector<TreeNode*> p1,q1;
      recursive(root,p,p1);
      recursive(root,q,q1);
      int i;
      for(i=0;i<p1.size()&&i<q1.size();i++)
      {
        if(p1[i]!=q1[i])
          break;
      }
      return p1[i-1];
    }
};
