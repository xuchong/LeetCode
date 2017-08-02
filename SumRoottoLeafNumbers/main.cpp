#include<iostream>
#include<queue>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int result=0;
        if(root==NULL)
          return result;
        queue<TreeNode*> layer;
        queue<int> value;
        layer.push(root);
        value.push(root->val);
        while(!layer.empty())
        {
          if(layer.front()->left==NULL&&layer.front()->right==NULL)
          {
            result+=value.front();
          }else if(layer.front()->right==NULL)
          {
            layer.push(layer.front()->left);
            value.push(value.front()*10+layer.front()->left->val);
          }else if(layer.front()->left==NULL)
          {
            layer.push(layer.front()->right);
            value.push(value.front()*10+layer.front()->right->val);
          }else
          {
            layer.push(layer.front()->left);
            value.push(value.front()*10+layer.front()->left->val);
            layer.push(layer.front()->right);
            value.push(value.front()*10+layer.front()->right->val);
          }
          layer.pop();
          value.pop();
        }
        return result;
    }
};
int main()
{
  return 0;
}
