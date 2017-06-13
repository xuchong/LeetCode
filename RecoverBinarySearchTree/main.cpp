#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){};
};
// one important thing:  BST 的中序遍历是 递增的序列。
class Solution
{
private:
	TreeNode* first=NULL, *second=NULL;
	TreeNode* pre=NULL;
	void check(TreeNode* root)
	{
		if (root == NULL)
			return;
		TreeNode* left = root->left;
		if (left != NULL)
			check(left);
		//this is an error node!
		if (pre != NULL&&pre->val > root->val)
		{
			if (first == NULL){
				first = pre;
				second = root;
			}
			else
				second = root;
		}
		pre = root; 

		TreeNode* right = root->right;
		if (right != NULL)
			check(right);
	}
public:
	void recoverTree(TreeNode* root) {
		check(root);
		//swap first and second
		int tmp;
		tmp = first->val;
		first->val = second->val;
		second->val = tmp;
	}
};
int main()
{
	return 0;
}