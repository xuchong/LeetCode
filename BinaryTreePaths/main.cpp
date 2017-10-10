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
  vector<string> paths;
  void recursive(TreeNode* root,string path)
  {
    if(root==NULL)
      return;
    stringstream ss;
    ss<<root->val;
    if(path.empty())
    {
      path=ss.str();
    }else
    {
      path=path+"->"+ss.str();
    }
    if(root->left==NULL&&root->right==NULL)
    {
      paths.push_back(path);
      return;
    }else
    {
      recursive(root->left,path);
      recursive(root->right,path);
    }
  }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
      paths.clear();
      string path;
      recursive(root,path);
      return paths;
    }
};
