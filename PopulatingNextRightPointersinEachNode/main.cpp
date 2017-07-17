#include<iostream>
#include<algorithm>
using namespace std;
//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
      TreeLinkNode *p,*r,*l,*s;
      p=root;
      while(p!=NULL)
      {
        //each layer
        s=p->left;
        r=NULL;
        while(p!=NULL){
          if(r==NULL)
          {
            r=p->left;
          }else{
            r->next=p->left;
            r=r->next;
          }
          if(r==NULL)
            break;
          r->next=p->right;
          r=r->next;
          p=p->next;
          if(r==NULL)
            break;
        }
        p=s;
      }
    }
};
