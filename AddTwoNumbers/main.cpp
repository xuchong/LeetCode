#include<iostream>

using namespace std;


 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*p,*q,*r,*result=NULL;
		int add=0;
		int a,b;
		p=l1;
		q=l2;
		r=result;
		while(p!=NULL||q!=NULL)
		{
			ListNode* digit=(ListNode*)malloc(sizeof(ListNode));
			a=b=0;
			if(p!=NULL)
			{
				a=p->val;
				p=p->next;
			}
			if(q!=NULL)
			{
				b=q->val;
				q=q->next;
			}
			digit->val=(a+b+add)%10;
			digit->next=NULL;
			add=(a+b+add)/10;
			if(r==NULL)
			{
				r=result=digit;
			}else
			{
				r->next=digit;
				r=digit;
			}
		}
		if(add!=0)
		{
			ListNode* digit=(ListNode*)malloc(sizeof(ListNode));
			digit->val=add;
			digit->next=NULL;
			r->next=digit;
		}
		return result;
    }
};

int main()
{
	int n;
	int value;
	ListNode *a,*b,*p;
	while(true)
	{
		a=NULL;
		b=NULL;
		cin>>n;
		while(n--)
		{
			cin>>value;
			ListNode* tmp=(ListNode*)malloc(sizeof(ListNode));
			tmp->next=NULL;
			tmp->val=value;
			if(a==NULL)
			{
				a=tmp;
				p=a;
			}else{
				p->next=tmp;
				p=tmp;
			}
		}
		cin>>n;
		while(n--)
		{
			cin>>value;
			ListNode* tmp=(ListNode*)malloc(sizeof(ListNode));
			tmp->next=NULL;
			tmp->val=value;
			if(b==NULL)
			{
				b=tmp;
				p=b;
			}else{
				(p->next)=tmp;
				p=tmp;
			}
		}
		Solution s;
		ListNode* result=s.addTwoNumbers(a,b);
		while(result!=NULL)
		{
			cout<<result->val<<"->";
			result=result->next;
		}
		cout<<endl;
	}
	return 0;
}