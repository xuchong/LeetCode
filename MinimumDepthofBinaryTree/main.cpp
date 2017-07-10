#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//#define RECURSIVE
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
// 分层遍历
class Solution
{
public:
  int minDepth(TreeNode* root) {
      int height=0;
      vector<TreeNode*>data,tmp;
      if(root==NULL)
        return height;
      data.push_back(root);
      height=1;
      while(data.size()>0)
      {
        tmp.clear();
        //iterator layer
        while(data.size()>0)
        {
          if(data.back()->left==NULL&&data.back()->right==NULL)
            return height;
          else if(data.back()->left==NULL)
          {
            tmp.push_back(data.back()->right);
          }else if(data.back()->right==NULL)
          {
            tmp.push_back(data.back()->left);
          }else{
            tmp.push_back(data.back()->right);
            tmp.push_back(data.back()->left);
          }
          data.pop_back();
        }
        height++;
        data.swap(tmp);
      }
      return height;
    }
};
int main()
{
  return 0;
}
