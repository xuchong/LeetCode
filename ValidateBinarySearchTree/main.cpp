#include<iostream>
using namespace std;
#define NOT_WORK
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){};
};
#ifndef NOT_WORK
class Solution
{
private:
	bool recursive(TreeNode* root,int flag,int father,int n,int m)
	{
		if (root == NULL)
			return true;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		if (left != NULL&& right != NULL)
		{
			if (left->val < root->val&&root->val < right->val)
			{
				if (flag == 0 && right->val >= n)
					return false;
				if (flag == 1 && left->val <= n)
					return false;
				if (father == 0 && right->val >= m)
					return false;
				if (father == 1 && left->val <= m)
					return false;
				if (father==-1)
					return recursive(left, 0, 0, root->val, root->val) && recursive(right, 1, 1, root->val, root->val);
				else
					return recursive(left, 0, father, root->val, m) && recursive(right, 1, father, root->val, m);
			}
			else
				return false;
		}
		else if (left != NULL&&right == NULL)
		{
			if (left->val < root->val)
			{
				if (flag == 1 && left->val <= n)
					return false;
				if (father == 1 && left->val <= m)
					return false;
				if (father==-1)
					return recursive(left,0,0,root->val,root->val);
				else
					return recursive(left, 0, father, root->val, m);
			}
			else
				return false;
		}
		else if (right != NULL&& left == NULL)
		{
			if (right->val > root->val)
			{
				if (flag == 0 && right->val >= n)
					return false;
				if (father == 0 && right->val >= m)
					return false;
				if (father == -1)
					return recursive(right,1,1,root->val,root->val);
				else
					return recursive(right, 1, father, root->val, m);
			}
			else
				return false;
		}
		else
			return true;
	}
public:
	bool isValidBST(TreeNode* root) {
		return recursive(root,-1,-1,0,0);
	}
};
#else
class Solution
{
private:
	bool recursive(TreeNode* root,long less,long more)
	{
		if (root == NULL)
			return true;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		if (root->val <= less || root->val >= more)
			return false;

		if (left != NULL&& right != NULL)
		{
			if (left->val < root->val&&root->val < right->val)
			{
				return recursive(left, less, root->val) && recursive(right, root->val, more);
			}
			else
				return false;

		}
		else if (left != NULL&&right == NULL)
		{
			if (left->val < root->val)
			{
				return recursive(left, less, root->val) ;
			}
			else
				return false;
		}
		else if (right != NULL&& left == NULL)
		{
			if (right->val > root->val)
			{
				return  recursive(right, root->val, more);
			}
			else
				return false;
		}
		else
			return true;
	}
public:
	bool isValidBST(TreeNode* root) {
		return recursive(root, LONG_MIN, LONG_MAX);
	}
};
#endif
int main()
{
	TreeNode *root=new TreeNode(3);
	TreeNode *left=new TreeNode(1);
	TreeNode *right = new TreeNode(5);
	root->left = left;
	root->right = right;
	left = new TreeNode(0); right = new TreeNode(2);
	root->left->left = left;
	root->left->right = right;
	right = new TreeNode(3);
	root->left->right->right = right;
	Solution s;
	cout << s.isValidBST(root) << endl;
	return 0;
}