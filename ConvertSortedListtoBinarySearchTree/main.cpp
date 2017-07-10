#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
    private:
        TreeNode* recursive(ListNode* &head,int length)
        {
            TreeNode* root=NULL;
            if(head==NULL||length==0)
                return root;
            TreeNode* left=recursive(head,length/2);
            root=new TreeNode(head->val);
            head=head->next;
            TreeNode* right=recursive(head,(length-1)/2);
            root->left=left;
            root->right=right;
            return root;
        }
    public:
        TreeNode* sortedListToBST(ListNode* head) {
            int length=0;
            ListNode* tmp=head;
            while(tmp!=NULL)
            {
                length++;
                tmp=tmp->next;
            }
            return recursive(head,length);
        }
};

void testNext(ListNode* &root)
{
    root=root->next;
    cout<<root->val<<endl;
}

int main()
{
    ListNode *root=new ListNode(1);
    root->next=new ListNode(2);
    cout<<root->val<<endl;
    testNext(root);
    cout<<root->val<<endl;
    return 0;
}
