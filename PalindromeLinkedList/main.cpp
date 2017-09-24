/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int length=0;
        ListNode* p=head,*r,*t;
        while(p!=NULL)
        {
          length++;
          p=p->next;
        }
        int halfLenght=length/2;
        if(halfLenght==0)
        {
          return true;
        }
        p=head;
        r=NULL;
        while(halfLenght--)
        {
          t=p;
          p=p->next;
          t->next=r;
          r=t;
        }
        if(length%2)
          p=p->next;
        while(r!=NULL&&p!=NULL)
        {
          if(r->val!=p->val)
            return false;
          r=r->next;
          p=p->next;
        }
        return true;
    }
};
