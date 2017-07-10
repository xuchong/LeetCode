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
class Solution
{
public:
  bool hasPathSum(TreeNode* root, int sum) {
        bool result=false;
        if(root==NULL)
          return result;
        vector<TreeNode*>data,tmp;
        data.push_back(root);
        while(data.size()>0)
        {
          tmp.clear();
          //分层遍历
          while(data.size()>0)
          {
            if(data.back()->left!=NULL&&data.back()->right!=NULL)
            {
              tmp.push_back(data.back()->left);
              tmp.back()->val+=data.back()->val;
              tmp.push_back(data.back()->right);
              tmp.back()->val+=data.back()->val;
            }
            if(data.back()->left!=NULL)
            {
              tmp.push_back(data.back()->left);
              tmp.back()->val+=data.back()->val;
            }else if(data.back()->right!=NULL)
            {
              tmp.push_back(data.back()->right);
              tmp.back()->val+=data.back()->val;
            }else{
              if(data.back()->val==sum)
                return true;
            }
            data.pop_back();
          }
          //data.swap(tmp);
          data=tmp;
        }
        return result;
    }
};
int main()
{
  return 0;
}
