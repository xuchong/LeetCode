#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
	void recursive(TreeNode* tree, int shift)
	{
		if (tree != NULL)
		{
			tree->val += shift;
			recursive(tree->left, shift);
			recursive(tree->right, shift);
		}
	}
	vector<TreeNode*> makeTree(vector<TreeNode*> total, int shift)
	{
		vector<TreeNode*> out;
		TreeNode*result;
		if (shift == 0)
			return total;
		for (int i = 0; i < total.size(); i++)
		{
			result = total[i];
			recursive(result, shift);
			out.push_back(result);
		}
		return out;
	}
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode *> total;
		vector<vector<TreeNode*>> a;
		vector<TreeNode*> item,leftitem,rightitem;
		TreeNode* first = new TreeNode(1);
		item.push_back(first);
		a.push_back(item);
		a.push_back(item);
		int i,j,k,l;
		for ( i = 2; i <= n; i++)
		{
			item.clear();
			for (j = 0; j < i; j++)
			{
				leftitem.clear();
				rightitem.clear();
				//left
				if (j>0)
				{
					leftitem = makeTree(a[j], 0);
				}
				//right
				if (j < i - 1)
				{
					rightitem = makeTree(a[i - j - 1], j + 1);
				}
				//mix left and right
				if (leftitem.size() == 0)
				{
					for (k = 0; k < rightitem.size(); k++)
					{
						TreeNode* tmp = new TreeNode(j + 1);
						tmp->right = rightitem[k];
						item.push_back(tmp);
					}
				}
				else if (rightitem.size() == 0)
				{
					for (k = 0; k < leftitem.size(); k++)
					{
						TreeNode* tmp = new TreeNode(j + 1);
						tmp->left = leftitem[k];
						item.push_back(tmp);
					}
				}
				else{
					for (k = 0; k < leftitem.size(); k++)
					{
						for (l = 0; l < rightitem.size(); l++){
							TreeNode* tmp = new TreeNode(j + 1);
							tmp->left = leftitem[k];
							tmp->right = rightitem[l];
							item.push_back(tmp);
						}
					}
				}
			}
			a.push_back(item);
		}
		return a[n];
	}
};
int main()
{
	Solution s;
	int n;
	while (true)
	{
		cin >> n;
		s.generateTrees(n);
	}
	return 0;
}