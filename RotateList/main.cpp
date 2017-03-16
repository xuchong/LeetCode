#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0)
			return head;
		int size = 0;
		ListNode *l = head;
		ListNode *last;
		while (l != NULL)
		{
			size++;
			last = l;
			l = l->next;
		}
		if (size == 0)
			return head;
		k = k%size;
		if (k == 0)
			return head;
		last->next = head;
		k = size - k;
		k--;
		l = head;
		while (k)
		{
			l = l->next;
			k--;
		}
		head = l->next;
		l->next = NULL;
		return head;
	}
};
int main()
{

	return 0;
}