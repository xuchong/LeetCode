//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(root==NULL)
          return result;
        list<TreeNode*> layer;
        TreeNode* item;
        layer.push_back(root);
        layer.push_back(NULL);
        while(!layer.empty())
        {
          item=layer.front();
          layer.pop_front();
          if(item==NULL&&layer.size()>=1)
          {
            layer.push_back(NULL);
          }else if(item!=NULL)
          {
            if(item->left!=NULL)
              layer.push_back(item->left);
            if(item->right!=NULL)
              layer.push_back(item->right);
          }
          if(!layer.empty()&&layer.front()==NULL)
          {
            result.push_back(item->val);
          }
        }
        return result;
    }
};
