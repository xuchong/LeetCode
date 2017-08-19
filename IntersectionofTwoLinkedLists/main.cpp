struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode*a=headA,*b=headB;
      int alength=0,blength=0;
      while(a!=NULL)
      {
        alength++;
        a=a->next;
      }
      while(b!=NULL)
      {
        blength++;
        b=b->next;
      }
      // a is long ,b is short
      a=alength>=blength?headA:headB;
      b=alength>=blength?headB:headA;
      int diff=abs(alength-blength);
      while(diff)
      {
        a=a->next;
        diff--;
      }
      while(a!=NULL&&b!=NULL)
      {
        if(a==b)
        {
          return a;
        }
        a=a->next;
        b=b->next;
      }
      return NULL;
    }
};
