#include<iostream>
#include<vector>
#include<math>
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
int getHeight(TreeNode* root)
{
	int h=0;
	if(root==NULL)
		return h;
	int lh=getHeight(root->left);
	int rh=getHeight(root->right);
	if(lh==-1||rh==-1||abs(lh-rh)>1)
		return -1;
	h=max(lh,rh)+1;
	return h;
}
public:
bool isBalanced(TreeNode* root) {
	if(getHeight(root)==-1)
		return false;
	else
		return true;
}
};
int main()
{
	return 0;
}
