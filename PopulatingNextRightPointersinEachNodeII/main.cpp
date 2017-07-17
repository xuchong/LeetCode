#include<iostream>
//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode*s,*p,*r,*l;
        p=root;
        while(p!=NULL)
        {
          //each layer
          //find first val
          s=NULL;
          while(p!=NULL){
            if(p->left!=NULL)
            {
              s=p->left;
              break;
            }
            if(p->right!=NULL)
            {
              s=p->right;
              break;
            }
            p=p->next;
          }
          r=NULL;
          while(p!=NULL)
          {
            if(p->left!=NULL)
            {
              if(r==NULL)
              {
                r=p->left;
              }else
              {
                r->next=p->left;
                r=r->next;
              }

            }
            if(p->right!=NULL)
            {
              if(r==NULL)
              {
                r=p->right;
              }else
              {
                r->next=p->right;
                r=r->next;
              }
            }
            p=p->next;
          }
          p=s;
        }
    }
};
int main()
{
  return 0;
}
