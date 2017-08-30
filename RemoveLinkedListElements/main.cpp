struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      ListNode* newhead=NULL,*p=head,*r=newhead;
      while(p!=NULL)
      {
        if(p->val!=val)
        {
          if(r==NULL)
          {
            newhead=r=p;
          }else
          {
            r->next=p;
            r=p;
          }
        }
        p=p->next;
      }
      if(r!=NULL)
        r->next=NULL;
      return newhead;
    }
};
