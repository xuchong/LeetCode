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
private:
	  void recurisve(TreeNode* root,int sum,vector<vector<int>>&result,vector<int>item,int subsum)
		{
			if(root==NULL)
				return;
			if(root->left==NULL&&root->right==NULL)
			{
				if(subsum+root->val==sum){
					item.push_back(root->val);
					result.push_back(item);
				}
			}else if(root->left==NULL)
			{
				item.push_back(root->val);
				recurisve(root->right,sum,result,item,subsum+root->val);
			}else if(root->right==NULL)
			{
				item.push_back(root->val);
				recurisve(root->left,sum,result,item,subsum+root->val);
			}else
			{
				item.push_back(root->val);
				recurisve(root->left,sum,result,item,subsum+root->val);
				recurisve(root->right,sum,result,item,subsum+root->val);
			}
		}
public:
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>result;
				if(!root)
					return result;
				vector<int>item;
				recurisve(root,sum,result,item,0);
				return result;
    }
};
int main()
{
    return 0;
}
