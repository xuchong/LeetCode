#include<iostream>
#include<vector>
#include<queue>
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
  vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
          return result;
        queue<TreeNode*> data,tmp;
        data.push(root);
        while(!data.empty())
        {
          vector<int> item;
          tmp.swap(queue<TreeNode*>())
          //遍历每一层
          while(!data.empty())
          {
            if(data.front()!=NULL)
            {
              item.push_back(data.front()->val);
              tmp.push(data.front()->left);
              tmp.push(data.front()->right);
            }
            data.pop();
          }
          if(!item.empty())
            result.push_back(item);
          data.swap(tmp);
        }
        return result;
    }
};

int main()
{

  return 0;
}
