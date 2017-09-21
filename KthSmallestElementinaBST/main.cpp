/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
      TreeNode* p=root;
      vector<TreeNode*> stack;
      stack.push_back(p);
      while(p->left!=NULL)
      {
        stack.push_back(p->left);
        p=p->left;
      }
      int count=0;
      while(!stack.empty())
      {
        p=stack.back();
        stack.pop_back();
        count++;
        if(count==k)
          return p->val;
        if(p->right!=NULL)
        {
          stack.push_back(p->right);
          p=p->right;
          while(p->left!=NULL)
          {
            stack.push_back(p->left);
            p=p->left;
          }
        }
      }
    }
};
