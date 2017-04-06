#include<iostream>
using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n)
			return head;
		int i, j;
		ListNode *start, *end=NULL, *p, *q, *r;
		//m!=1
		if (m > 1){
			start = head;
			for (i = 0; i < m - 2; i++)
			{
				start = start->next;
			}
			q = p = end = start->next;
			q = q->next;
			for (; i < n - 2; i++)
			{
				r = q->next;
				q->next = p;
				p = q;
				q = r;
			}
			start->next = p;
			end->next = q;
			return head;
		}
		else
		{
			q = p = end = start = head;
			q = q->next;
			for (i=1; i < n; i++)
			{
				r = q->next;
				q->next = p;
				p = q;
				q = r;
			}
			//start->next = p;
			end->next = q;
			return p;
		}
	}
};