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
private:
  void recursive(TreeNode* root)
  {
    if(root==NULL)
      return;
    TreeNode* item=root->left;
    root->left=root->right;
    root->right=item;
    recursive(root->left);
    recursive(root->right);
  }
public:
    TreeNode* invertTree(TreeNode* root) {
      recursive(root);
      return root;
    }
};
