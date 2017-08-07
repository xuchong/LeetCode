#include<iostream>
#include<vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> result;
      if(root==NULL)
        return result;
      vector<TreeNode*> stack;
      TreeNode* tmp;
      stack.push_back(root);
      while(!stack.empty())
      {
        tmp=stack.back();
        stack.pop_back();
        result.push_back(tmp->val);
        if(tmp->right!=NULL)
        {
          stack.push_back(tmp->right);
        }
        if(tmp->left!=NULL)
        {
          stack.push_back(tmp->left);
        }
      }
      return result;
    }
};
