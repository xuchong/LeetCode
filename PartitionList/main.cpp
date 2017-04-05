#include<iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL)
			return head;
		ListNode* little = NULL, *big = NULL, *lp = NULL , *bp=NULL, *p;
		p = head;
		while (p != NULL)
		{
			if (p->val < x)
			{
				if (little == NULL)
				{
					little = p;
					lp = p;
				}
				else
				{
					lp->next = p;
					lp = p;
				}
			}
			else
			{
				if (big == NULL)
				{
					big = p;
					bp = p;
				}
				else
				{
					bp->next = p;
					bp = p;
				}
			}
			p = p->next;
		}
		if (bp != NULL)
			bp->next = NULL;
		if (little != NULL)
		{
			lp->next = big;
			return little;
		}
		else
		{
			return head;
		}
	}
};
int main()
{

	return 0;
}