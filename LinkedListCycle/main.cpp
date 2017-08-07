#include<iostream>

using namespace std;
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(head==NULL)
        return false;
      ListNode *p,*r;
      p=r=head;
      while(p!=NULL&&r!=NULL)
      {
        p=p->next;
        if(p==NULL)
          break;
        p=p->next;
        r=r->next;
        if(p==r)
        {
          return true;
        }
      }
      return false;
    }
};
int main()
{
  return 0;
}
