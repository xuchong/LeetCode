#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* l,*p,*q,*r;
        l=p=head;
        if(head==NULL)
            return head;
        if(p->next!=NULL)
        {
            q=p->next;
            p->next=q->next;
            q->next=p;
            head=q;
        }else
        {
            return head;
        }
        l=p;
        p=p->next;
        while(p!=NULL&&p->next!=NULL)
        {
            q=p->next;
            p->next=q->next;
            q->next=p;
            l->next=q;
            l=p;
            p=p->next;
        }
        return head;
    }
};
int main() {
    Solution s;
    ListNode*input,*p,*q;
    int n;
    int val;
    while (true)
    {
        cin>>n;
        input=NULL;
        while (n--)
        {
            cin>>val;
            ListNode* item=new ListNode(val);
            if(input==NULL)
            {
                input=p=item;
            }else
            {
                p->next=item;
                p=p->next;
            }
        }
        p=s.swapPairs(input);
        while(p!=NULL)
        {
            q=p;
            cout<<p->val<<" ";
            p=p->next;
            free(q);
        }
        cout<<endl;

    }
    return 0;
}