#include<iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL){}
};
class Solution
{
private:
	bool check(TreeNode* p,TreeNode* q)
	{
		if (p == q&&p == NULL)
			return true;
		if (p == NULL || q == NULL)
			return false;
		if (p->val == q->val)
		{
			return check(p->left, q->left) && check(p->right, q->right);
		}
		else
		{
			return false;
		}
	}
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		return check(p, q);
	}
};
int main()
{

	return 0;
}