/**
 * Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode* newhead=NULL,*p=head,*q;
      while(p!=NULL)
      {
        if(newhead==NULL)
        {
          newhead=p;
          p=p->next;
          newhead->next=NULL;
        }else
        {
          q=p->next;
          p->next=newhead;
          newhead=p;
          p=q;
        }
      }
      return newhead;
    }
};
