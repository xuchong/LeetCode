#include<iostream>
#include<list>
#include<vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
          return result;
        list<TreeNode*> data,tmp;
        int flag=1;//0 left->right, 1 right->left
        data.push_back(root);
        while(!data.empty())
        {
          tmp.clear();
          vector<int>item;

          //遍历每层
          while(!data.empty())
          {
            if(!flag)
            {
              item.push_back(data.back()->val);
              if(data.back()->right!=NULL)
                tmp.push_front(data.back()->right);
              if(data.back()->left!=NULL)
                tmp.push_front(data.back()->left);
              data.pop_back();
            }else
            {
              item.push_back(data.front()->val);
              if(data.front()->left!=NULL)
                tmp.push_back(data.front()->left);
              if(data.front()->right!=NULL)
                tmp.push_back(data.front()->right);
              data.pop_front();
            }
          }
          if(!item.empty())
            result.push_back(item);
          data=tmp;
          flag=1-flag;
        }
        return result;
    }
};
