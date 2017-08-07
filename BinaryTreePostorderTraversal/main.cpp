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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int>result;
    if(root==NULL)
      return result;
    vector<TreeNode*> stack;
    TreeNode* tmp,*l,*r;
    stack.push_back(root);
    while(!stack.empty())
    {
      tmp=stack.back();
      stack.pop_back();
      if(tmp->right==NULL&&tmp->left==NULL)
      {
        result.push_back(tmp->val);
      }else if(tmp->right!=NULL&&tmp->left!=NULL)
      {
        r=tmp->right;
        l=tmp->left;
        tmp->right=NULL;
        tmp->left=NULL;
        stack.push_back(tmp);
        stack.push_back(r);
        stack.push_back(l);
      }else if(tmp->left!=NULL)
      {
        l=tmp->left;
        tmp->left=NULL;
        stack.push_back(tmp);
        stack.push_back(l);
      }else
      {
        r=tmp->right;
        tmp->right=NULL;
        stack.push_back(tmp);
        stack.push_back(r);
      }
    }
    return result;
  }
};
