#include<iostream>
using namespace std;
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x),next(NULL){}
};
//merge sort by recursive
class Solution {
private:
  void recursive(ListNode* &head,int length)
  {
    if(length==1)
    {
      return;
    }
    if(length==2)
    {
      if(head->val>head->next->val)
      {
        int tmp=head->val;
        head->val=head->next->val;
        head->next->val=tmp;
      }
      return;
    }
    int left=(length+1)/2,right=length/2;
    ListNode* leftNode=head,*rightNode=NULL,*p;
    int i=0;
    while(i<left)
    {
      if(rightNode==NULL)
        rightNode=leftNode;
      else
        rightNode=rightNode->next;
      i++;
    }
    p=rightNode->next;
    rightNode=NULL;
    rightNode=p;
    recursive(leftNode,left);
    recursive(rightNode,right);
    //merge
    int start1=0,start2=0;
    head=NULL;
    while(start1<left&&start2<right)
    {
      if(leftNode->val<=rightNode->val)
      {
        if(head==NULL)
        {
          head=p=leftNode;
        }else
        {
          p->next=leftNode;
          p=p->next;
        }
        leftNode=leftNode->next;
        start1++;
      }else
      {
        if(head==NULL)
        {
          head=p=rightNode;
        }else
        {
          p->next=rightNode;
          p=p->next;
        }
        rightNode=rightNode->next;
        start2++;
      }
    }
    while(start1<left)
    {
      p->next=leftNode;
      leftNode=leftNode->next;
      p=p->next;
      start1++;
    }
    while(start2<right)
    {
      p->next=rightNode;
      rightNode=rightNode->next;
      p=p->next;
      start2++;
    }
  }
public:
    ListNode* sortList(ListNode* head) {
      if(head==NULL)
        return head;
      int length=0;
      ListNode* p=head;
      while(p!=NULL)
      {
        length++;
        p=p->next;
      }
      recursive(head,length);
      return head;
    }
};
