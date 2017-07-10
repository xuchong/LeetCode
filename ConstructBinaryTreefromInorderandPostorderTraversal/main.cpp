#include<iostream>
#include<vector>
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
  TreeNode* build(vector<int>& inorder,int istart,int ilen,vector<int>&postorder,int pstart,int plen)
  {
    TreeNode* root=NULL;
    if(ilen==0||ilen!=plen)
      return root;
    root=new TreeNode(postorder[pstart+plen-1]);
    int index=find(inorder.begin()+istart,inorder.begin()+istart+ilen,root->val)-inorder.begin();
    //left inorder start
    int left_in_start=istart;
    int left_in_length=index-istart;
    //right inorder start
    int right_in_start=index+1;
    int right_in_length=istart+ilen-index-1;
    //left postorder start
    int left_post_start=pstart;
    int left_post_length=left_in_length;
    //right postorder start
    int right_post_start=pstart+index-istart;
    int right_post_length=right_in_length;
    //buiding TreeNode
    root->left=build(inorder,left_in_start,left_in_length,postorder,left_post_start,left_post_length);
    root->right=build(inorder,right_in_start,right_in_length,postorder,right_post_start,right_post_length);
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      return build(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
};
int main()
{
  return 0;
}
