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
        TreeNode* recursive(vector<int>& nums,int start,int length)
        {
            TreeNode* root=NULL;
            if(length==0)
                return NULL;
            //left
            int left_start=start;
            int left_length=length/2;
            //right
            int right_start=start+left_length+1;
            int right_length=(length-1)/2;
            root=new TreeNode(nums[start+left_length]);
            root->left=recursive(nums,left_start,left_length);
            root->right=recursive(nums,right_start,right_length);
            return root;
        }
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return recursive(nums,0,nums.size());
        }
};
