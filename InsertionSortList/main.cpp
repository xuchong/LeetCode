#include<iostream>
using namespace std;
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if(head==NULL)
        return head;
      ListNode*p,*r,*s,*before,*newnode,*end;
      newnode=end=head;
      p=head->next;
      newnode->next=NULL;
      while(p!=NULL)
      {
        before=NULL;
        s=newnode;
        while(s!=NULL)
        {
          //need insert
          if(s->val>p->val)
          {
            if(before==NULL)
            {
              r=p->next;
              p->next=s;
              newnode=p;
              p=r;
            }else
            {
              before->next=p;
              r=p->next;
              p->next=s;
              p=r;
            }
            break;
          }
          before=s;
          s=s->next;
        }
        if(s==NULL){
          end->next=p;
          r=p->next;
          end=p;
          end->next=NULL;
          p=r;
        }
      }
      return newnode;
    }
};
