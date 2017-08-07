#include<iostream>

using namespace std;
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};
class Solution {
public:
    void reorderList(ListNode* head) {
      if(head==NULL)
        return;
      ListNode*one=NULL,*two=NULL,*p,*r,*s;
      int count=0;
      p=head;
      while(p!=NULL)
      {
        count++;
        p=p->next;
      }
      //caculate one two
      int onecount=(count+1)/2;
      int twocount=(count-onecount);
      p=head;
      count=0;
      while(count<onecount)
      {
        count++;
        if(one==NULL)
        {
          one=r=p;
        }else
        {
          r->next=p;
          r=r->next;
        }
        p=p->next;
      }
      r->next=NULL;
      count=0;
      while(count<twocount)
      {
        count++;
        if(two==NULL)
        {
          two=s=p;
          p=p->next;
          s->next=NULL;
        }else
        {
          s=p;
          p=p->next;
          s->next=two;
          two=s;
        }
      }
      //merge one and two
      p=one;
      while(p!=NULL)
      {
        r=p->next;
        p->next=two;
        if(two!=NULL)
          two=two->next;
        p=p->next;
        if(p!=NULL)
          p->next=r;
        p=r;
      }
      head=one;
    }
};
int main()
{
  return 0;
}
