#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//#define RECURSIVE
struct TreeNode{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
#ifdef RECURSIVE
class Solution {
private:
	void recursive(vector<int> &result, TreeNode* root)
	{
		if (root != NULL)
		{
			recursive(result, root->left);
			result.push_back(root->val);
			recursive(result, root->right);
		}
	}
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>result;
		recursive(result, root);
		return result;
	}
};
#else
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>result;
		stack<TreeNode*> a;
		if (root == NULL)
			return result;
		a.push(root);
		TreeNode* item,*left,*right;
		while (a.size() > 0)
		{
			item = a.top();
			left = item->left;
			right = item->right;
			item->left = NULL;
			item->right=NULL;
			if (right != NULL)
			{
				a.pop();
				a.push(right);
				a.push(item);
			}
			if (left != NULL)
			{
				a.pop();
				a.push(item);
				a.push(left);
			}
			if (left==NULL&&right==NULL)
			{
				result.push_back(item->val);
				a.pop();
			}
		}

		return result;
	}
};
#endif
int main()
{
	Solution s;
	return 0;
}