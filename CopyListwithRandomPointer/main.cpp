#include<iostream>
#include<unordered_map>
using namespace std;
struct RandomListNode{
  int label;
  RandomListNode* next,*random;
  RandomListNode(int x):label(x),next(NULL),random(NULL){}
}

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
      unordered_map<RandomListNode*,RandomListNode*> dict;
      RandomListNode *clone=NULL,*p,*r;
      p=head;
      if(head==NULL)
        return clone;
      while(p!=NULL)
      {
        if(clone==NULL)
        {
          r=clone=new RandomListNode(p->label);
        }else{
          r->next=new RandomListNode(p->label);
          r=r->next;
        }
        dict[p]=r;
        p=p->next;
      }
      p=head;
      r=clone;
      while(p!=NULL)
      {
        r->random=dict[p->random];
        p=p->next;
        r=r->next;
      }
      return clone;
    }
};
int main()
{
  return 0;
}
