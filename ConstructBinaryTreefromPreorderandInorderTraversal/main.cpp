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
class Solution {
private:
    TreeNode* build(vector<int> preorder,int sp,int lenp,vector<int> inorder,int si,int leni)
    {
      TreeNode* root=NULL;
      if(lenp==0||lenp!=leni)
        return root;
      root=new TreeNode(preorder[sp]);
      int index=find(inorder.begin()+si,inorder.begin()+si+leni,preorder[sp])-inorder.begin();

      //inorder sequence
      // vector<int> in_left(inorder.begin(),index);
      // vector<int> in_right(index+1,inorder.end());
      int in_left_start=si;
      int in_left_len=index-si;
      int in_right_start=index+1;
      int in_right_len=si+leni-index-1;
      // //preorder sequence
      // vector<int> pre_left(preorder.begin()+1,preorder.begin()+in_left.size()+1);
      // vector<int> pre_right(preorder.begin()+in_left.size()+1,preorder.end());
      int pre_left_start=sp+1;
      int pre_left_len=in_left_len;
      int pre_right_start=sp+1+in_left_len;
      int pre_right_len=in_right_len;
      root->left=build(preorder,sp+1,index-si,inorder,si,index-si);
      root->right=build(preorder,index-si+sp+1,lenp-(index-si+1),inorder,index+1,si+leni-index-1);
      return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      return build(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};

int main()
{
  return 0;
}
