#include<iostream>
#include<algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
private:
  void recursive(TreeNode* root,TreeNode*& last)
  {
    if(root==NULL)
      return;
    if(last==NULL)
      last=root;
    else{
      last->left=root;
      last=root;
    }
    recursive(root->left,last);
    recursive(root->right,last);
  }
public:
  void flatten(TreeNode* root) {
      recursive(root,NULL);
    }
};
int main()
{
  return 0;
}
