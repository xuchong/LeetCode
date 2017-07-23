#include<iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    int result;
    void recursive(TreeNode* root, int& withroot,int& withoutroot)
    {
      if(root==NULL)
      {
        withroot=INT_MIN/2;
        withoutroot=INT_MIN/2;
        return;
      }
      int a,b;
      recursive(root->left,a,b);
      // joint
      int withroot_left=max(a+root->val,root->val);
      // not joint
      int withoutroot_left=max(b,root->val);
      int c,d;
      recursive(root->right,c,d);
      // joint
      int withroot_right=max(c+root->val,root->val);
      // not joint
      int withoutroot_right=max(d,root->val);
      withroot=max(withroot_left,withroot_right);
      withoutroot=max(withoutroot_left,withoutroot_right);
      result=max(result,withroot);
      result=max(result,withoutroot);
      result=max(result,a+c+root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
      result=INT_MIN;
      int withroot,withoutroot;
      recursive(root,withroot,withoutroot);
      return result;
    }
};
int int main(int argc, char const *argv[]) {
  return 0;
}
