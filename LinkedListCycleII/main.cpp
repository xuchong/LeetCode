#include<iostream>

using namespace std;
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if(head==NULL)
      return head;
    ListNode *p,*r,*s;
    s=p=r=head;
    while(p!=NULL&&r!=NULL)
    {
      p=p->next;
      if(p==NULL)
        break;
      p=p->next;
      r=r->next;
      if(p==r)
      {
        // hasCycle
        while(s!=p)
        {
          p=p->next;
          if(p==r)
          {
            s=s->next;
          }
        }
        return p;
      }
    }
    return NULL;
  }
};
int main()
{
  return 0;
}
