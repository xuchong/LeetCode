#include<iostream>
#include<vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution{
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* before;
		ListNode* result = NULL, *p, *r=NULL;
		int last = head->val - 1;
		p = head;
		while (p != NULL){
			if (p->val != last){
				before = p;
				last = p->val;
				p = p->next;
				if (p == NULL || p->val != last)
				{
					if (result == NULL)
					{
						result = before;
						r = result;
					}
					else
					{
						r->next = before;
						r = before;
					}
				}
			}
			else
			{
				p = p->next;
			}
		}
		if (r != NULL)
			r->next = NULL;
		return result;
	}
};
int main()
{
	Solution s;
	ListNode* head=NULL, *item,*p=NULL;
	int n, val;
	while (true)
	{
		cin >> n;
		head = NULL;
		while (n--)
		{
			cin >> val;
			item = new ListNode(val);
			if (head == NULL)
			{
				head = item;
				p = head;
			}
			else
			{
				p->next = item;
				p = p->next;
			}
		}
		s.deleteDuplicates(head);
	}
	return 0;
}